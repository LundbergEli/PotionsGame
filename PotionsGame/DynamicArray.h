#ifndef DYYNAMICARRAY_H
#define DYYNAMICARRAY_H
#pragma once
#include <iostream>
#include "Potions.h"
class DynamicArray
{
private:
	int elements = 0;
	Potions* Array;
public: 
	//default ctor
	DynamicArray() : elements(0), Array(nullptr) {}

	//copy ctor
	//creates a deep copy of the object 
	DynamicArray(const DynamicArray& other);

	//move ctor i think
	//steal the data from another object
	DynamicArray(DynamicArray&& other) noexcept;

	int getElements() const{//retrieve the number of elements in an array
		return  elements;
	}

	//copy assignment operator
	DynamicArray& operator=(const DynamicArray& other);

	//move assingment operator
	//steals resources from a object
	DynamicArray& operator=(DynamicArray&& other) noexcept;

	// searches the array for a matching potion
	// Returns the index of the first match if found or -1 if no match 
	int find(const Potions& other)const;
	Potions find(int index) const;
	int find(const std::string&)const;
	
	void insert(const Potions& other);
	void insert(const std::string& n, const std::string& d, const std::string& p, int c);

	void display(int viewElement) const;
	void display() const;

	void Delete(const Potions& other);
	void Delete(int other);

	std::string getName() {
		return Array->getName();
	}

	int getCost() {
		return Array->getCost();
	}

	std::string getDesc() {
		return Array->getDesc();
	}

	std::string getPotency() {
		return Array->getPotency();
	}



	~DynamicArray() {// get rid of the dynamic memory so no mem leaks
		delete[] Array;
	}



};

#endif