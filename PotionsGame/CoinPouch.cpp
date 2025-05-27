#include "CoinPouch.h"


void CoinPouch::displayCoins() const{
	std::cout << "Platinum: " << coins.platinum << '\t' << "Gold: " << coins.gold << '\t' << "Silver: " << coins.silver << '\t' << "Bronze: " << coins.bronze << '\n';

}


void CoinPouch::displayCoins(DynamicArray& array) const {
}

void CoinPouch::addCoins(int platinum, int gold, int silver, int bronze) {
	int totalBronze = platinum * moneyValues::plat + // add all values of coins up into bronze coins to then convert to more coins 
		gold * moneyValues::gold +
		silver * moneyValues::silver +
		bronze;

	coins.bronze += totalBronze;

	convertBronze();

	std::cout << "You have added, ";
	Potions potion;
	potion.displayFormattedCostNUM(totalBronze);
	
}


void CoinPouch::writeCoinsToFile(const DynamicArray&, const std::string& filename) {
	// Overwrite file each time (recommended for saving current state)
	std::ofstream outFile(filename, std::ios::out | std::ios::binary);
	// If you want to append instead, use:
	// std::ofstream outFile(filename, std::ios::out | std::ios::app | std::ios::binary);

	if (!outFile) {
		std::cout << "Error opening file for writing.\n";
		return;
	}

	// Write the coin counts as binary data
	outFile.write(reinterpret_cast<const char*>(&coins.platinum), sizeof(coins.platinum));
	outFile.write(reinterpret_cast<const char*>(&coins.gold), sizeof(coins.gold));
	outFile.write(reinterpret_cast<const char*>(&coins.silver), sizeof(coins.silver));
	outFile.write(reinterpret_cast<const char*>(&coins.bronze), sizeof(coins.bronze));

	outFile.close();
	std::cout << "Coin pouch saved to file.\n";
}


void CoinPouch::readCoinsFromFile(const std::string& filename) {
	std::ifstream inFile(filename, std::ios::in | std::ios::binary);
	if (!inFile) {
		std::cout << "Error opening file for reading.\n";
		return;
	}

	inFile.read(reinterpret_cast<char*>(&coins.platinum), sizeof(coins.platinum));
	inFile.read(reinterpret_cast<char*>(&coins.gold), sizeof(coins.gold));
	inFile.read(reinterpret_cast<char*>(&coins.silver), sizeof(coins.silver));
	inFile.read(reinterpret_cast<char*>(&coins.bronze), sizeof(coins.bronze));

	inFile.close();
	//std::cout << "Coin pouch loaded from file.\n";
}


void CoinPouch::convertBronze() {

	// Combine all coins into total bronze
	int totalBronze = coins.platinum * moneyValues::plat +
		coins.gold * moneyValues::gold +
		coins.silver * moneyValues::silver +
		coins.bronze;

	//add back coins into object
	coins.platinum = totalBronze / moneyValues::plat;
	totalBronze %= moneyValues::plat;
	coins.gold = totalBronze / moneyValues::gold;
	totalBronze %= moneyValues::gold;
	coins.silver = totalBronze / moneyValues::silver;
	totalBronze %= moneyValues::silver;
	coins.bronze = totalBronze;
}


bool CoinPouch::spendCoins(int amount) {
	//get total number of bronze coins for easier calculations
	int totalBronze = coins.platinum * moneyValues::plat +
		coins.gold * moneyValues::gold +
		coins.silver * moneyValues::silver +
		coins.bronze;

	if (amount > totalBronze) {
		std::cout << "Not enough coins sorry go make some bread\n\n";
		return false;
	}

	//subtract the amount from your coins
	totalBronze -= amount;

	//normalize your remaining coins for the coinpouch object 
	coins.platinum = totalBronze / moneyValues::plat;
	totalBronze %= moneyValues::plat;
	coins.gold = totalBronze / moneyValues::gold;
	totalBronze %= moneyValues::gold;
	coins.silver = totalBronze / moneyValues::silver;
	totalBronze %= moneyValues::silver;
	coins.bronze = totalBronze;

	return true;
}