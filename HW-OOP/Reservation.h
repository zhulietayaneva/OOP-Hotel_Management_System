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

	void setId(unsigned int val);
	void copy(const Reservation& other);

public:
	Reservation();
	Reservation(unsigned int id, Customer customer, Room room, Time start, Time end);
	Reservation(const Reservation& other);
	
	const Room getRoom()const ;
	const unsigned int getRoomNumber() const;
	const unsigned int getID() const;
	const Time getEndDate() const;
	const Time getStartDate() const;
	const unsigned int getRoomPrice() const;
	const char* getCustomerName() const;
	const Customer getCustomer() const;

	bool operator==(const Reservation& other);
	friend std::ostream& operator<<(std::ostream& os, const Reservation& obj);

	int priceForReservation();
	bool isTheRoomFreeForThePeriod(const Time& start, const Time& end);

};
