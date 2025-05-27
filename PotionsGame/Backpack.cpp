#include "Backpack.h"

void Backpack::displayWholeBackpack(DynamicArray& array) const{
	readFromFile(array);
	array.display();
}


void Backpack::writePotionsToFile(const DynamicArray& array, const std::string& filename = "Backpack.bin") {
	std::ofstream outFile(filename, std::ios::out | std::ios::binary );
	if (!outFile) {
		std::cout << "Error opening file for writing.\n";
		return;
	}

	for (int i = 0; i < array.getElements(); ++i) {
		Potions potion = array.find(i);

		// Write name
		std::string name = potion.getName();
		size_t nameLength = name.size();
		outFile.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
		outFile.write(name.c_str(), nameLength);

		// Write description
		std::string desc = potion.getDesc();
		size_t descLength = desc.size();
		outFile.write(reinterpret_cast<const char*>(&descLength), sizeof(descLength));
		outFile.write(desc.c_str(), descLength);

		// Write potency
		std::string potency = potion.getPotency();
		size_t potencyLength = potency.size();
		outFile.write(reinterpret_cast<const char*>(&potencyLength), sizeof(potencyLength));
		outFile.write(potency.c_str(), potencyLength);

		// Write cost
		int cost = potion.getCost();
		outFile.write(reinterpret_cast<const char*>(&cost), sizeof(cost));
	}

	outFile.close();
}


void Backpack::readFromFile(DynamicArray& Array) const{
	fstream BackPackFile("Backpack.bin", std::ios::in | std::ios::binary);

	if (!BackPackFile) {
		cout << "Error opening file for reading. \n";
		return;
	}

	while (true) {
		size_t nameLength, descLength, potencyLength;
		int cost;
		std::string name, desc, potency;

		// Read name length and name
		if (!BackPackFile.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength))) break;
		name.resize(nameLength);
		if (!BackPackFile.read(&name[0], nameLength)) break;

		// Read description length and description
		if (!BackPackFile.read(reinterpret_cast<char*>(&descLength), sizeof(descLength))) break;
		desc.resize(descLength);
		if (!BackPackFile.read(&desc[0], descLength)) break;

		// Read potency length and potency
		if (!BackPackFile.read(reinterpret_cast<char*>(&potencyLength), sizeof(potencyLength))) break;
		potency.resize(potencyLength);
		if (!BackPackFile.read(&potency[0], potencyLength)) break;

		// Read cost
		if (!BackPackFile.read(reinterpret_cast<char*>(&cost), sizeof(cost))) break;

		Array.insert(name, desc, potency, cost);
	}

	BackPackFile.close();
}



void Backpack::removePotion(DynamicArray& array, const std::string& potionName) {
	int index = array.find(potionName);
	if (index != -1) {
		array.Delete(index);
	}
	else {
		std::cout << "Potion not found in backpack.\n";
	}
}
bool Backpack::boolremovePotion(DynamicArray& array, const std::string& potionName) {
	int index = array.find(potionName);
	if (index != -1) {
		array.Delete(index);
		return true; // Successfully removed
	}
	else {
		std::cout << "Potion not found in backpack.\n";
		return false; // Potion not found
	}
}

void Backpack::addPotion(Potions& potion, DynamicArray& array) {
	// Check if the potion already exists in the array
	if (array.find(potion) == -1) {
		array.insert(potion);
		writePotionsToFile(array, "Backpack.bin"); // Save after adding
	}
	else {
		std::cout << "Potion already in backpack.\n";
	}
}


void Backpack::searchPotion(DynamicArray& array, Potions& potionName) {
	int index = array.find(potionName);
	
	if (index != -1) {
		cout << "found ";
		array.display(index);
	}
	else {
		cout << "potion not found";
	}
}


void Backpack::insertDefaultPotions(DynamicArray& array) {

	readFromFile(array);

	array.insert(Potions("Healing Potion", "Heals you to full hp", "Extremely Potent", (moneyValues::plat * 2) + 89));
	array.insert(Potions("Hurting Potion", "Can hurt a lot or a little", "Mildly Potent", 69));
	array.insert(Potions("Smoke potion", "Create a wall of smoke to escape", "Very Potent", 95));
	array.insert(Potions("Invisibility Potion", "Nobody will be able to see you after you drink this", "Unknown", (moneyValues::silver * 2) + 202));
	array.insert(Potions("Truth Potion", "Whoever drink this will tell the truth and nothing but the truth", "Highly Potent", 165));
	array.insert(Potions("Loud Potion", "Makes your voice loud as hell", "Hella loud", (moneyValues::bronze * 2) + 9));
	array.insert(Potions("Shrink Potion", "Makes you shrink a lot", "Small af", (moneyValues::silver * 2) + 96));

	//cout << tempArray.getElements();

	writePotionsToFile(array, "Backpack.bin");
	 
}