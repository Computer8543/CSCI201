#pragma once

#include <iostream>
#include <string>

template <class TBD> 
class ARRAY {
private:
	TBD* array;
	int size;
public:
	// Constructor
	ARRAY(int size = 100)
	{
		if (size <= 0)
		{
			throw std::invalid_argument("Array cannot be 0 or less than 0");
		}
		array = new TBD[size];
		this->size = size;
	}
	// Copy Constructor
	ARRAY(const ARRAY<TBD>& other) {
		size = other.size;
		array = new TBD[size];

		for (int i = 0; i < size; i++)
		{
			array[i] = other.array[i];
		}
	}
	// Destructor
	~ARRAY() {
		delete[] array;
		array = NULL;
	}
	// accessor methods
	TBD getValue(int index) {
		if (index < 0 || index >= size) {
			throw std::invalid_argument("Index out of range.");
		}
		return array[index];
	}
	int getSize() {
		return size;
	}
	// mutator
	void setValue(int index, TBD value) {
		if (index < 0 || index >= size)
		{
			throw std::invalid_argument("Index out of range.");
		}
		array[index] = value;
	}

	TBD& operator[](int index) {
		if (index < 0 || index >= size) {
			throw std::invalid_argument("Index out of range.");
		}
		return array[index];
	}

	void append(TBD value) {
		TBD* newArray = new TBD[size + 1];
		for (int i = 0; i < size; i++)
		{
			newArray[i] = array[i];
		}
		newArray[size] = value;
		delete[] array;
		array = newArray;
		size++;
	}

	ARRAY<TBD>& operator+=(TBD value) {
		append(value);
		return *this;
	}
};