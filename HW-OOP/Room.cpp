#include <iostream>
#include <stdexcept>
#include <cstring>
#include "room.h"


class Room {

private:
	unsigned int _number = 0;
	RoomType _type = RoomType::Invalid;
	char* _description;

	void setNumber(unsigned int val) {  
		if (val > 0)
		{
			_number = val;
		}
		else
		{
			throw new std::runtime_error("Invalid room number!");
		}
	}
	void setDescription(char* val) {
		delete[] _description;
		_description = new char[strlen(val) + 1];
		strcpy(_description, val);
	}

	void destroy() {
		delete[]_description;
		_description = nullptr;

	}
	void copy(const Room& other) {
		this->_number = other.getRoomNumber();
		this->_type = other.getRoomType();

		delete[]_description;
		_description = new char[strlen(other.getRoomDescription())];
		strcpy(this->_description, other.getRoomDescription());
	}


public:

	Room()
	{
		_description = new char[1] {'\0'};
	}
	Room(unsigned int num, RoomType type, char* description)
	{
		setNumber(num);
		_type = type;
		setDescription(description);
	}
	Room(const Room& other) {
		copy(other);

	}
	~Room() {
		destroy();
	}


	const unsigned int getRoomNumber() const {
		return _number;
	}
	const RoomType getRoomType() const {
		return _type;
	}
	const char* getRoomDescription() const {
		return _description;
	}
	const unsigned int getPriceForANight()const {
		switch (_type)
		{
		case RoomType::Invalid: return 0;

		case RoomType::Single: return 40;

		case RoomType::Double: return 65;

		case RoomType::Suite: return 90;

		}
	}

	Room& operator=(const Room& other) {
		copy(other);
		return *this;
	}
	bool operator==(const Room& other) {

		if (other.getRoomNumber() == this->_number || &other == this)
		{
			return false;
		}
		return true;

	}
	friend std::ostream& operator<<(std::ostream& os, const Room& obj) {

		os << "Room number: " << obj.getRoomNumber() << std::endl;
		os << "Room Type: " << obj.getRoomType() << std::endl;
		os << "Room description: " << obj.getRoomDescription() << std::endl;

		return os;
	}


};