// gomuks - A terminal Matrix client written in Go.
// Copyright (C) 2020 Tulir Asokan
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

package messages

import (
	"bytes"
	"fmt"
	"image"
	"image/color"

	"maunium.net/go/mautrix/crypto/attachment"
	"maunium.net/go/mautrix/event"
	"maunium.net/go/mautrix/id"
	"maunium.net/go/mauview"
	"maunium.net/go/tcell"

	"maunium.net/go/gomuks/config"
	"maunium.net/go/gomuks/debug"
	"maunium.net/go/gomuks/interface"
	"maunium.net/go/gomuks/lib/ansimage"
	"maunium.net/go/gomuks/matrix/muksevt"
	"maunium.net/go/gomuks/ui/messages/tstring"
)

type FileMessage struct {
	Type event.MessageType
	Body string

	URL           id.ContentURI
	File          *attachment.EncryptedFile
	Thumbnail     id.ContentURI
	ThumbnailFile *attachment.EncryptedFile

	imageData []byte
	buffer    []tstring.TString

	matrix ifc.MatrixContainer
}

// NewFileMessage creates a new FileMessage object with the provided values and the default state.
func NewFileMessage(matrix ifc.MatrixContainer, evt *muksevt.Event, displayname string) *UIMessage {
	content := evt.Content.AsMessage()
	var file, thumbnailFile *attachment.EncryptedFile
	if content.File != nil {
		file = &content.File.EncryptedFile
		content.URL = content.File.URL
	}
	if content.GetInfo().ThumbnailFile != nil {
		thumbnailFile = &content.Info.ThumbnailFile.EncryptedFile
		content.Info.ThumbnailURL = content.Info.ThumbnailFile.URL
	}
	return newUIMessage(evt, displayname, &FileMessage{
		Type:          content.MsgType,
		Body:          content.Body,
		URL:           content.URL.ParseOrIgnore(),
		File:          file,
		Thumbnail:     content.GetInfo().ThumbnailURL.ParseOrIgnore(),
		ThumbnailFile: thumbnailFile,
		matrix:        matrix,
	})
}

func (msg *FileMessage) Clone() MessageRenderer {
	data := make([]byte, len(msg.imageData))
	copy(data, msg.imageData)
	return &FileMessage{
		Body:      msg.Body,
		URL:       msg.URL,
		Thumbnail: msg.Thumbnail,
		imageData: data,
		matrix:    msg.matrix,
	}
}

func (msg *FileMessage) NotificationContent() string {
	switch msg.Type {
	case event.MsgImage:
		return "Sent an image"
	case event.MsgAudio:
		return "Sent an audio file"
	case event.MsgVideo:
		return "Sent a video"
	case event.MsgFile:
		fallthrough
	default:
		return "Sent a file"
	}
}

func (msg *FileMessage) PlainText() string {
	return fmt.Sprintf("%s: %s", msg.Body, msg.matrix.GetDownloadURL(msg.URL))
}

func (msg *FileMessage) String() string {
	return fmt.Sprintf(`&messages.FileMessage{Body="%s", URL="%s", Thumbnail="%s"}`, msg.Body, msg.URL, msg.Thumbnail)
}

func (msg *FileMessage) DownloadPreview() {
	var url id.ContentURI
	var file *attachment.EncryptedFile
	if !msg.Thumbnail.IsEmpty() {
		url = msg.Thumbnail
		file = msg.ThumbnailFile
	} else if msg.Type == event.MsgImage && !msg.URL.IsEmpty() {
		msg.Thumbnail = msg.URL
		url = msg.URL
		file = msg.File
	} else {
		return
	}
	debug.Print("Loading file:", url)
	data, err := msg.matrix.Download(url, file)
	if err != nil {
		debug.Printf("Failed to download file %s: %v", url, err)
		return
	}
	debug.Print("File", url, "loaded.")
	msg.imageData = data
}

func (msg *FileMessage) ThumbnailPath() string {
	return msg.matrix.GetCachePath(msg.Thumbnail)
}

func (msg *FileMessage) CalculateBuffer(prefs config.UserPreferences, width int, uiMsg *UIMessage) {
	if width < 2 {
		return
	}

	if prefs.BareMessageView || prefs.DisableImages || len(msg.imageData) == 0 {
		msg.buffer = calculateBufferWithText(prefs, tstring.NewTString(msg.PlainText()), width, uiMsg)
		return
	}

	img, _, err := image.DecodeConfig(bytes.NewReader(msg.imageData))
	if err != nil {
		debug.Print("File could not be decoded:", err)
	}
	imgWidth := img.Width
	if img.Width > width {
		imgWidth = width / 3
	}

	ansFile, err := ansimage.NewScaledFromReader(bytes.NewReader(msg.imageData), 0, imgWidth, color.Black)
	if err != nil {
		msg.buffer = []tstring.TString{tstring.NewColorTString("Failed to display image", tcell.ColorRed)}
		debug.Print("Failed to display image:", err)
		return
	}

	msg.buffer = ansFile.Render()
}

func (msg *FileMessage) Height() int {
	return len(msg.buffer)
}

func (msg *FileMessage) Draw(screen mauview.Screen) {
	for y, line := range msg.buffer {
		line.Draw(screen, 0, y)
	}
}
