#pragma once

#include <stdio.h>

class OrangutanMotors {

public:

	static float vright;
	static float vleft;

	static void OrangutanMotors::setSpeeds(int m1Speed, int m2Speed) {
		OrangutanMotors::vleft = -m1Speed;
		OrangutanMotors::vright = -m2Speed;
	}

};