#pragma once
#include "RoomType.h"

class Room {
private:
	unsigned int _number = 0;
	RoomType _type = RoomType::Invalid;
	char* _description;

	void setNumber(unsigned int val);
	void setDescription(char* val);

	void destroy();
	void copy(const Room& other);

public:

	Room();
	Room(unsigned int num, RoomType type, char* description);
	Room(const Room& other);
	~Room();


	const unsigned int getRoomNumber() const;
	const RoomType getRoomType() const;
	const char* getRoomDescription() const;
	const unsigned int getPriceForANight()const;

	Room& operator=(const Room& other);
	bool operator==(const Room& other);
	friend std::ostream& operator<<(std::ostream& os, const Room& obj);

};
