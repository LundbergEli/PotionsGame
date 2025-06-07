// PotionsGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Potions.h"
#include "DynamicArray.h"
#include "Backpack.h"
#include "Quest.h"
#include "Character.h"
#include "CoinPouch.h"
using namespace std;

int main()
{

	DynamicArray PotionInventory;
	Backpack pack;
	CoinPouch purse;
	Character bobby("Bobby", 1, 100, 0);
	Quest shrinkPotionQuest("Shrink Potion");
	Quest speedPotionQuest("Speed Potion");
	Quest freezePotionQuest("Freeze Potion");
	Quest healingPotionQuest("Healing Potion");
	Quest expensivePotionQuest("Expensive Potion");

	Potions SpeedPotion("Speed Potion", "Speeds you up to rabbit speed", "Extremely Potent", (moneyValues::gold * 5) + 109);
	Potions ShrinkPotion("Shrink Potion", "Makes you shrink a lot", "Small af", (moneyValues::silver * 2) + 96);
	Potions FreezePotion("Freeze Potion", "Makes anything it touches freeze", "cold as hell boi", (moneyValues::gold * 2) + 6);
	Potions HealingPotion("Healing Potion", "Heals you to full hp", "Extremely Potent", (moneyValues::plat * 2) + 89);
	Potions ExpensivePotion("Expensive Potion", "Costs a lot of monet", "Costly", 4651);
	
	bobby.loadAll("Bobby"); cout << '\n';
	bobby.buyPotion(ShrinkPotion); cout << '\n';

	bobby.saveAll("Bobby");


	//bobby.loadAll("Bobby");
	//bobby.usePotion("Speed Potion");
	////bobby.takeDamage(20);
	////bobby.heal(10);
	//bobby.displayEverything();
	//bobby.saveAll("Bobby");






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
