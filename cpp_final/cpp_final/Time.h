#pragma once
#include<iostream>
#include<ctime>
using namespace std;

class Time {
public:
	// constructor
	Time() {
		// record current time
		reset();
#ifdef  DEBUG
		cout << "Time constructor" << endl;
		cout << now.tm_year + 1900 << ". " << now.tm_mon + 1 << ". " << now.tm_mday << " " << now.tm_wday << " 요일" << endl;
		cout << now.tm_hour << ": " << now.tm_min << endl;
#endif //  DEBUG	
	}
	
	// reset current time at this point of time
	void reset() {
		time_t temp = time(NULL);
		tm now;
		localtime_s(&now, &temp);

		// store the current time
		this->year = now.tm_year;
		this->mon = now.tm_mon;
		this->date = now.tm_mday;
		this->day = now.tm_wday;
		this->hr = now.tm_hour;
		this->min = now.tm_min;
	}

	// return current year
	int getYear() const{
		return this->year;
	}

	// return current month
	int getMonth() const{
		return this->mon;
	}

	// return current month date
	int getDate() const{
		return this->date;
	}

	// return current day
	int getDay() const{
		return this->day;
	}

	// return current hour
	int getHour() const{
		return this->hr;
	}

	// return current minutes
	int getMin() const{
		return this->min;
	}

protected:
	int day;	// 요일 (0 : sun, 1 : mon, 2 : tue, 3 : wed, 4 : thu, 5 : fri, 6 : sat)
	int hr;		// 시간
	int min;	// 분

private:
	int year;	// 년
	int mon;	// 월
	int date;	// 월일
};