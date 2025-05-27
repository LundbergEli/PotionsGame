#include "Character.h"
#include <fstream>

void Character::save(const std::string& filename, DynamicArray& array)  {
	if (filename == "Backpack.bin") {
		pack.writePotionsToFile(array, filename);
	}
	else if(filename == "CoinPouch.bin"){
		purse.writeCoinsToFile(array, filename);
	}
	else {
		cout << "Unable to find that file\n";
	}
}

void Character::load(const std::string& filename, DynamicArray& array) {
	if (filename == "Backpack.bin") {
		pack.readFromFile(array);
	}
	else if (filename == "CoinPouch.bin") {
		purse.readCoinsFromFile(filename);
	}
	else {
		cout << "Unable to read that file";
	}
}

void Character::displayEverything() {
	std::cout << "Character " << name << '\n';

	purse.readCoinsFromFile("CoinPouch.bin");
	cout << '\n'; 
	purse.displayCoins();
	cout << '\n';
	pack.displayWholeBackpack(inventoryArray);
}

void Character::gainXP(int amt) {
	xp += amt;

	std::cout << "You gained " << amt << " XP!\n";

	while (xp >= xpToNextLevel()) {
		xp -= xpToNextLevel();
		levelUp();
	}
}

void Character::levelUp() {
	level++;
	std::cout << "Congratulations! You leveled up to level " << level << "!\n";

	if (level > 10) {
		maxHealth += 20; // Increase max health by 20 for levels above 10
		std::cout << "Your max health has increased to " << maxHealth << "!\n";
	}
	else {
		maxHealth += 10; // Increase max health by 10 for levels 1-10
		std::cout << "Your max health has increased to " << maxHealth << "!\n";
	}

}

void Character::takeDamage(int dmg) {
	if (dmg < 0) {
		std::cout << "Damage cannot be negative.\n";
	}
	health -= dmg;
	if (health < 0) {
		health = 0; // Ensure health doesn't go below 0
		std::cout << "You have taken " << dmg << " damage. Your health is now " << health << ".\n";
		std::cout << "You have died.\n";
	}
	else {
		std::cout << "You have taken " << dmg << " damage. Your health is now " << health << ".\n";
	}
}


void Character::heal(int amt) {
	if (amt < 0) {
		std::cout << "Healing amount cannot be negative.\n";
		return;
	}
	health += amt;
	if (health > maxHealth) {
		health = maxHealth; // Ensure health doesn't exceed max health
	}
	std::cout << "You have healed " << amt << " health. Your health is now " << health << ".\n";
}

void Character::usePotion(std::string& potionName) {
	// Check if the potion exists in the inventory
	bool potionExists = pack.boolremovePotion(inventoryArray, potionName);

	//apply the potion effect here based on the name 
	if(potionExists){
		if (potionName == "Speed Potion") {
			std::cout << "You used the Speed Potion. You feel quick.\n";
			gainXP(25);
			heal(5);
		}
		else if (potionName == "Shrink Potion") {
			std::cout << "You used the Shrink Potion. You feel smaller.\n";
			// Apply shrinking effect logic here
		}
		else if (potionName == "Freeze Potion") {
			std::cout << "You used the Freeze Potion. Everything around you is freezing.\n";
			// Apply freezing effect logic here
		}
		else if (potionName == "Healing Potion") {
			std::cout << "You used the Healing Potion. You feel rejuvenated.\n";
			heal(50); // Example healing amount
		}
		else {
			std::cout << "Unknown potion effect.\n";
		}
	}
}



void Character::saveAll(const std::string& slotName) {
	//save core attributes to a file
	std::ofstream out(slotName + ".dat", std::ios::out | std::ios::binary);

	if (!out.is_open()) {		// If the file cannot be opened, print an error message	
		std::cout << "Error opening file for reading.\n";
		return;
	}

	size_t nameLen = name.size();

	out.write(reinterpret_cast<const char*>(&nameLen), sizeof(nameLen));
	out.write(name.c_str(), nameLen);

	out.write(reinterpret_cast<const char*>(&level), sizeof(level));	
	out.write(reinterpret_cast<const char*>(&xp), sizeof(xp));
	out.write(reinterpret_cast<const char*>(&health), sizeof(health));
	out.write(reinterpret_cast<const char*>(&maxHealth), sizeof(maxHealth));
	out.close();

	//save to the existing files
	save("Backpack.bin", inventoryArray);
	save("CoinPouch.bin", inventoryArray);
	std::cout << "Character saved to " << slotName << ".dat\n";
}


void Character::loadAll(const std::string& slotName) {
	//load core attributes from a file
	std::ifstream in(slotName + ".dat", std::ios::in | std::ios::binary);

	if (!in.is_open()) { 		// If the file cannot be opened, print an error message
		std::cout << "Error opening file for reading.\n";
		return;
	}

	size_t nameLen;
	in.read(reinterpret_cast<char*>(&nameLen), sizeof(nameLen));
	name.resize(nameLen);

	in.read(&name[0], nameLen);
	in.read(reinterpret_cast<char*>(&level), sizeof(level));
	in.read(reinterpret_cast<char*>(&xp), sizeof(xp));
	in.read(reinterpret_cast<char*>(&health), sizeof(health));
	in.read(reinterpret_cast<char*>(&maxHealth), sizeof(maxHealth));
	in.close();

	//load from the existing files
	load("Backpack.bin", inventoryArray);
	load("CoinPouch.bin", inventoryArray);
	std::cout << "Character loaded from " << slotName << ".dat\n";
}