#include <iostream>
#include <ctime>
#include "Time.h"


	int Time::daysInMonth(int m, int y)
	{
		if (m == 2) {
			if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) { return 29; }
			else { return 28; }
		}

		else if (m == 4 || m == 6 || m == 9 || m == 11) {
			return 30;
		}
		return 31;
	}
	bool Time::isLeapYear(const int year) {
		if (year % 400 == 0) {
			return true;
		}
		else if (year % 100 == 0) {
			return false;
		}
		else if (year % 4 == 0) {
			return true;
		}
		return false;
	}
	tm Time::to_tm(const Time& obj) {
		tm timeinfo = {};
		timeinfo.tm_year = obj.getYear() - 1900;
		timeinfo.tm_mon = obj.getMonth() - 1;
		timeinfo.tm_mday = obj.getDay();
		timeinfo.tm_hour = obj.getHour();
		timeinfo.tm_min = obj.getMinute();
		timeinfo.tm_sec = obj.getSecond();
		timeinfo.tm_isdst = -1;
		return timeinfo;
	}

	const unsigned int Time::getYear() const {
		return this->_year;
	}

	const unsigned int Time::getMonth() const {
		return _month;
	}

	const unsigned int Time::getDay() const {
		return _day;
	}

	const unsigned int Time::getHour() const {
		return _hour;
	}

	const unsigned int Time::getMinute() const {
		return _minute;
	}

	const unsigned int Time::getSecond() const {
		return _second;
	}

	Time::Time() {
		_year = 0;
		_month = 0;
		_day = 0;
		_hour = 0;
		_minute = 0;
		_second = 0;
	}
	Time::Time(unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int minute, unsigned int second)
	{
		_year = year;
		_month = month;
		_day = day;
		_hour = hour;
		_minute = minute;
		_second = second;
	}

	int Time::daysBetweenDates(const Time& date1, const Time& date2) {

		tm d1 = Time::to_tm(date1);
		tm d2 = Time::to_tm(date2);


		time_t time1 = mktime(&d1);
		time_t time2 = mktime(&d2);

		time_t diffSeconds = difftime(time2, time1);
		int diffDays = round(diffSeconds / (24.0 * 3600.0));

		return diffDays;
	}

	Time Time::operator-(const Time& other)
	{
		int year = this->_year - other.getYear();
		int month = this->_month - other.getMonth();
		int day = this->_day - other.getDay();
		int hour = this->_hour - other.getHour();
		int min = this->_minute - other.getMinute();
		int sec = this->_second - other.getSecond();

		if (sec < 0) {
			sec += 60;
			min--;
		}
		if (min < 0) {
			min += 60;
			hour--;
		}
		if (hour < 0) {
			hour += 24;
			day--;
		}
		if (day < 0) {
			month--;
			if (month < 0) {
				month += 12;
				year--;
			}
			day += daysInMonth(month, year);
		}
		if (month < 0) {
			month += 12;
			year--;
		}

		return Time(year, month, day, hour, min, sec);

	}
	const bool Time::operator<(const Time& t2) const {
		if (this->_year < t2._year) {
			return true;
		}
		else if (this->_year > t2._year) {
			return false;
		}
		else {
			if (this->_month < t2._month) {
				return true;
			}
			else if (this->_month > t2._month) {
				return false;
			}
			else {
				if (this->_day < t2._day) {
					return true;
				}
				else if (this->_day > t2._day) {
					return false;
				}
				else {
					if (this->_hour < t2._hour) {
						return true;
					}
					else if (this->_hour > t2._hour) {
						return false;
					}
					else {
						if (this->_minute < t2._minute) {
							return true;
						}
						else if (this->_minute > t2._minute) {
							return false;
						}
						else {
							if (this->_second < t2._second) {
								return true;
							}
							else {
								return false;
							}
						}
					}
				}
			}
		}
	}
	bool Time::operator==(const Time& other) const {
		return _year == other._year &&
			_month == other._month &&
			_day == other._day &&
			_hour == other._hour &&
			_minute == other._minute &&
			_second == other._second;
	}
	std::ostream& operator<<(std::ostream& os, const Time& obj) {
		os << obj._year << '-' << obj._month << '-' << obj._day << ' ' << obj._hour << ':' << obj._minute << ':' << obj._second;
		return os;
	}
