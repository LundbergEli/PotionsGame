#ifndef QUEST_H
#define QUEST_H
#include <string>
#include <iostream>
#include "Character.h"
#pragma once


class Quest
{
private:
    std::string requiredPotion;
    bool completed = false;
public:
    Quest() : requiredPotion(""), completed(false) {};

    Quest(const std::string& potion) : requiredPotion(potion) {}

    bool isCompleted() const { return completed; }
    std::string getObjective() const { return "Use a " + requiredPotion; }

    void checkCompletion(const std::string& usedPotion, Character& bob) {
        if (!completed && usedPotion == requiredPotion) {
            std::cout << "Quest completed!!";
            completed = true;
            bob.gainXP(100);
            bob.addCoins(3, 2, 1, 0);
            bob.heal(99);
        }
    }

};

#endif