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


static const int characters = 3;

class Character : public CoinPouch, public Backpack
{
private: 
	Potions potionInventory[characters];
	CoinPouch purse[characters];
	Backpack pack[characters];
public:
	 

};

#endif