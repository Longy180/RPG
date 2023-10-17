#ifndef HEALTHPOTIONTEST_H
# define HEALTHPOTIONTEST_H
#include <iostream>
#include <string>

#include "item.h"
#include "healthPotion.h"
#include "player.h"

class healthPotionTest {
private:
    void testItemCreation() {
        Item item("Sword", 100, 50);
        if (item.get_name() != "Sword" || item.get_buyPrice() != 100 || item.get_sellPrice() != 50) {
            std::cout << "Error in test 1: Item creation." << std::endl;
        }
    }

    void testHealthPotionCreation() {
        HealthPotion boost("Boost");
        if (boost.get_name() != "Boost" || boost.get_buyPrice() != 10 || boost.get_sellPrice() != 5 || boost.get_healthIncrease() != 25) {
            std::cout << "Error in test 2: HealthBoost creation." << std::endl;
        }
    }

    void testHealthPotionEffect() {
        Player player(
          (std::string) "Sprites/halfling ranger/HalflingRangerIdleSide.gif",
          200, 200, 100, 100, 10, 0);
        HealthPotion boost;
        
        int initialhealth = player.get_Health();
        boost.itemEffect(&player);

        if (player.get_damage() != initialhealth + boost.get_healthIncrease() - 25) {
            std::cout << "Error in test 3: HealthBoost effect." << std::endl;
        }
    }

public:
    void ItemTest() {
        testItemCreation();
        testHealthPotionCreation();
        testHealthPotionEffect();
    }
};

#endif