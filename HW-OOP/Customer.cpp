#include <iostream>
#include <cstring>
#include <exception>

class Customer {
private:

	char* _name;
	char* _telNumber;
	char* _address;

	void setName(const char* val) {
		if (strlen(val) > 0)
		{
			_name = new char[strlen(val) + 1];
			strcpy(_name, val);
		}
		else
		{
			throw new std::logic_error("Invalid name!");
		}


	}
	void setTelephoneNumber(const char* val) {
		if (val[0] == '0' && val[1] == '8' && strlen(val) == 10)
		{
			_telNumber = new char[strlen(val) + 1];
			strcpy(_telNumber, val);
		}
		else
		{
			throw new std::logic_error("Invalid phone number");
		}


	}
	void setAddress(const char* val) {
		if (strlen(val) > 0)
		{
			_address = new char[strlen(val) + 1];
			strcpy(_address, val);
		}
		else
		{
			throw new std::logic_error("Invalid address");
		}


	}

	void copy(const Customer& other) {
		destroy();

		setName(other.getName());
		setTelephoneNumber(other.getTelephoneNumber());
		setAddress(other.getAddress());
	}
	void destroy() {
		delete[] _name;
		_name = nullptr;
		delete[] _telNumber;
		_telNumber = nullptr;
		delete[] _address;
		_address = nullptr;
	}

public:


	Customer()
	{
		_name = new char[1] {'\0'};
		_telNumber = new char[1] {'\0'};
		_address = new char[1] {'\0'};
	}
	Customer(char* name, char* telNumber, char* address) {

		destroy();

		setName(name);
		setTelephoneNumber(telNumber);
		setAddress(address);

	}
	Customer(const Customer& other) {
		copy(other);
	}
	~Customer() {
		destroy();
	}

	const char* getName() const { return _name; }
	const char* getTelephoneNumber() const { return _telNumber; }
	const char* getAddress() const { return _address; }

	Customer& operator=(const Customer& other) {
		copy(other);
		return *this;
	}
	bool operator==(const Customer& other) {

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
	friend std::ostream& operator<<(std::ostream& os, const Customer& obj) {
		os << "Name: " << obj.getName() << std::endl;
		os << "Phone number: " << obj.getTelephoneNumber() << std::endl;
		os << "Address: " << obj.getAddress() << std::endl;

		return os;
	}

};