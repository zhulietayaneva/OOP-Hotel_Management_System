#include "UniqueVector.h"
#include <iostream>
#include <functional>
#include <cstring>



template<typename T>
void UniqueVector<T>::setCapacity(int val) {
	if (val <= 0) {
		throw std::invalid_argument("Invalid value");
	}
	this->_capacity = val;
}

template<typename T>
void UniqueVector<T>::deleteArr() {
	delete[]this->_arr;
	this->_arr = nullptr;
}

template<typename T>
void UniqueVector<T>::copy(const UniqueVector<T>& other) {
	deleteArr();
	for (size_t i = 0; i < other.getLength(); i++)
	{
		this->_arr[i] = other._arr[i]; //TODO
	}
	this->_capacity = other.getCapacity();
	this->_length = other.getLength();
}

template<typename T>
bool UniqueVector<T>::exists(const T& element) const {
	for (size_t i = 0; i < this->_length; i++)
	{
		if (this->_arr[i] == element)
		{
			return true;
		}
	}
	return false;
}

template<typename T>
void UniqueVector<T>::resize() {
	this->_capacity *= 2;
	T* newarr = new T[this->_capacity];

	for (size_t i = 0; i < this->_length; i++)
	{
		newarr[i] = this->_arr[i];
	}
	delete[]this->_arr;
	this->_arr = newarr;

}

template<typename T>
bool UniqueVector<T>::needsResizing() const {
	if (this->_length == this->_capacity)
	{
		return true;
	}
	return false;
}

template<typename T>
UniqueVector<T>::UniqueVector()
{
	this->_capacity = 5;
	this->_arr = new T[this->_capacity];
}

template<typename T>
UniqueVector<T>::UniqueVector(int capacity)
{
	setCapacity(capacity);
	this->_arr = new T[capacity];
}

template<typename T>
UniqueVector<T>::UniqueVector(const UniqueVector& other) {
	copy(other);
}

template<typename T>
UniqueVector<T>::~UniqueVector() {
	deleteArr();
}

template<typename T>
const int UniqueVector<T>::getLength() const { return this->_length; }

template<typename T>
const int UniqueVector<T>::getCapacity() const { return this->_capacity; }

template<typename T>
UniqueVector<T>& UniqueVector<T>::operator=(const UniqueVector<T>& element) {
	if (this != &element) {

		copy(element);
	}
	return *this;
}

template<typename T>
T& UniqueVector<T>::operator[](int i) {
	return this->_arr[i];
}

template<typename T>
const T& UniqueVector<T>::operator[](int i) const {
	return this->_arr[i];
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const UniqueVector<T>& element) {
	for (size_t i = 0; i < this->_length; i++)
	{
		os << this->_arr[i] << " ";
	}
	os << std::endl;
	return os;
}

template<typename T>
void UniqueVector<T>::addElement(const T& element) {
	if (!exists(element))
	{
		if (needsResizing())
		{
			resize();
		}
		this->_arr[this->_length] = element;
		++this->_length;
	}
	else
	{
		std::cout << "Element " << element << " already exists!\n";
	}

}

template<typename T>
void UniqueVector<T>::addElementAt(int position, const T& element) {

	if (!exists(element))
	{
		if (needsResizing())
		{
			resize();
		}

		T* newArr = new T[this->_capacity];
		for (size_t i = 0; i < position - 1; i++)
		{

			newArr[i] = this->_arr[i];
		}
		newArr[position - 1] = element;
		for (size_t i = position; i < this->_length; i++)
		{
			newArr[i] = this->_arr[i];
		}

		delete[]this->_arr;
		this->_length++;
		newArr = this->_arr;

	}
	else
	{
		std::cout << "Element " << element << " already exists!\n";
	}

}

template<typename T>
void UniqueVector<T>::removeElementAt(int postition) {
	if (postition <= _length)
	{
		for (size_t i = postition - 1; i < this->_length - 2; i++)
		{
			this->_arr[i] = this->_arr[i + 1];
		}
		this->_length--;
		delete _arr[_length];
		_arr[_length] = nullptr;
	}
	else
	{
		std::cout << "Element " << _arr[postition] << " already exists!" << std::endl;;
	}
}

template<typename T>
void UniqueVector<T>::reverseArray() {

	T* newArr = new T[this->_capacity];
	int ind = 0;
	for (size_t i = this->_length - 1; i >= 0; i--)
	{
		newArr[ind] = this->_arr[i];
	}

	delete[]this->_arr;
	this->_arr = newArr;
}

template<typename T>
template<typename U>
UniqueVector<U> UniqueVector<T>::map(std::function<U(const T&)>) const
{
	UniqueVector<U> result;
	for (int i = 0; i < _length; i++)
	{
		result.addElement(f(_arr[i]));
	}
	return result;
}

template<typename T>
UniqueVector<T> UniqueVector<T>::filter(std::function<bool(const T&)> predicate)
{
	UniqueVector<T> result;

	for (size_t i = 0; i < this->_length; i++)
	{
		if (predicate(this->_arr[i]))
		{
			result.addElement(this->_arr[i]);
		}
	}
	return result;
}

template<typename T>
template<typename U>
U UniqueVector<T>::reduce(U null_val, std::function<U(U, T)> op) const
{
	U result = null_val;
	for (int i = 0; i < this->_length; i++)
	{
		result = op(result, this->_arr[i]);
	}
	return result;
}

template<typename T>
UniqueVector<T> UniqueVector<T>::partition(std::function<bool(const T&)> predicate)
{
	UniqueVector<T> first;
	UniqueVector<T> _second;

	for (size_t i = 0; i < this->_length; i++)
	{
		if (predicate(this->_arr[i]))
		{
			first.addElement(this->_arr[i]);
		}
		else
		{
			_second.addElement(this->_arr[i]);
		}
	}

	for (size_t i = 0; i < _second.getLength(); i++)
	{
		first.addElementAt(this->_length + i, _second[i]);
	}

	return first;
}

