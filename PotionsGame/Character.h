#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <fstream>
#include "Backpack.h"
#include "CoinPouch.h"
#include "DynamicArray.h"
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

	Character() {//default constructor
		name = "Default";
		level = 1;
		xp = 0;
		health = 100;
		loadBackpack();
		loadCoinPouch();
	}
	Character(const std::string& n, double l, int h, int x) {//name, level, health, xp
		name = n;
		level = l;
		health = h;
		xp = x;
		loadBackpack();
		loadCoinPouch();
	}

	std::string getName() { return name; }
	void setName(const std::string& n) { name = n; }

	double getLevel() { return level; }
	void setLevel(const double l) { level = l; }//might not use

	void displayEverything() const;//display array passed into method 

	void gainXP(int xp);
	int xpToNextLevel() const { return static_cast<int>(level * 100); }//calculate xp to next level based on level
	void levelUp();

	int getHealth() const{ return health; }
	void setHealth(int h) { health = h; }// might not use
	void takeDamage(int);
	void heal(int);

	void addCoins(int plat, int gold, int silver, int bronze) { purse.addCoins(plat, gold, silver, bronze); }//add coins into purse
	void addCoins(int value){}
	bool spendCoins(int amount) { return purse.spendCoins(amount); }//spend coins gets rid of amount of coins 
	void displayCoins() { purse.displayCoins(); }//display all the coins in your purse or coinpouch

	void addPotion(Potions& p) { pack.addPotion(p, inventoryArray); }//you can use the object name to add a potion if already constructed;
	void removePotion(const std::string& potionName) { pack.removePotion(inventoryArray, potionName); pack.writePotionsToFile(inventoryArray, "Backpack.bin"); } // use string name of potion to delete
	void usePotion(const std::string&);
	void buyPotion(Potions&);

	//potions
	void saveBackpack() {pack.writePotionsToFile(inventoryArray, "Backpack.bin");}
	void loadBackpack() {pack.readFromFile(inventoryArray);}

	//coinpouch
	void saveCoinPouch() { purse.writeCoinsToFile("CoinPouch.bin"); }
	void loadCoinPouch() { purse.readCoinsFromFile("CoinPouch.bin"); }
	
	//save and load all
	void saveAll(const std::string& filename);
	void loadAll(const std::string& filename);

	int find(const std::string& potionName) const {
		for (int i = 0; i < inventoryArray.getElements(); ++i) {
			if (inventoryArray[i].getName() == potionName) {
				return i;
			}
		}
		return -1;
	}

	//various random methods
	bool boolusePotion(const std::string& potionName);
	std::vector<std::string> getPotionNamesInInventory() const;


};

#endif