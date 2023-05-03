#include <iostream>
#include "Time.h"
#include "Customer.h"
#include "Room.h"


class Reservation {

private:
	unsigned int _id;
	Customer _customer;
	Room _room;
	Time _startDate;
	Time _endDate;
	
	void copy(const Reservation& other) {
		if (this!=&other)
		{
			this->_id = other._id;
			this->_customer = other._customer;
			this->_room = other._room;
			this->_startDate = other._startDate;
			this->_endDate = other._endDate;

		}
	}


public:

	Reservation() {
		_id = 0;
	}
	Reservation(const Reservation& other) {
		copy(other);
	}
	//TODO
	const unsigned int getRoomNumber() const {
		return _room.getRoomNumber();
	}
	const unsigned int getID() const {
		return _id;
	}
	const Time getEndDate() const {
		return _endDate;
	}
	const unsigned int getRoomPrice() const {
		return _room.getPriceForANight();
	}
	const char* getCustomerName() const {
		return _customer.getName();
	}

	bool operator==(const Reservation& other) {
		return _id == other._id || this == &other ? true : false;
	}
	friend std::ostream& operator<<(std::ostream& os, const Reservation& obj) {
		os << "ID: " << obj._id << std::endl;
		os << "Room: " << obj._room.getRoomNumber() << ", " << obj._room.getRoomType() << std::endl;
		os << "Customer: " << obj._customer.getName() << ", " << obj._customer.getTelephoneNumber() << obj._customer.getAddress() << std::endl;
		os << "Start: " << obj._startDate << std::endl;
		os << "End: " << obj._endDate << std::endl;
	}

	int priceForReservation() {
		return Time::daysBetweenDates(_startDate, _endDate) * _room.getPriceForANight();
	}
	bool isTheRoomFreeForThePeriod(const Time& start, const Time& end) {
		if (end < _startDate || this->_endDate < start)
		{	//	TODO	
			return false;
		}
		return true;
	}


};