#pragma once
#include"Time.h"

// record the time
class Marker :public Time {
public:
	// set the marker
	Marker(const int hour, const int min, const int day) : Time() {
		this->setHour(hour);
		this->setMin(min);
		this->setDay(day);
	}

	// copy constructor
	Marker(const Marker& a) {
		this->day = a.getDay();
		this->hr = a.getHour();
		this->min = a.getMin();
	}

	// setter
	void setHour(int hour) {
		this->hr = hour%24;
	}

	void setMin(int min) {
		if (min % 60 >= 15 && min % 60 <45) {
			this->min = 30;
		}
		else {
			this->min = 0;
		}
	}

	void setDay(int day) {
		this->day = day%7;
	}

private:
};