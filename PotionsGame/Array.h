#ifndef ARRAY_H
#define ARRAY_H
#include <stdexcept>
#pragma once

template <class t>
class Array {
private:
	int elements = 0; 
	t* data;

public:
	Array() : elements(0), data(nullptr) {}

	Array(int size) : elements(size) {
		data = new t[size];
	}

	~Array() {
		delete[] data;
	}
	
	Array(const Array& other) : elements(other.elements) {
		data = new t[elements];
		for (int i = 0; i < elements; ++i) {
			data[i] = other.data[i];
		}
	}

	Array& operator=(const Array& other) {
		if (this != &other) {
			delete[] data;
			elements = other.elements;
			data = new t[elements];
			for (int i = 0; i < elements; ++i) {
				data[i] = other.data[i];
			}
		}
		return *this;
	}

	Array(Array&& other) noexcept : elements(other.elements), data(other.data) {
		other.elements = 0;
		other.data = nullptr;
	}

	Array& operator=(Array&& other) noexcept {
		if (this != &other) {
			delete[] data;
			elements = other.elements;
			data = other.data;
			other.elements = 0;
			other.data = nullptr;
		}
		return *this;
	}

	void remove(int index) {
		if (index < 0 || index >= elements) { throw std::out_of_range("Index out of range"); }
		t* newData = new t[elements - 1];
		for (int i = 0, j = 0; i < elements; ++i) {
			if (i != index) {
				newData[j++] = data[i];
			}
		}
		delete[] data;
		data = newData;
		elements--;
	}

	void clear() {
		delete[] data;
		data = nullptr;
		elements = 0;
	}

	void insert(const t& item) {
		t* newData = new t[elements + 1];
		for (int i = 0; i < elements; ++i) {
			newData[i] = data[i];
		}
		newData[elements] = item;
		delete[] data;
		data = newData;
		elements++;
	}
	
	int getSize() const {
		return elements;
	}
	
	t& operator[](int index) {
		if (index < 0 || index >= elements) { throw std::out_of_range("Index out of range"); }
		return data[index];
	}
	
	const t& operator[](int index) const {
		if (index < 0 || index >= elements) { throw std::out_of_range("Index out of range"); }
		return data[index];
	}
};

#endif