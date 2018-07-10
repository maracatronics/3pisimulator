/*
	2 motors declared
	1 method: setSpeeds
*/

#pragma once

#include <stdio.h>

class OrangutanMotors {

public:

	static float vright;
	static float vleft;

	static void OrangutanMotors::setSpeeds(int m1Speed, int m2Speed) {
		OrangutanMotors::vleft = -m1Speed; // negative?
		OrangutanMotors::vright = -m2Speed;

		//printf("setou velocidades: %d %d\n", m1Speed, m2Speed);
		//Sleep(1000);
	}

};