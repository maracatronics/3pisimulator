/*
* Simple3piLineFollower - demo code for the Pololu 3pi Robot
*
* This code will follow a black line on a white background, using a
* very simple algorithm.  It demonstrates auto-calibration and use of
* the 3pi IR sensors, motor control, bar graphs using custom
* characters, and music playback, making it a good starting point for
* developing your own more competitive line follower.
*
* http://www.pololu.com/docs/0J21
* http://www.pololu.com
* http://forum.pololu.com
*
*/

// The 3pi include file must be at the beginning of any program that
// uses the Pololu AVR library and 3pi.  Pololu3pi.h includes all of the
// other Orangutan Arduino libraries that can be used to control the
// on-board hardware such as LCD, buzzer, and motor drivers.
#include <Pololu3pi.h>
#include <PololuQTRSensors.h>
#include <OrangutanMotors.h>
#include <OrangutanAnalog.h>
#include <OrangutanLEDs.h>
#include <OrangutanLCD.h>
#include <OrangutanPushbuttons.h>
#include <OrangutanBuzzer.h>

#define VEL 100
Pololu3pi robot;

unsigned int sensors[5]; // an array to hold sensor values

						 // This include file allows data to be stored in program space.  The
						 // ATmega168 has 16k of program space compared to 1k of RAM, so large
						 // pieces of static data should be stored in program space.
#include <avr/pgmspace.h>

						 // Introductory messages.  The "PROGMEM" identifier causes the data to
						 // go into program space.
const char welcome_line1[] PROGMEM = " Pololu";
const char welcome_line2[] PROGMEM = "3\xf7 Robot";
const char demo_name_line1[] PROGMEM = "Line";
const char demo_name_line2[] PROGMEM = "follower";

// A couple of simple tunes, stored in program space.
const char welcome[] PROGMEM = ">g32>>c32";
const char go[] PROGMEM = "L16 cdegreg4";

// Data for generating the characters used in load_custom_characters
// and display_readings.  By reading levels[] starting at various
// offsets, we can generate all of the 7 extra characters needed for a
// bargraph.  This is also stored in program space.
const char levels[] PROGMEM = {
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111
};

// This function loads custom characters into the LCD.  Up to 8
// characters can be loaded; we use them for 7 levels of a bar graph.
void load_custom_characters()
{
	OrangutanLCD::loadCustomCharacter(levels + 0, 0); // no offset, e.g. one bar
	OrangutanLCD::loadCustomCharacter(levels + 1, 1); // two bars
	OrangutanLCD::loadCustomCharacter(levels + 2, 2); // etc...
	OrangutanLCD::loadCustomCharacter(levels + 3, 3);
	OrangutanLCD::loadCustomCharacter(levels + 4, 4);
	OrangutanLCD::loadCustomCharacter(levels + 5, 5);
	OrangutanLCD::loadCustomCharacter(levels + 6, 6);
	OrangutanLCD::clear(); // the LCD must be cleared for the characters to take effect
}

// This function displays the sensor readings using a bar graph.
void display_readings(const unsigned int *calibrated_values)
{
	unsigned char i;

	for (i = 0; i<5; i++) {
		// Initialize the array of characters that we will use for the
		// graph.  Using the space, an extra copy of the one-bar
		// character, and character 255 (a full black box), we get 10
		// characters in the array.
		const char display_characters[10] = { ' ', 0, 0, 1, 2, 3, 4, 5, 6, 255 };

		// The variable c will have values from 0 to 9, since
		// calibrated values are in the range of 0 to 1000, and
		// 1000/101 is 9 with integer math.
		char c = display_characters[calibrated_values[i] / 101];

		// Display the bar graph character.
		OrangutanLCD::print(c);
	}
}

void setup()
{
	OrangutanLEDs::left(HIGH);
	OrangutanLEDs::right(LOW);
	delay(3000);
	OrangutanLEDs::left(LOW);
	OrangutanLEDs::right(HIGH);
	delay(3000);
}

void loop()
{
	// Get the position of the line.  Note that we *must* provide
	// the "sensors" argument to read_line() here, even though we
	// are not interested in the individual sensor readings.
	unsigned int position = robot.readLine(sensors, IR_EMITTERS_ON);

	if (position < 1000) // 0 - 999
	{
		OrangutanMotors::setSpeeds(0, VEL);

		OrangutanLEDs::left(HIGH);
		OrangutanLEDs::right(LOW);
	}
	else if (position < 3000) // 1000 - 2999
	{
		// We are somewhat close to being centered on the line:
		// drive straight.
		OrangutanMotors::setSpeeds(VEL, VEL);
		OrangutanLEDs::left(HIGH);
		OrangutanLEDs::right(HIGH);
	}
	else // 3000 - 
	{
		// We are far to the left of the line: turn right.
		OrangutanMotors::setSpeeds(VEL, 0);
		//OrangutanMotors::setSpeeds(0, VEL);
		OrangutanLEDs::left(LOW);
		OrangutanLEDs::right(HIGH);
	}
}
