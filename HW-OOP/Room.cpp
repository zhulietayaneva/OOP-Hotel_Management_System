#include <iostream>
#include <stdexcept>
#include <cstring>
#include "RoomType.h"
#include "Room.h"


	void Room::setNumber(unsigned int val) {  
		if (val > 0)
		{
			this->_number = val;
		}
		else
		{
			throw new std::runtime_error("Invalid room number!");
		}
	}
	void Room::setDescription(char* val) {
		if (this->_description!=nullptr)
		{
			delete[]this->_description;
		}
		this->_description = new char[strlen(val) + 1];
		strcpy(this->_description, val);
	}

	void Room::destroy() {
		delete[]this->_description;
		this->_description = nullptr;

	}
	void Room::copy(const Room& other) {
		this->_number = other.getRoomNumber();
		this->_type = other.getRoomType();

		if (this->_description != nullptr)
		{
			delete[]this->_description;
		}
		if (other._description != nullptr)
		{
			this->_description = new char[strlen(other.getRoomDescription()) + 1];
			strcpy(this->_description, other.getRoomDescription());
		}
		else
		{
			this->_description = nullptr;
		}
	}


	Room::Room() : _description(nullptr)
	{
	}

	Room::Room(unsigned int num, RoomType type, char* description)
	{
		setNumber(num);
		this->_type = type;
		setDescription(description);
	}
	Room::Room(const Room& other) {
		copy(other);
	}
	Room::~Room() {
		destroy();
	}


	const unsigned int Room::getRoomNumber() const {
		return this->_number;
	}
	const RoomType Room::getRoomType() const {
		return this->_type;
	}
	const char* Room::getRoomDescription() const {
		return this->_description;
	}
	const unsigned int Room::getPriceForANight()const {
		switch (this->_type)
		{
		case RoomType::Invalid: return 0;

		case RoomType::Single: return 40;

		case RoomType::Double: return 65;

		case RoomType::Suite: return 90;

		}
	}

	Room& Room::operator=(const Room& other) {
		if (this != &other) {

			copy(other);
		}

		return *this;
	}
	bool Room::operator==(const Room& other) {

		if (other.getRoomNumber() == this->_number || &other == this)
		{
			return false;
		}
		return true;

	}
	std::ostream& operator<<(std::ostream& os, const Room& obj) {

		os << "Room number: " << obj.getRoomNumber() << std::endl;
		os << "Room Type: " << obj.getRoomType() << std::endl;
		os << "Room description: " << obj.getRoomDescription() << std::endl;

		return os;
	}

