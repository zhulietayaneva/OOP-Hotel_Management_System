#include <iostream>
#include "Hotel.h"

	
	void Hotel::copy(const Hotel& other) {

		this->_rooms = *(new UniqueVector<Room>[other._rooms.getLength()]);
		this->_reservations = *(new UniqueVector<Reservation>[other._reservations.getLength()]);

	}
	void Hotel::destroy() {
		delete[]&_rooms;
		delete[] & _reservations;
	}
	
	Hotel::Hotel()
	{
		this->_rooms = *(new UniqueVector<Room>());
		this->_reservations = *(new UniqueVector<Reservation>());

	}
	Hotel::Hotel(int roomCapacity, int reservationCapacity)
	{
		this->_rooms = *(new UniqueVector<Room>[roomCapacity]);
		this->_reservations = *(new UniqueVector<Reservation>[reservationCapacity]);
	}
	Hotel::Hotel(const Hotel& other) {
		copy(other);
	}
	Hotel::~Hotel() {
		destroy();
	}
	
	void Hotel::addReservation(const Reservation& reservation) {
		this->_reservations.addElement(reservation);
	}
	void Hotel::removeReservationWithNumber(unsigned int id) {


		for (size_t i = 0; i < this->_reservations.getLength(); i++)
		{
			if (this->_reservations[i].getID() == id)
			{

				this->_reservations.removeElementAt(i);

			}
		}


	}
	const unsigned int Hotel::profitFromReservationsEndingOn(const Time& end) const {
		unsigned int sum = 0;

		for (size_t i = 0; i < this->_reservations.getLength(); i++)
		{
			if (this->_reservations[i].getEndDate() == end)
			{
				sum += this->_reservations[i].getRoomPrice();
			}
		}

		return sum;

	}
	void Hotel::ReservatinsMadeByClient(const char* clientName) {

		for (size_t i = 0; i < this->_reservations.getLength(); i++)
		{
			if (this->_reservations[i].getCustomerName() == clientName)
			{
				std::cout << this->_reservations[i] << std::endl;;
			}
		}


	}
	
	void Hotel::addRoom(const Room& room) {
		_rooms.addElement(room);
	}
	const bool Hotel::isRoomFreeBetween(const Time start, const Time end, unsigned int roomNum) {

		for (size_t i = 0; i < this->_reservations.getLength(); i++)
		{

			if (this->_reservations[i].getRoomNumber() == roomNum)
			{
				return this->_reservations[i].isTheRoomFreeForThePeriod(start, end);
			}
		}
		return false;
	}
	void Hotel::freeRoomsBetween(const Time& start, const Time& end) {


		for (size_t i = 0; i < this->_reservations.getLength(); i++)
		{

			if (this->_reservations[i].isTheRoomFreeForThePeriod(start, end))
			{
				std::cout << "Room: " << this->_reservations[i].getRoomNumber() << std::endl;
			}
		}
	}
	std::ostream& operator<< (std::ostream& os, const Hotel& obj) {

		for (size_t i = 0; i < obj._reservations.getLength(); i++)
		{
			os << obj._reservations[i] << std::endl;
		}
		return os;

	}

