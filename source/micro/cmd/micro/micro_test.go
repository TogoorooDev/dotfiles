package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"os"
	"testing"

	"github.com/go-errors/errors"
	"github.com/stretchr/testify/assert"
	"github.com/zyedidia/micro/v2/internal/action"
	"github.com/zyedidia/micro/v2/internal/buffer"
	"github.com/zyedidia/micro/v2/internal/config"
	"github.com/zyedidia/micro/v2/internal/screen"
	"github.com/zyedidia/tcell/v2"
)

var tempDir string
var sim tcell.SimulationScreen

func init() {
	screen.Events = make(chan tcell.Event, 8)
}

func startup(args []string) (tcell.SimulationScreen, error) {
	var err error

	tempDir, err = ioutil.TempDir("", "micro_test")
	if err != nil {
		return nil, err
	}
	err = config.InitConfigDir(tempDir)
	if err != nil {
		return nil, err
	}

	config.InitRuntimeFiles()
	err = config.ReadSettings()
	if err != nil {
		return nil, err
	}
	err = config.InitGlobalSettings()
	if err != nil {
		return nil, err
	}

	s, err := screen.InitSimScreen()
	if err != nil {
		return nil, err
	}

	defer func() {
		if err := recover(); err != nil {
			screen.Screen.Fini()
			fmt.Println("Micro encountered an error:", err)
			// backup all open buffers
			for _, b := range buffer.OpenBuffers {
				b.Backup()
			}
			// Print the stack trace too
			log.Fatalf(errors.Wrap(err, 2).ErrorStack())
			os.Exit(1)
		}
	}()

	err = config.LoadAllPlugins()
	if err != nil {
		screen.TermMessage(err)
	}

	action.InitBindings()
	action.InitCommands()

	err = config.InitColorscheme()
	if err != nil {
		return nil, err
	}

	b := LoadInput(args)

	if len(b) == 0 {
		return nil, errors.New("No buffers opened")
	}

	action.InitTabs(b)
	action.InitGlobals()

	err = config.RunPluginFn("init")
	if err != nil {
		return nil, err
	}

	s.InjectResize()
	handleEvent()

	return s, nil
}

func cleanup() {
	os.RemoveAll(tempDir)
}

func handleEvent() {
	screen.Lock()
	e := screen.Screen.PollEvent()
	screen.Unlock()
	if e != nil {
		screen.Events <- e
	}
	DoEvent()
}

func injectKey(key tcell.Key, r rune, mod tcell.ModMask) {
	sim.InjectKey(key, r, mod)
	handleEvent()
}

func injectMouse(x, y int, buttons tcell.ButtonMask, mod tcell.ModMask) {
	sim.InjectMouse(x, y, buttons, mod)
	handleEvent()
}

func injectString(str string) {
	// the tcell simulation screen event channel can only handle
	// 10 events at once, so we need to divide up the key events
	// into chunks of 10 and handle the 10 events before sending
	// another chunk of events
	iters := len(str) / 10
	extra := len(str) % 10

	for i := 0; i < iters; i++ {
		s := i * 10
		e := i*10 + 10
		sim.InjectKeyBytes([]byte(str[s:e]))
		for i := 0; i < 10; i++ {
			handleEvent()
		}
	}

	sim.InjectKeyBytes([]byte(str[len(str)-extra:]))
	for i := 0; i < extra; i++ {
		handleEvent()
	}
}

func openFile(file string) {
	injectKey(tcell.KeyCtrlE, rune(tcell.KeyCtrlE), tcell.ModCtrl)
	injectString(fmt.Sprintf("open %s", file))
	injectKey(tcell.KeyEnter, rune(tcell.KeyEnter), tcell.ModNone)
}

func createTestFile(name string, content string) (string, error) {
	testf, err := ioutil.TempFile("", name)
	if err != nil {
		return "", err
	}

	if _, err := testf.Write([]byte(content)); err != nil {
		return "", err
	}
	if err := testf.Close(); err != nil {
		return "", err
	}

	return testf.Name(), nil
}

func TestMain(m *testing.M) {
	var err error
	sim, err = startup([]string{})
	if err != nil {
		log.Fatalln(err)
		os.Exit(1)
	}

	retval := m.Run()
	cleanup()

	os.Exit(retval)
}

func TestSimpleEdit(t *testing.T) {
	file, err := createTestFile("micro_simple_edit_test", "base content")
	if err != nil {
		t.Error(err)
		return
	}
	defer os.Remove(file)

	openFile(file)

	var buf *buffer.Buffer
	for _, b := range buffer.OpenBuffers {
		if b.Path == file {
			buf = b
		}
	}

	if buf == nil {
		t.Errorf("Could not find buffer %s", file)
		return
	}

	injectKey(tcell.KeyEnter, rune(tcell.KeyEnter), tcell.ModNone)
	injectKey(tcell.KeyUp, 0, tcell.ModNone)
	injectString("first line")

	// test both kinds of backspace
	for i := 0; i < len("ne"); i++ {
		injectKey(tcell.KeyBackspace, rune(tcell.KeyBackspace), tcell.ModNone)
	}
	for i := 0; i < len(" li"); i++ {
		injectKey(tcell.KeyBackspace2, rune(tcell.KeyBackspace2), tcell.ModNone)
	}
	injectString("foobar")

	injectKey(tcell.KeyCtrlS, rune(tcell.KeyCtrlS), tcell.ModCtrl)

	data, err := ioutil.ReadFile(file)
	if err != nil {
		t.Error(err)
		return
	}

	assert.Equal(t, "firstfoobar\nbase content\n", string(data))
}

func TestMouse(t *testing.T) {
	file, err := createTestFile("micro_mouse_test", "base content")
	if err != nil {
		t.Error(err)
		return
	}
	defer os.Remove(file)

	openFile(file)

	// buffer:
	// base content
	// the selections need to happen at different locations to avoid a double click
	injectMouse(3, 0, tcell.Button1, tcell.ModNone)
	injectKey(tcell.KeyLeft, 0, tcell.ModNone)
	injectMouse(0, 0, tcell.ButtonNone, tcell.ModNone)
	injectString("secondline")
	// buffer:
	// secondlinebase content
	injectKey(tcell.KeyEnter, rune(tcell.KeyEnter), tcell.ModNone)
	// buffer:
	// secondline
	// base content
	injectMouse(2, 0, tcell.Button1, tcell.ModNone)
	injectMouse(0, 0, tcell.ButtonNone, tcell.ModNone)
	injectKey(tcell.KeyEnter, rune(tcell.KeyEnter), tcell.ModNone)
	// buffer:
	//
	// secondline
	// base content
	injectKey(tcell.KeyUp, 0, tcell.ModNone)
	injectString("firstline")
	// buffer:
	// firstline
	// secondline
	// base content
	injectKey(tcell.KeyCtrlS, rune(tcell.KeyCtrlS), tcell.ModCtrl)

	data, err := ioutil.ReadFile(file)
	if err != nil {
		t.Error(err)
		return
	}

	assert.Equal(t, "firstline\nsecondline\nbase content\n", string(data))
}

var srTestStart = `foo
foo
foofoofoo
Ernleȝe foo æðelen
`
var srTest2 = `test_string
test_string
test_stringtest_stringtest_string
Ernleȝe test_string æðelen
`
var srTest3 = `test_foo
test_string
test_footest_stringtest_foo
Ernleȝe test_string æðelen
`

func TestSearchAndReplace(t *testing.T) {
	file, err := createTestFile("micro_search_replace_test", srTestStart)
	if err != nil {
		t.Error(err)
		return
	}
	defer os.Remove(file)

	openFile(file)

	injectKey(tcell.KeyCtrlE, rune(tcell.KeyCtrlE), tcell.ModCtrl)
	injectString(fmt.Sprintf("replaceall %s %s", "foo", "test_string"))
	injectKey(tcell.KeyEnter, rune(tcell.KeyEnter), tcell.ModNone)

	injectKey(tcell.KeyCtrlS, rune(tcell.KeyCtrlS), tcell.ModCtrl)

	data, err := ioutil.ReadFile(file)
	if err != nil {
		t.Error(err)
		return
	}

	assert.Equal(t, srTest2, string(data))

	injectKey(tcell.KeyCtrlE, rune(tcell.KeyCtrlE), tcell.ModCtrl)
	injectString(fmt.Sprintf("replace %s %s", "string", "foo"))
	injectKey(tcell.KeyEnter, rune(tcell.KeyEnter), tcell.ModNone)
	injectString("ynyny")
	injectKey(tcell.KeyEscape, 0, tcell.ModNone)

	injectKey(tcell.KeyCtrlS, rune(tcell.KeyCtrlS), tcell.ModCtrl)

	data, err = ioutil.ReadFile(file)
	if err != nil {
		t.Error(err)
		return
	}

	assert.Equal(t, srTest3, string(data))
}

func TestMultiCursor(t *testing.T) {
	// TODO
}

func TestSettingsPersistence(t *testing.T) {
	// TODO
}

// more tests (rendering, tabs, plugins)?
