#pragma once
#include <stdio.h>

class OrangutanLEDs {

public:
	static int leftLED;
	static int rightLED;
	static void OrangutanLEDs::left(unsigned char state) {
		leftLED = state;
	}

	static void OrangutanLEDs::right(unsigned char state) {
		rightLED = state;
	}

};