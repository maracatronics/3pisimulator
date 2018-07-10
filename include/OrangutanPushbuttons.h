#pragma once

#define TOP_BUTTON		(1 << 2) // #define TOP_BUTTON		(1 << PORTB5)
#define MIDDLE_BUTTON	(1 << 1) // #define MIDDLE_BUTTON	(1 << PORTB4)
#define BOTTOM_BUTTON	(1 << 0) // #define BOTTOM_BUTTON	(1 << PORTB1)

#define BUTTON_C		TOP_BUTTON
#define BUTTON_B		MIDDLE_BUTTON
#define BUTTON_A		BOTTOM_BUTTON

class OrangutanPushbuttons {

public:

	static int buttonAState;
	static int buttonBState;
	static int buttonCState;

	static unsigned char OrangutanPushbuttons::isPressed(unsigned char buttons) {
		
		switch (buttons) {
			case BUTTON_A: {
				if (buttonAState == 1) {
					buttonAState = 0;
					return 1;
				}
			}
			case BUTTON_B: {
				if (buttonBState == 1) {
					buttonBState = 0;
					return 1;
				}
			}
			case BUTTON_C: {
				if (buttonCState == 1) {
					buttonCState = 0;
					return 1;
				}
			}
			default: return 0;
		}

		return true;
	}

	static unsigned char OrangutanPushbuttons::waitForRelease(unsigned char buttons) {
		// TODO
		return 0;
	}
	/*
	void press(char button) {
		switch (button) {
		case 'a':
			buttonAState = 1;
			break;
		case 'b':
			buttonBState = 1;
			break;
		case 'c':
			buttonCState = 1;
			break;
		default:
			break;
		}
	}

	void release(char button) {
		switch (button) {
		case 'a':
			buttonAState = 0;
			break;
		case 'b':
			buttonBState = 0;
			break;
		case 'c':
			buttonCState = 0;
			break;
		default:
			break;
		}
	}
	*/
};