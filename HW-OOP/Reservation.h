#pragma once
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

	void copy(const Reservation& other);

public:
	Reservation();
	Reservation(const Reservation& other);

	const unsigned int getRoomNumber() const;
	const unsigned int getID() const;
	const Time getEndDate() const;
	const unsigned int getRoomPrice() const;
	const char* getCustomerName() const;

	bool operator==(const Reservation& other);
	friend std::ostream& operator<<(std::ostream& os, const Reservation& obj);

	int priceForReservation();
	bool isTheRoomFreeForThePeriod(const Time& start, const Time& end);

};
