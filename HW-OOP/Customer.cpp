#include <iostream>
#include <cstring>
#include <stdexcept>
#include "Customer.h"



	void Customer::setName(const char* val) {
		if (strlen(val) > 0)
		{
			this->_name = new char[strlen(val) + 1];
			strcpy(this->_name, val);
		}
		else
		{
			throw new std::runtime_error("Invalid name!");
		}
	}
	void Customer::setTelephoneNumber(const char* val) {
		if (strlen(val) == 10 && strncmp(val, "08", 2) == 0)
		{
			this->_telNumber = new char[strlen(val) + 1];
			strcpy(this->_telNumber, val);
		}
		else
		{
			throw new std::runtime_error("Invalid phone number");
		}
	}
	void Customer::setAddress(const char* val) {
		if (strlen(val) > 0)
		{
			this->_address = new char[strlen(val) + 1];
			strcpy(this->_address, val);
		}
		else
		{
			throw new std::runtime_error("Invalid address");
		}
	}

	void Customer::copy(const Customer& other) {
		destroy();

		setName(other.getName());
		setTelephoneNumber(other.getTelephoneNumber());
		setAddress(other.getAddress());
	}
	void Customer::destroy() {
		if (this->_name != nullptr) {
			delete[] this->_name;
			this->_name = nullptr;
		}
		if (this->_telNumber != nullptr) {
			delete[] this->_telNumber;
			this->_telNumber = nullptr;
		}
		if (this->_address != nullptr) {
			delete[] this->_address;
			this->_address = nullptr;
		}
	}


	Customer::Customer()
	{
		this->_name = nullptr;
		this->_telNumber = nullptr;
		this->_address = nullptr;
	}
	Customer::Customer(char* name, char* telNumber, char* address) {
		
		setName(name);
		setTelephoneNumber(telNumber);
		setAddress(address);
	}
	Customer::Customer(const Customer& other) {
		copy(other);
	}
	Customer::~Customer() {
		destroy();
	}

	const char* Customer::getName() const { return this->_name; }
	const char* Customer::getTelephoneNumber() const { return this->_telNumber; }
	const char* Customer::getAddress() const { return this->_address; }

	Customer& Customer::operator=(const Customer& other) {
		if (this != &other) {

			copy(other);
		}
		return *this;
	}
	bool Customer::operator==(const Customer& other) {

		if (this == &other)
		{
			return true;
		}
		if (strcmp(this->getName(), other.getName()) == 0
			&& strcmp(this->getTelephoneNumber(), other.getTelephoneNumber()) == 0
			&& strcmp(this->getAddress(), other.getAddress()) == 0)
		{
			return true;
		}
		return false;
	}
	std::ostream& operator<<(std::ostream& os, const Customer& obj) {
		os << "Name: " << obj.getName() << std::endl;
		os << "Phone number: " << obj.getTelephoneNumber() << std::endl;
		os << "Address: " << obj.getAddress() << std::endl;

		return os;
	}

