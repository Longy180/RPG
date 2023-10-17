#ifndef HEALTHBOOSTTEST_H
# define HEALTHBOOSTTEST_H
#include <iostream>
#include <string>

#include "item.h"
#include "healthBoost.h"
#include "player.h"

class healthBoostTest {
private:
    void testItemCreation() {
        Item item("Sword", 100, 50);
        if (item.get_name() != "Sword" || item.get_buyPrice() != 100 || item.get_sellPrice() != 50) {
            std::cout << "Error in test 1: Item creation." << std::endl;
        }
    }

    void testHealthBoostCreation() {
        HealthBoost boost("Boost");
        if (boost.get_name() != "Boost" || boost.get_buyPrice() != 10 || boost.get_sellPrice() != 5 || boost.get_healthIncrease() != 25) {
            std::cout << "Error in test 2: HealthBoost creation." << std::endl;
        }
    }

    void testHealthBoostEffect() {
        Player player(
          (std::string) "Sprites/halfling ranger/HalflingRangerIdleSide.gif",
          200, 200, 100, 100, 10, 0);
        HealthBoost boost;
        
        int initialhealth = player.get_maxHealth();
        boost.itemEffect(&player);

        if (player.get_damage() != initialhealth + boost.get_healthIncrease()) {
            std::cout << "Error in test 3: HealthBoost effect." << std::endl;
        }
    }

public:
    void ItemTest() {
        testItemCreation();
        testHealthBoostCreation();
        testHealthBoostEffect();
    }
};

#endif