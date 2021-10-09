//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"Mem: ", "echo $(/home/hens/.config/polybar/mem_calculator.sh percentage)%",	30,		0},

	{"Bat: ", "echo `sysctl hw.acpi.battery.life | cut -d' ' -f 2`%", 60, 0 },	

	{"", "date '+%I:%M %p'",					5,		0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
