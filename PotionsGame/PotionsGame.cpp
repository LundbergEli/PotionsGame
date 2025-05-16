// PotionsGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include "Potions.h"
#include "DynamicArray.h"
#include "Backpack.h"
#include "Character.h"
using namespace std;

int main()
{

	DynamicArray PotionInventory;
	Backpack pack;
	CoinPouch purse;


	Potions ShrinkPotion("Shrink Potion", "Makes you shrink a lot", "Small af", (moneyValues::silver * 2) + 96);
	Potions FreezePotion("Freeze potion", "Makes anything it touches freeze", "cold as hell boi", (moneyValues::gold * 2) + 6);
	Potions HealingPotion("Healing notion", "Heals you to full hp", "Extremely Potent", (moneyValues::plat * 2) + 89);
	Potions SlowPotion("Slowing Potion", "Slows you down to sloth speed", "Extremely Potent", (moneyValues::gold * 2) + 109);


	pack.readFromFile(PotionInventory);
	/*PotionInventory.insert(SlowPotion);
	pack.addPotion(HealingPotion, PotionInventory);
	pack.addPotion(FreezePotion, PotionInventory);
	pack.addPotion(ShrinkPotion, PotionInventory);*/
	purse.writeCoinsToFile(PotionInventory, "CoinPouch.bin");

	pack.displayWholeBackpack(PotionInventory);
	cout << '\n\n';
	//PotionInventory.display();
}
