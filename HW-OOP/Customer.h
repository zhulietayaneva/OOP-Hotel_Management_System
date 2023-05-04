#pragma once
#include <iostream>


class Customer {
private:

	char* _name = nullptr;
	char* _telNumber = nullptr;
	char* _address = nullptr;

	void setName(const char* val);
	void setTelephoneNumber(const char* val);
	void setAddress(const char* val);

	void copy(const Customer& other);
	void destroy();

public:

	Customer();
	Customer(char* name, char* telNumber, char* address);
	Customer(const Customer& other);
	~Customer();	

	const char* getName() const;
	const char* getTelephoneNumber() const;
	const char* getAddress() const;
	
	Customer& operator=(const Customer& other);
	bool operator==(const Customer& other);
	friend std::ostream& operator<<(std::ostream& os, const Customer& obj);

};