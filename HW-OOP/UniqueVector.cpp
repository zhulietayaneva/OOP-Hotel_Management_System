#include <iostream>
#include <cstring>
#include <functional>
#include "UniqueVector.h"

template<class T>
class UniqueVector {
private:

	T* _arr;
	int _length = 0;
	int _capacity;

	void setCapacity(int val) {

		if (val > 0)
		{
			this->_capacity = val;
		}
		else
		{
			throw new exception("Invalid value!");
		}
	}

	void deleteArr() {
		delete[]_arr;
		_arr = nullptr;

	}
	void copy(const UniqueVector<T>& other) {
		deleteArr();
		for (size_t i = 0; i < other.getLength(); i++)
		{
			this->_arr[i] = other._arr[i]; //TODO
		}
		this->_capacity = other.getCapacity();
		this->_length = other.getLength();
	}

	bool exists(const T& element) const {
		for (size_t i = 0; i < _length; i++)
		{
			if (_arr[i] == element)
			{
				return true;
			}
		}
		return false;
	}
	void resize() {
		_capacity *= 2;
		T* newarr = new T[_capacity];

		for (size_t i = 0; i < _length; i++)
		{
			newarr[i] = _arr[i];
		}
		delete[]_arr;
		_arr = newarr;

	}
	bool needsResizing() const {
		if (_length == _capacity)
		{
			return true;
		}
		return false;
	}

public:

	UniqueVector()
	{
		_arr = new T[5];
		_capacity = 5;
	}
	UniqueVector(int capacity)
	{
		setCapacity(capacity);
		_arr = new T[capacity];
	}
	UniqueVector(const UniqueVector& other) {
		copy();
	}
	~UniqueVector() {
		deleteArr();
	}

	const int getLength() const { return _length; }
	const int getCapacity() const { return _capacity; }

	UniqueVector<T>& operator=(const UniqueVector<T>& element) {
		if (this != element){
		
			copy();
		}

		return *this;
	}
	T& operator[](int i) {
		return _arr[i];
	}
	const T& operator[](int i) const {
		return _arr[i];
	}
	friend std::ostream& operator<<(std::ostream& os, const UniqueVector<T>& element) {
		for (size_t i = 0; i < _length; i++)
		{
			os << _arr[i] << " ";
		}
		os << endl;
		return os;
	}

	
	void addElement(const T& element) {
		if (!exists(element))
		{
			if (needsResizing())
			{
				resize();
			}
			_arr[_length] = element;
			++_length;
		}
		else
		{
			std::cout << "Element " << element << " already exists!\n";
		}

	}
	void addElementAt(int position, const T& element) {

		if (!exists(element))
		{
			if (needsResizing())
			{
				resize();
			}

			T* newArr = new T[_capacity];
			for (size_t i = 0; i < position - 1; i++)
			{

				newArr[i] = _arr[i];
			}
			newArr[position - 1] = element;
			for (size_t i = position; i < _length; i++)
			{
				newArr[i] = _arr[i];
			}

			delete[]_arr;
			_length++;
			newArr = _arr;

		}
		else
		{
			std::cout << "Element " << element << " already exists!\n";
		}

	}
	void removeElementAt(int postition) {
		if (postition <= _length)
		{
			for (size_t i = postition - 1; i < _length - 2; i++)
			{
				_arr[i] = _arr[i + 1];
			}
			_length--;
			delete _arr[_length];
			_arr[_length] = nullptr;
		}
		else
		{
			cout << "Element " << _arr[postition] << " already exists!\n";
		}
	}

	void reverseArray() {

		T* newArr = new T[_capacity];
		int ind = 0;
		for (size_t i = _length - 1; i >= 0; i--)
		{
			newArr[ind] = _arr[i];
		}

		delete[]_arr;
		_arr = newArr;
	}

	template<typename U>
	UniqueVector<U> map(function<U(const T&)>) const
	{
		UniqueVector<U> result;
		for (int i = 0; i < _length; i++)
		{
			result.addElement(f(_arr[i]));
		}
		return result;
	}
	UniqueVector<T> filter(function<bool(const T&)> predicate)
	{
		UniqueVector<T> result;

		for (size_t i = 0; i < _length; i++)
		{
			if (predicate(_arr[i]))
			{
				result.addElement(_arr[i]);
			}
		}
		return result;
	}
	template<typename U>
	U reduce(U null_val, function<U(U, T)> op) const
	{
		U result = null_val;
		for (int i = 0; i < _length; i++)
		{
			result = op(result, _arr[i]);
		}
		return result;
	}
	UniqueVector<T> partition(function<bool(const T&)> predicate)
	{
		UniqueVector<T> first;
		UniqueVector<T> _second;

		for (size_t i = 0; i < _length; i++)
		{
			if (predicate(_arr[i]))
			{
				first.addElement(_arr[i]);
			}
			else
			{
				_second.addElement(_arr[i]);
			}
		}

		for (size_t i = 0; i < _second.getLength(); i++)
		{
			first.addElementAt(_length + i, _second[i]);
		}

		return first;
	}

};;