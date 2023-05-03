#pragma once
#include <iostream>
#include "UniqueVector.h"
#include "Room.h"
#include "RoomType.h"
#include "Reservation.h"
#include "Time.h"


class Hotel {

private:

	UniqueVector<Room> _rooms;
	UniqueVector<Reservation> _reservations;

	void copy(const Hotel& other);
	void destroy();

public:

	Hotel();
	Hotel(int roomCapacity, int reservationCapacity);
	Hotel(const Hotel& other);
	~Hotel();

	void addReservation(const Reservation& reservation);
	void removeReservationWithNumber(unsigned int id);
	const unsigned int profitFromReservationsEndingOn(const Time& end) const;
	void ReservatinsMadeByClient(const char* clientName);

	void addRoom(const Room& room);
	const bool isRoomFreeBetween(const Time start, const Time end, unsigned int roomNum);
	void freeRoomsBetween(const Time& start, const Time& end);


	friend std::ostream& operator<< (std::ostream& os, const Hotel& obj);


};