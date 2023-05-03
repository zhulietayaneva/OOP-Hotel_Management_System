#include <iostream>
#include "UniqueVector.h"
#include "Room.h"
#include "Reservation.h"



class Hotel {
private:
	UniqueVector<Room> _rooms;
	UniqueVector<Reservation> _reservations;

	void copy(const Hotel& other) {

		_rooms = *(new UniqueVector<Room>[other._rooms.getLength()]);
		_reservations = *(new UniqueVector<Reservation>[other._reservations.getLength()]);

	}

public:

	Hotel()
	{
		_rooms = *(new UniqueVector<Room>());
		_reservations = *(new UniqueVector<Reservation>());

	}
	Hotel(int roomCapacity, int reservationCapacity)
	{
		_rooms = *(new UniqueVector<Room>[roomCapacity]);
		_reservations = *(new UniqueVector<Reservation>[reservationCapacity]);
	}
	Hotel(const Hotel& other) {
		copy(other);
	}
		
	void addReservation(const Reservation& reservation) {
		_reservations.addElement(reservation);
	}
	void removeReservationWithNumber(unsigned int id) {


		for (size_t i = 0; i < _reservations.getLength(); i++)
		{
			if (_reservations[i].getID() == id)
			{

				_reservations.removeElementAt(i);

			}
		}


	}
	const unsigned int profitFromReservationsEndingOn(const Time& end) const {
		unsigned int sum = 0;

		for (size_t i = 0; i < _reservations.getLength(); i++)
		{
			if (_reservations[i].getEndDate() == end)
			{
				sum += _reservations[i].getRoomPrice();
			}
		}


	}
	void ReservatinsMadeByClient(const char* clientName) {

		for (size_t i = 0; i < _reservations.getLength(); i++)
		{
			if (_reservations[i].getCustomerName() == clientName)
			{
				std::cout << _reservations[i] << std::endl;;
			}
		}


	}

	void addRoom(const Room& room) {
		_rooms.addElement(room);
	}
	const bool isRoomFreeBetween(const Time start, const Time end, unsigned int roomNum) {

		for (size_t i = 0; i < _reservations.getLength(); i++)
		{

			if (_reservations[i].getRoomNumber() == roomNum)
			{
				return _reservations[i].isTheRoomFreeForThePeriod(start, end);
			}
		}
		return false;
	}
	void freeRoomsBetween(const Time& start, const Time& end) {


		for (size_t i = 0; i < _reservations.getLength(); i++)
		{

			if (_reservations[i].isTheRoomFreeForThePeriod(start, end))
			{
				std::cout << "Room: " << _reservations[i].getRoomNumber() << std::endl;
			}
		}
	}

	friend std::ostream& operator<< (std::ostream& os, const Hotel& obj) {

		for (size_t i = 0; i < obj._reservations.getLength(); i++)
		{
			os << obj._reservations[i] << std::endl;
		}
		return os;

	}

};