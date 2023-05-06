#include <iostream>
#include "Reservation.h"
#include "Time.h"


	void Reservation::setId(unsigned int val) {
		if (val>0)
		{
			this->_id = val;
		}
		else
		{
			throw new std::runtime_error("Invalid id");
		}
	}
	void Reservation::copy(const Reservation& other) {
		if (this!=&other)
		{
			this->_id = other.getID();
			this->_customer = other.getCustomer();
			this->_room = other.getRoom();
			this->_startDate = other.getStartDate();
			this->_endDate = other.getEndDate();

		}
	}


	Reservation::Reservation() {
		this->_id = 0;
	}
	Reservation::Reservation(unsigned int id, Customer customer, Room room, Time start, Time end) {
		setId(id);
		this->_customer = customer;
		this->_room = room;
		this->_startDate = start;
		this->_endDate = end;
	}
	Reservation::Reservation(const Reservation& other) {
		copy(other);
	}


	const Room Reservation::getRoom() const { return this->_room; }
	const unsigned int Reservation::getRoomNumber() const {
		return this->_room.getRoomNumber();
	}
	const unsigned int Reservation::getID() const {
		return this->_id;
	}
	const Time Reservation::getEndDate() const {
		return this->_endDate;
	}
	const Time Reservation::getStartDate() const {
		return this->_startDate;
	}
	const unsigned int Reservation::getRoomPrice() const {
		return this->_room.getPriceForANight();
	}
	const char* Reservation::getCustomerName() const {
		return this->_customer.getName();
	}
	const Customer Reservation::getCustomer() const {
		return this->_customer;
	}

	bool Reservation::operator==(const Reservation& other) {
		return this->_id == other._id || this == &other ? true : false;
	}
	std::ostream& operator<<(std::ostream& os, const Reservation& obj) {
		os << "ID: " << obj._id << std::endl;
		os << "Room: " << obj._room.getRoomNumber() << ", " << obj._room.getRoomType() << std::endl;
		os << "Customer: " << obj._customer.getName() << ", " << obj._customer.getTelephoneNumber() <<", " << obj._customer.getAddress() << std::endl;
		os << "Start: " << obj._startDate << std::endl;
		os << "End: " << obj._endDate << std::endl;

		return os;
	 }

	int Reservation::priceForReservation() {
		return Time::daysBetweenDates(this->_startDate, this->_endDate) * this->_room.getPriceForANight();
	}
	bool Reservation::isTheRoomFreeForThePeriod(const Time& start, const Time& end) {
		if (end < this->_startDate || this->_endDate < start)
		{		
			return false;
		}
		return true;
	}

