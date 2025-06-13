//This is a fun potions RPG where you can explore the dark forests and fight off gangs of witches that want to jump you. Have fun!
//This game includes potions you can use and find in the explore tab. There are many different things adventures you can go on
//I also included quests that auto check off when completed 

#include <iostream>
#include <string>
#include "Potions.h"
#include "DynamicArray.h"
#include "Backpack.h"
#include "Quest.h"
#include "Array.h"
#include "Character.h"
#include "CoinPouch.h"
using namespace std;

Array<Quest> questList;

int main()
{
    srand(time(0));

    Character bobby("Bobby", 1, 100, 0);
    CoinPouch purse;

    // Add quests
    questList.insert(Quest("Shrink Potion"));
    questList.insert(Quest("Speed Potion"));
    questList.insert(Quest("Healing Potion"));
    questList.insert(Quest("Freeze Potion"));
    questList.insert(Quest("Expensive Potion"));

    // Example potions
    Potions SpeedPotion("Speed Potion", "Speeds you up to rabbit speed", "Extremely Potent", (moneyValues::gold * 5) + 109);
    Potions ShrinkPotion("Shrink Potion", "Makes you shrink a lot", "Small af", (moneyValues::silver * 2) + 96);
    Potions FreezePotion("Freeze Potion", "Makes anything it touches freeze", "cold as hell boi", (moneyValues::gold * 2) + 6);
    Potions HealingPotion("Healing Potion", "Heals you to full hp", "Extremely Potent", (moneyValues::plat * 2) + 89);
    Potions ExpensivePotion("Expensive Potion", "Costs a lot of monet", "Costly", 4651);

    bobby.loadAll("Bobby");

    bool running = true;
    while (running) {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Explore\n";
        cout << "2. View Inventory\n";
        cout << "3. Use Potion\n";
        cout << "4. Buy Potion\n";
        cout << "5. View Quests\n";
        cout << "6. Save Game\n";
        cout << "7. Exit\n";
        cout << "Choose an option: ";
        int choice;
        cin >> choice;
        cin.ignore(); // clear newline

        switch (choice) {
        case 1: { // Explore
            int event = rand() % 8;
            if (event == 0) {
                cout << "You found a Healing Potion!\n";
                bobby.buyPotion(HealingPotion);
                break;
            }

            else if (event == 1) {
                cout << "You found some coins!\n";
                bobby.addCoins(0, 2, 5, 10);
                break;
            }

            else if (event == 2) {
                cout << "You met a wandering merchant who offers you a random potion!\n"
                    << "Would you like to buy a potion for 100 bronze coins? (y/n): ";
                char merchantChoice;
                cin >> merchantChoice;
                cin.ignore();
                if (merchantChoice == 'y' || merchantChoice == 'Y') {
                    if (bobby.spendCoins(100)) {
                        Potions randomPotion("Random Potion", "A mysterious potion with unknown effects", "Unknown", 100);
                        bobby.addPotion(randomPotion);
                        cout << "You bought a Random Potion!\n";
                        break;
                    }
                    else {
                        cout << "You don't have enough coins.\n";
                        break;
                    }
                }
                else if (merchantChoice == 'n' || merchantChoice == 'N') {
                    cout << "You chose not to buy the potion.\n";
                    break;
                }
                else { break;
                }
            }

            else if (event == 3) {
                cout << "You encountered a wild creature! It attacks you!\n";
                bobby.takeDamage(50);
                if (bobby.getHealth() <= 0) {
                    cout << "You have died. Game over.\n";
                    running = false; // Exit the game
                    break;
                }
                else {
                    cout << "You survived the attack, but lost some health. Get a health potion to rejuvenate your health\n";
                    break;
                }
            }

            else if (event == 4) {
                cout << "You found a mysterious potion! It seems to have strange effects.\n";
                // create a temporary variable for the potion before adding it to the inventory.  
                Potions mysteriousPotion("Mysterious Potion", "Unknown effects", "Very Potent", 150);
                bobby.addPotion(mysteriousPotion);
                break;
            }


            else if (event == 5) {
                cout << "You have triggered a trap set by a gang of witches! "
                    << "\nYou can either fight, run, or surender to the witches which would you like to do?\n"
                    << "1. Fight.\n"
                    << "2. RUN!\n"
                    << "3. Surrender.\n";
                int witchChoice;
                cin >> witchChoice;
                if (witchChoice == 1) {
                    int fightOutcome = rand() % 3;
                    if (fightOutcome == 0) {
                        cout << "You bravely fought the witches and won! You gain 50 XP and 2 gold coins. The witches also dropped a potion\n";
                        Potions witchesBrew("Witches Brew", "A potion brewed by the witches. It's mysterious, and slightly cursed!", "Very Potent", 200);
                        bobby.gainXP(50); bobby.addCoins(0, 2, 0, 0); bobby.addPotion(witchesBrew);
                    }
                    else if (fightOutcome == 1) {
                        cout << "You tried to fight the witches but got overpowered and had to run away.\n";
                        bobby.takeDamage(50);  bobby.spendCoins(115);
                    }
                    else if (fightOutcome == 2) {
                        cout << "You took out a few witches and looted them before running away with minor injuries!";
						Potions witchesLoot("Witches Loot", "The witches use this to make their brooms fly. ", "Very Potent", 150);
                        bobby.takeDamage(23); 
                    }
                }
                else if (witchChoice == 2) {
                    cout << "You successfully ran away from the witches, but you lost 20 bronze coins in the process.\n";
                    bobby.spendCoins(20);
                }
                else if (witchChoice == 3) {
                    cout << "You surrendered to the witches. They took all your coins, but spared your life.\n";
                    bobby.spendCoins(purse.getTotalInBronze());
                }
                else {
                    cout << "Nothing happened during your exploration.\n";
                }
                break;
            }

            else if (event == 6) {
                cout << "You find a pack of fairies and they offer you a Uknown potion for 3 gold coins do you accept (y/n)\n";
                char fairyOffer;
                cin >> fairyOffer;
                if (fairyOffer == 'y' || fairyOffer == 'Y') {
                    cout << "You bought the Unknown Potion from the fairies.\n";
                    Potions unkownPotion("Unknown Potion", "A potion with mysterious effects", "Unknown", 300);
                    bobby.spendCoins(300); bobby.addPotion(unkownPotion); bobby.gainXP(5); break;
                }
                else if (fairyOffer == 'n' || fairyOffer == 'N') {
                    cout << "You declined the offer from the fairies and decided to head home.\n"; break;
                }
                else {
                    cout << "Invalid choice. You missed the opportunity to buy the potion.\n"; break;
                }
            }
            else if (event == 7) {
                cout << "You have wondered upon a merchant selling potions do you want to see his inventory (y/n)\n";
                char seePotions;
                cin >> seePotions;
                while (seePotions == 'Y' || seePotions == 'y') {
                    cout << "The merchant has these potions for sale\n"
                        << "1. Shrink potion\n"
                        << "2. Speed potion\n"
                        << "3. Expensive potion\n"
                        << "4. Freeze potion\n"
                        << "5. Healing potion\n";
                    cout << "Do you want to purchase a potion? (y/n)\n";
                    char buyPotions;
                    cin >> buyPotions;
                    
                    if(buyPotions == 'y' || buyPotions == 'Y') {
                        cout << "Please enter the number infront of the potion you want. \n";
                        int mChoice;
                        cin >> mChoice;
                        switch (mChoice) {
                        case 1: bobby.buyPotion(ShrinkPotion); break;
                        case 2: bobby.buyPotion(SpeedPotion); break;
                        case 3: bobby.buyPotion(ExpensivePotion); break;
                        case 4: bobby.buyPotion(FreezePotion); break;
                        case 5: bobby.buyPotion(HealingPotion); break;
                        }
                    }

                    else if (buyPotions == 'n' || buyPotions == 'N') {
                        cout << "You chose not to buy any potions from the merchant.\n"; break; 
                    }
                    break;
                }
				if (seePotions == 'n' || seePotions == 'N') {
                    cout << "You chose not to buy any potions from the merchant.\n"; break;
				}
				else {
                    break;
				}
            }
        }
        case 2: // View Inventory
            bobby.displayEverything();
            break;
        case 3: { // Use Potion
            auto potionNames = bobby.getPotionNamesInInventory();
            if (potionNames.empty()) {
                cout << "You have no potions in your inventory.\n";
                break;
            }
            cout << "Which potion do you want to use?\n";
            for (size_t i = 0; i < potionNames.size(); ++i) {
                cout << (i + 1) << ". " << potionNames[i] << '\n';
            }
            int useChoice;
            cin >> useChoice;
            cin.ignore();
            if (useChoice < 1 || useChoice >(int)potionNames.size()) {
                cout << "Invalid choice.\n";
                break;
            }
            string potionName = potionNames[useChoice - 1];
            bobby.usePotion(potionName);
            for (int i = 0; i < questList.getSize(); ++i) {
                questList[i].checkCompletion(potionName, bobby);
            }

            break;
        }
        case 4: { // Buy Potion
            cout << "Which potion do you want to buy?\n";
            cout << "1. Shrink Potion\n2. Speed Potion\n3. Healing Potion\n4. Freeze Potion\n5. Expensive Potion\n";
            int buyChoice;
            cin >> buyChoice;
            cin.ignore();
            switch (buyChoice) {
            case 1: bobby.buyPotion(ShrinkPotion); break;
            case 2: bobby.buyPotion(SpeedPotion); break;
            case 3: bobby.buyPotion(HealingPotion); break;
            case 4: bobby.buyPotion(FreezePotion); break;
            case 5: bobby.buyPotion(ExpensivePotion); break;
            default: cout << "Invalid choice.\n";
            }
            break;
        }
        case 5: // View Quests
            cout << "\n--- Quest List ---\n";
            for (int i = 0; i < questList.getSize(); ++i) {
                cout << questList[i].getObjective();
                if (questList[i].isCompleted()) cout << " (Completed)";
                cout << endl;
            }
            break;
        case 6: // Save Game
            bobby.saveAll("Bobby");
            cout << "Game saved.\n";
            break;
        case 7: // Exit
            running = false;
            bobby.saveAll("Bobby");
            cout << "Game saved. Exiting.\n";
            break;
        default:
            cout << "Invalid option.\n";
        }
    }
	return 0;
}
