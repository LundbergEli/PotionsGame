#include "Character.h"
#include <fstream>



void Character::displayEverything() const{
	std::cout << "Character " << name
		<< "\nLevel: " << level
		<< "\nXp: " << xp
		<< "\nhealth: " << health;

	std::cout << "\nCoins: ";  
	purse.displayCoins();//display your coinpouch
	std::cout << purse.getTotalInBronze() << '\n';
	std::cout << endl;
	inventoryArray.display();//display your backpack
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

void Character::usePotion(const std::string& potionName) {
	// Check if the potion exists in the inventory
	bool potionExists = pack.boolremovePotion(inventoryArray, potionName);

	//apply the potion effect here based on the name 
	if (!potionExists) { std::cout << "You do not have " << potionName << " in your inventory. \n"; }
		else {
			if (potionName == "Speed Potion") {
				std::cout << "You used the Speed Potion. You feel quick.\n";
				gainXP(25);
				heal(5);
			}
			else if (potionName == "Shrink Potion") {
				std::cout << "You used the Shrink Potion. You feel smaller.\n";
			
			}
			else if (potionName == "Freeze Potion") {
				std::cout << "You used the Freeze Potion. Everything around you is freezing.\n";
			
			}
			else if (potionName == "Healing Potion") {
				std::cout << "You used the Healing Potion. You feel rejuvenated.\n";
				heal(maxHealth);
				gainXP(30);
			}
			else {
				std::cout << "Unknown potion effect.\n";
				gainXP(45);
				heal(30);
			}
	}
}



void Character::saveAll(const std::string& filename) {
	//save core attributes to a file
	std::ofstream out(filename + ".dat", std::ios::out | std::ios::binary);

	if (!out.is_open()) {		// If the file cannot be opened,throw an exception	
		throw std::runtime_error("Failed to open “" + filename + "” for writing");
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
	saveBackpack();
	saveCoinPouch();
	std::cout << "Character saved to " << filename << ".dat\n";
}


void Character::loadAll(const std::string& filename) {
	//load core attributes from a file
	std::ifstream in(filename + ".dat", std::ios::in | std::ios::binary);

	if (!in.is_open()) { 		// If the file cannot be opened, print an error message
		throw std::runtime_error("Failed to open “" + filename + "” for reading");
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
	loadBackpack();
	loadCoinPouch();
	std::cout << "Character loaded from " << filename << ".dat\n";
}


void Character::buyPotion(Potions& potion) {
	int cost = potion.getCost();

	//if the amount in your coinpouch is less than the cost of potion do not give them potion and exit method
	if (purse.getTotalInBronze() < cost) { 
		std::cout << "\nnot enough coins in your purse to buy " << potion.getName() << " \n"; return;
	}

	else {
		spendCoins(cost); 
		addPotion(potion);
		std::cout << "You have bought a " << potion.getName();
	}

	
}

bool Character::boolusePotion(const std::string& potionName) {
	int index = inventoryArray.find(potionName);
	if (index != -1) {
		removePotion(potionName);
		// Apply potion effects here if needed
		return true;
	}
	std::cout << "You don't have that potion!\n";
	return false;
}
