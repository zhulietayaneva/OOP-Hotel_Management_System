#pragma once
#include <iostream>
#include <ctime>

class Time {

private:

	unsigned int _year;
	unsigned int _month;
	unsigned int _day;
	unsigned int _hour;
	unsigned int _minute;
	unsigned int _second;

	int daysInMonth(int m, int y);
	bool isLeapYear(const int year);
	static tm to_tm(const Time& obj);

public:

	Time();
	Time(unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int minute, unsigned int second);


	const unsigned int getYear() const;
	const unsigned int getMonth() const;
	const unsigned int getDay() const;
	const unsigned int getHour() const;
	const unsigned int getMinute() const;
	const unsigned int getSecond() const;


	static int daysBetweenDates(const Time& date1, const Time& date2);

	Time operator-(const Time& other);
	const bool operator<(const Time& t2) const;
	bool operator==(const Time& other) const;
	friend std::ostream& operator<<(std::ostream& os, const Time& obj);

};