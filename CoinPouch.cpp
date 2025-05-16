#include "CoinPouch.h"

void CoinPouch::writeCoinsToFile(const DynamicArray& array, const std::string& filename = "CoinPouch.bin") {
	std::ofstream outFile(filename, std::ios::out | std::ios::binary);
	if (!outFile) {
		std::cout << "Error opening file for writing.\n";
		return;
	}

	for (int i = 0; i < array.getElements(); ++i) {
		Potions potion = array.find(i);

	}

	outFile.close();
}