#pragma once

class OrangutanLCD {

public:

	static char ascii[256][8];

	static int x;
	static int y;

	static int offsetx;
	static int offsety;

	static char content[2][8];

	static void OrangutanLCD::clear() {
		// TODO
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 8; j++) {
				content[i][j] = 0;
			}
		}
	}

	static void OrangutanLCD::gotoXY(unsigned char x, unsigned char y) {
		OrangutanLCD::x = x;
		OrangutanLCD::y = y;

	}

	static void OrangutanLCD::loadCustomCharacter(const char *picture_ptr, unsigned char number) {
		// TODO
	}

	static void OrangutanLCD::print(int value) {
		char number[20];
		sprintf(number, "%d", value);
		print(number);
	}

	static void OrangutanLCD::print(unsigned int value) {
		char number[20];
		sprintf(number, "%u", value);
		print(number);
	}

	static void OrangutanLCD::print(unsigned char character) {
		// TODO

	}

	static void OrangutanLCD::print(char character) {
		int address = y * 8 + x;
		if (address < 16) {
			content[OrangutanLCD::y][OrangutanLCD::x] = character;
			address++;
			y = address / 8;
			x = address % 8;
		}

	}

	static void OrangutanLCD::printFromProgramSpace(const char *str) {
		// TODO
	}

	static void OrangutanLCD::print(const char *str) {
		int index = 0;
		int address;
		while (str[index]) {
			address = y * 8 + x;
			if (address < 16) {
				content[y][x] = str[index++];
				address++;
				y = address / 8;
				x = address % 8;
			}
			else break;
		}
	}

};