#include "Potions.h"

Potions::Potions(std::string n, std::string d, std::string p, int c) {
	name = n;
	desc = d;
	potency = p;
	cost = c;

}

Potions::Potions(const Potions& copyPotion) {//overloaded copy constructor
	name = copyPotion.name;
	desc = copyPotion.desc;
	potency = copyPotion.potency;
	cost = copyPotion.cost;
}

Potions& Potions::operator=(const Potions& rhs) {//overloaded assingment operator 
	if (this != &rhs) {
		name = rhs.name;
		desc = rhs.desc;
		potency = rhs.potency;
		cost = rhs.cost;
	}
	return *this;
}

bool Potions::operator==(const Potions& other) const {//overloaded == operator for the find function in DynamicArray class very cool very nice
	return name == other.name &&
		desc == other.desc &&
		potency == other.potency &&
		cost == other.cost;
}

void Potions::displayFormattedCost(Potions& potion) {//this one will take a potions object for getting cost in coins for single potions
	std::string result;
	int remainingCost = potion.getCost();
	int numPlat = remainingCost / moneyValues::plat;
	remainingCost %= moneyValues::plat;
	int numGold = remainingCost / moneyValues::gold;
	remainingCost %= moneyValues::gold;
	int numSilver = remainingCost / moneyValues::silver;
	remainingCost %= moneyValues::silver;
	int numBronze = remainingCost / moneyValues::bronze;
	remainingCost %= moneyValues::bronze;

	if (numPlat > 0) {
		if (!result.empty()) { result += ", "; }
		result += std::to_string(numPlat) + " Platinum";
	}
	if (numGold > 0) {
		if (!result.empty()) { result += ", "; }
		result += std::to_string(numGold) + " Gold";
	}
	if (numSilver > 0) {
		if (!result.empty()) { result += ", "; }
		result += std::to_string(numSilver) + " Silver";
	}
	if (numBronze > 0) {
		if (!result.empty()) { result += ", "; }
		result += std::to_string(numBronze) + " Bronze";
	}

	std::cout << result << std::endl;
}

std::string getFormattedCost(const Potions& potion) {
	std::string result;
	int remainingCost = potion.getCost();
	int numPlat = remainingCost / moneyValues::plat;
	remainingCost %= moneyValues::plat;
	int numGold = remainingCost / moneyValues::gold;
	remainingCost %= moneyValues::gold;
	int numSilver = remainingCost / moneyValues::silver;
	remainingCost %= moneyValues::silver;
	int numBronze = remainingCost / moneyValues::bronze;
	remainingCost %= moneyValues::bronze;

	if (numPlat > 0) {
		if (!result.empty()) { result += ", "; }
		result += std::to_string(numPlat) + " Platinum";
	}
	if (numGold > 0) {
		if (!result.empty()) { result += ", "; }
		result += std::to_string(numGold) + " Gold";
	}
	if (numSilver > 0) {
		if (!result.empty()) { result += ", "; }
		result += std::to_string(numSilver) + " Silver";
	}
	if (numBronze > 0) {
		if (!result.empty()) { result += ", "; }
		result += std::to_string(numBronze) + " Bronze";
	}

	return result;
}

void Potions::displayFormattedCostNUM(int totalCost) {// i put this over here to hide it becuase i was confused with two of them i shouldve found a better wau to do this 
	std::string result;
	int remainingCost = totalCost;
	int numPlat = remainingCost / moneyValues::plat;
	remainingCost %= moneyValues::plat;
	int numGold = remainingCost / moneyValues::gold;
	remainingCost %= moneyValues::gold;
	int numSilver = remainingCost / moneyValues::silver;
	remainingCost %= moneyValues::silver;
	int numBronze = remainingCost / moneyValues::bronze;
	remainingCost %= moneyValues::bronze;

	if (numPlat > 0) {
		if (!result.empty()) { result += ", "; }
		result += std::to_string(numPlat) + " Platinum";
	}
	if (numGold > 0) {
		if (!result.empty()) { result += ", "; }
		result += std::to_string(numGold) + " Gold";
	}
	if (numSilver > 0) {
		if (!result.empty()) { result += ", "; }
		result += std::to_string(numSilver) + " Silver";
	}
	if (numBronze > 0) {
		if (!result.empty()) { result += ", "; }
		result += std::to_string(numBronze) + " Bronze";
	}

	std::cout << result << std::endl;
}
std::string Potions::getFormattedCost(const Potions&)
{
	return std::string();
}
;


std::string Potions::getFormattedCost() const {
	std::string result;
	int remainingCost = cost;
	int numPlat = remainingCost / moneyValues::plat;
	remainingCost %= moneyValues::plat;
	int numGold = remainingCost / moneyValues::gold;
	remainingCost %= moneyValues::gold;
	int numSilver = remainingCost / moneyValues::silver;
	remainingCost %= moneyValues::silver;
	int numBronze = remainingCost / moneyValues::bronze;
	remainingCost %= moneyValues::bronze;

	if (numPlat > 0) {
		if (!result.empty()) { result += ", "; }
		result += std::to_string(numPlat) + " Platinum";
	}
	if (numGold > 0) {
		if (!result.empty()) { result += ", "; }
		result += std::to_string(numGold) + " Gold";
	}
	if (numSilver > 0) {
		if (!result.empty()) { result += ", "; }
		result += std::to_string(numSilver) + " Silver";
	}
	if (numBronze > 0) {
		if (!result.empty()) { result += ", "; }
		result += std::to_string(numBronze) + " Bronze";
	}

	return result;
}


