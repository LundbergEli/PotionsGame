#ifndef BACKPACK_H
#define BACKPACK_H
#pragma once
#include "DynamicArray.h"
#include "Potions.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class Backpack
{
private:
	DynamicArray PotionInventory[3];
	Potions potion;
public:

	Backpack() {}

	string getName() {

	}

	void insertDefaultPotions(DynamicArray&);
	void displayWholeBackpack(DynamicArray&);
	void addPotion(Potions&, DynamicArray&);
	void writePotionsToFile(const DynamicArray&, const std::string&);
	void readFromFile(DynamicArray& Array);
	void removePotion(DynamicArray&, Potions&);
	void searchPotion(DynamicArray&, Potions&);

};

#endif