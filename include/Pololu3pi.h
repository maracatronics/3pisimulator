#pragma once

#include <Simulator.h>

#define PROGMEM

#define IR_EMITTERS_OFF 0
#define IR_EMITTERS_ON 1
#define IR_EMITTERS_ON_AND_OFF 2

#define HIGH 1
#define LOW 0

class Pololu3pi {

public:
	
	static int sensors[5];

	void calibrateLineSensors(unsigned char readMode = IR_EMITTERS_ON) {
		// TODO
	}
	
	static unsigned char Pololu3pi::init(unsigned int line_sensor_timeout = 1000, unsigned char disable_emitter_pin = 0) {
		// TODO
		return 0;
	}

	unsigned int readLine(unsigned int *sensor_values, unsigned char readMode = IR_EMITTERS_ON, unsigned char white_line = 0) {
		int result = 0;
		int denominator = 0;
		for (int i = 0; i < 5; i++) {
			sensor_values[i] = sensors[i];
			if (Pololu3pi::sensors[i] != 0) {
				result += i * 1000;
				denominator += 1;
			}
		}
		if (denominator != 0) {
			result /= denominator;
		}
		
		return result;
	}



};

/*
	na funcao readLine(), para que servem os dois ultimos parametros?
*/