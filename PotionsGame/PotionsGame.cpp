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
    Character bobby("Bobby", 1, 100, 0);

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
        cout << "1. View Inventory\n";
        cout << "2. Use Potion\n";
        cout << "3. Buy Potion\n";
        cout << "4. View Quests\n";
        cout << "5. Save Game\n";
        cout << "6. Exit\n";
        cout << "Choose an option: ";
        int choice;
        cin >> choice;
        cin.ignore(); // clear newline

        switch (choice) {
        case 1:
            bobby.displayEverything();
            break;
        case 2: {
            cout << "Enter potion name to use: ";
            string potionName;
            getline(cin, potionName);
            if (bobby.boolusePotion(potionName)) {
                // Auto-check all quests for completion
                for (int i = 0; i < questList.getSize(); ++i) {
                    questList[i].checkCompletion(potionName, bobby);
                }
            }
            else {
                cout << "You don't have that potion or it could not be used.\n";
            }
            break;
        }
        case 3: {
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
        case 4:
            cout << "\n--- Quest List ---\n";
            for (int i = 0; i < questList.getSize(); ++i) {
                cout << questList[i].getObjective();
                if (questList[i].isCompleted()) cout << " (Completed)";
                cout << endl;
            }
            break;
        case 5:
            bobby.saveAll("Bobby");
            cout << "Game saved.\n";
            break;
        case 6:
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
