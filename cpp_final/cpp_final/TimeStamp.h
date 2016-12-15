#pragma once
#include<iostream>
#include<string>
#include"Marker.h"

// record time of a work
class timeStamp {
public:
	// constructor
	timeStamp(const Marker& begin, const Marker& end, string name) {
		// initiate the time of a work
		this->begin = new Marker(begin);
		this->end = new Marker(end);
		this->workName = name;

		// get the duration
		try {
			this->calDuration();
		}
		catch (string e) {
			cout << e << endl;
			exit(0);
		}
	}

	timeStamp(int beginHour, int beginMin,  int endHour, int endMin, int day, string name) {
		// initate the time of a work
		this->begin = new Marker(beginHour, beginMin, day);
		this->end = new Marker(endHour, endMin, day);
		this->workName = name;

		// get the duraiton of a work
		try {
			this->calDuration();
		}
		catch (string e) {
			cout << e << endl;
			exit(0);
		}
	}

	timeStamp(const timeStamp& temp) {
		this->begin = new Marker(temp.getBeginHour(), temp.getBeginMin(), temp.getDay());
		this->end = new Marker(temp.getEndHour(), temp.getEndMin(), temp.getDay());
		this->workName = temp.getName();
		this->calDuration();
	}

	// destructor
	~timeStamp() {
		delete this->duration;
		delete this->begin;
		delete this->end;
	}

	// check if the time of this work conflicts with the time of other work
	bool isConflict(timeStamp& other) {
		timeStamp temp= other;

		if (this->begin->getHour() <= temp.getBeginHour() && this->end->getHour() >= temp.getBeginHour()) {
			return true;
		}

		if (this->begin->getHour() <= temp.getEndHour() && this->end->getHour() >= temp.getEndHour()) {
			return true;
		}

		if (this->begin->getHour()<= temp.getBeginHour() && this->end->getHour() >= temp.getEndHour()) {
			return true;
		}

		if (this->begin->getHour() >= temp.getBeginHour() && this->end ->getHour() <= temp.getEndHour()) {
			return true;
		}

		return false;
	}
	
	// getter
	int getBeginHour() const{
		return this->begin->getHour();
	}

	int getEndHour() const {
		return this->end->getHour();
	}

	int getBeginMin() const {
		return this->begin->getMin();
	}

	int getEndMin() const {
		return this->end->getMin();
	}
	
	int getDay() const {
		return this->begin->getDay();
	}

	string getName() const {
		return this->workName;
	}

	// setter
	void setBegin(const Marker& begin) {
		*(this->begin) = begin;
		this->calDuration();
	}

	void setBegin(int hour, int min, int day) {
		this->begin->setHour(hour);
		this->begin->setMin(min);
		this->begin->setDay(day);
		this->calDuration();
	}

	void setEnd(const Marker& end) {
		*(this->end) = end;
		this->calDuration();
	}

	void setEnd(int hour, int min, int day) {
		this->end->setHour(hour);
		this->end->setMin(min);
		this->end->setDay(day);
		this->calDuration();
	}

	void setName(string name) {
		this->workName = name;
	}

	// operator overloading
	timeStamp& operator=(timeStamp& temp) {
		this->begin = new Marker(temp.getBeginHour(),temp.getBeginMin(),temp.getDay());
		this->end = new Marker(temp.getEndHour(), temp.getEndMin(), temp.getDay());
		this->calDuration();
	}
private: 
	// calculate the duration of a work
	void calDuration() {
		// get the duration
		if (this->end->getMin() < this->begin->getMin() && this->end->getHour() > this->begin->getHour()) {
			this->duration[0] = this->end->getHour() - this->begin->getHour() - 1;	// duration hour
			this->duration[1] = 30;													// duration minute	
		}
		else {
			throw string("Ending time is earlier than the beginnig time");
		}
	}

	Marker* begin;		// beginning time of a work
	Marker* end;		// ending time of a work
	string workName;	// name of work
	int duration[2];	// duration time of a work
};