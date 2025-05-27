#ifndef POTIONS_H
#define POTIONS_H
#include <iostream>
#include <string>
#pragma once

static const int maxPotions = 5;

struct moneyValues {
static const int plat = 1000;
static const int gold = 100;
static const int silver = 10;
static const int bronze = 1;
};

class Potions
{
private:
std::string name;
std::string desc;
std::string potency;
int cost = 0;

public:
//
Potions() : name(""), desc(""), potency(""), cost(0) {}

//overloaded constructor 
Potions(std::string n, std::string d, std::string p, int c);

Potions(const Potions& copyPotion);

~Potions() {}

Potions& operator=(const Potions& rhs);
bool operator==(const Potions& other) const;

//all the getters and setters until line 88 as of right now 
void setName(std::string n) {
	name = n;
}

std::string getName() const {
	return name;
}


void setDesc(std::string d) {
	desc = d;
}

std::string getDesc() const {
	return desc;
}

void setPotency(int p) {
	potency = p;
}

std::string getPotency() const {
	return potency;
}

void setCost(int c) {
	cost = c;
}

int getCost() const {
	return cost; 
}

void displayFormattedCost(Potions& potion);
void displayFormattedCostNUM(int totalCost);//this function is used to get total and input and integer number instead of an object 
std::string getFormattedCost(const Potions&);
std::string getFormattedCost() const;

};



#endif