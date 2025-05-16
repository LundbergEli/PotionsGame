#ifndef COINPOUCH_H
#define COINPOUCH_H
#pragma once
#include "Potions.h"
#include "DynamicArray.h"
#include <fstream>

class CoinPouch
{
private: 
	
public: 
	void writeCoinsToFile(const DynamicArray&, const std::string&);
	void addCoins();
};

#endif