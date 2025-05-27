// PotionsGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Potions.h"
#include "DynamicArray.h"
#include "Backpack.h"
#include "Character.h"
#include "CoinPouch.h"
using namespace std;

int main()
{

	DynamicArray PotionInventory;
	Backpack pack;
	CoinPouch purse;
	Character bobby("Bobby", 1, 100, 0);

	Potions SpeedPotion("Speed Potion", "Speeds you up to rabbit speed", "Extremely Potent", (moneyValues::gold * 2) + 109);
	Potions ShrinkPotion("Shrink Potion", "Makes you shrink a lot", "Small af", (moneyValues::silver * 2) + 96);
	Potions FreezePotion("Freeze Potion", "Makes anything it touches freeze", "cold as hell boi", (moneyValues::gold * 2) + 6);
	Potions HealingPotion("Healing Potion", "Heals you to full hp", "Extremely Potent", (moneyValues::plat * 2) + 89);

	
	bobby.loadAll("Bobby");
	bobby.removePotion("Freeze Potion");
	bobby.displayEverything();






	//pack.readFromFile(PotionInventory);
	////pack.addPotion(SlowPotion, PotionInventory);
	////pack.removePotion(PotionInventory, "Slowing Potion");
	////PotionInventory.insert(SlowPotion);
	///*pack.addPotion(HealingPotion, PotionInventory);
	//pack.addPotion(FreezePotion, PotionInventory);
	//pack.addPotion(ShrinkPotion, PotionInventory);*/

	////pack.displayWholeBackpack(PotionInventory);
	////cout << '\n\n';
	//PotionInventory.display();

	//purse.readCoinsFromFile("CoinPouch.bin");
	////purse.spendCoins(280);
	////purse.addCoins(4, 6, 19, 9);
	//purse.displayCoins();
	//cout << "\n" << purse.getTotalInBronze() << '\n';
	//purse.writeCoinsToFile(PotionInventory, "CoinPouch.bin");
}
