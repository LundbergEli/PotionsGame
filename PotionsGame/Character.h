#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <fstream>
#include "Backpack.h"
#include "CoinPouch.h"
#include "DynamicArray.h"
#include "Backpack.h"
#include "CoinPouch.h"
using namespace std;
#pragma once


class Character
{
private: 
	std::string name;
	double level;
	int xp;
	int health;
	int maxHealth = 100;
	CoinPouch purse;
	Backpack pack;
	DynamicArray inventoryArray;
public:
	Character() { pack.readFromFile(inventoryArray); }
	Character(const std::string& n, double l, int h) {//name, level, health
		name = n;
		level = l;
		health = h;
	}

	std::string getName() { return name; }
	void setName(const std::string& n) { name = n; }

	double getLevel() { return level; }
	void setLevel(const double l) { level = l; }//might not use

	void displayEverything() ;//display array passed into method 

	void gainXP(int xp);
	int xpToNextLevel() const { return static_cast<int>(level * 100); }//calculate xp to next level based on level
	void levelUp();

	int getHealth(int) { return health; }
	void setHealth(int h) { health = h; }// might not use
	void takeDamage(int);
	void heal(int);

	void addCoins(int plat, int gold, int silver, int bronze) { purse.addCoins(plat, gold, silver, bronze); }//add coins into purse
	bool spendCoins(int amount) { return purse.spendCoins(amount); }//spend coins gets rid of amount of coins 
	void displayCoins() { purse.displayCoins(); }//display all the coins in your purse or coinpouch

	void addPotion(Potions& p) { pack.addPotion(p, inventoryArray); }//you can use the object name to add a potion if already constructed;
	void removePotion(const std::string& potionName) { pack.removePotion(inventoryArray, potionName); pack.writePotionsToFile(inventoryArray, "Backpack.bin"); } // use string name of potion to delete
	void usePotion(std::string&);
	void displayPurse()const;

	void save(const std::string&, DynamicArray&);
	void load(const std::string&, DynamicArray&);
	void saveAll(const std::string& slotName);
	void loadAll(const std::string& slotName);

};

#endif