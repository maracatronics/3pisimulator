#include <time.h>
#include <math.h>

class Timer {
private:
	bool counting;
	bool stopped;
	double beg;
	int init;
	int end;
	int milliseconds;
	int seconds;
	int minutes;
	int time;

public:
	Timer();
	void startCount();
	void stopCount();
	void resetCount();
	double getTime();
	int getMilliSecs();
	int getSecs();
	int getMin();
};

Timer::Timer() {
	milliseconds = 0;
	seconds = 0;
	minutes = 0;
	time = 0;

	counting = false;
	beg = 0;
}

void Timer::startCount() {
	counting = true;
	if (stopped) {
		end = getTime();
		beg += end - init;
	}
	else {
		beg = getTime();
		stopped = false;
	}
}

void Timer::stopCount() {
	counting = false;
	stopped = true;
	init = getTime();
}

void Timer::resetCount() {
	beg = clock();
}

double Timer::getTime() {
	return double(clock()) / CLOCKS_PER_SEC * 1000 - beg;
}

int Timer::getMin() {

	if (counting) {
		minutes = getSecs() / 60;
	}
	return minutes;
}

int Timer::getSecs() {
	if (counting)
		seconds = getMilliSecs() / 1000;

	return seconds;
}

int Timer::getMilliSecs() {
	if (counting)
		milliseconds = floor(double(clock()) / CLOCKS_PER_SEC * 1000 - beg);

	return milliseconds;
}