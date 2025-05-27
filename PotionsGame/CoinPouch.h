#ifndef COINPOUCH_H
#define COINPOUCH_H
#pragma once
#include "Potions.h"
#include "DynamicArray.h"
#include <fstream>

struct coinCount {
	int platinum = 0, gold = 0, silver = 0, bronze = 0;
};

class CoinPouch
{
private:
	coinCount coins;
	void convertBronze();
public:
	void writeCoinsToFile(const DynamicArray&, const std::string&);
	void readCoinsFromFile(const std::string&) ;
	void addCoins(int platinum, int gold, int silver, int bronze);
	void displayCoins() const;
	void displayCoins(DynamicArray&) const;
	bool spendCoins(int);

	//getters
	int getPlatinum() const { return coins.platinum; }
	int getGold() const { return coins.gold; }
	int getSilver() const { return coins.silver; }
	int getBronze() const { return coins.bronze; }
	int getTotalInBronze() const {
		return coins.platinum * moneyValues::plat +
			coins.gold * moneyValues::gold +
			coins.silver * moneyValues::silver +
			coins.bronze;
	}
};
#endif