#pragma once
#include <iostream>
#include <functional>
#include <cstring>

template <typename T>
class UniqueVector {

private:

	T* _arr;
	int _length = 0;
	int _capacity;

	void setCapacity(int val);

	void deleteArr();
	void copy(const UniqueVector<T>& other);


	bool exists(const T& element) const;
	void resize();
	bool needsResizing() const;

public:

	UniqueVector();
	UniqueVector(int capacity);
	UniqueVector(const UniqueVector& other);
	~UniqueVector();

	const int getLength() const;
	const int getCapacity() const;

	UniqueVector<T>& operator=(const UniqueVector<T>& element);
	T& operator[](int i);
	const T& operator[](int i) const;
	friend std::ostream& operator<<(std::ostream& os, const UniqueVector<T>& element);

	void addElement(const T& element);
	void addElementAt(int position, const T& element);
	void removeElementAt(int postition);
	
	void reverseArray();
	
	template<typename U>
	UniqueVector<U> map(std::function<U(const T&)>) const;
	UniqueVector<T> filter(std::function<bool(const T&)> predicate);
	template<typename U>
	U reduce(U null_val, std::function<U(U, T)> op) const;
	UniqueVector<T> partition(std::function<bool(const T&)> predicate);
	
};
