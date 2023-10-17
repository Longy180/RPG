#ifndef ATTACKBOOSTTEST_H
# define ATTACKBOOSTTEST_H
#include <iostream>
#include <string>

#include "item.h"
#include "attackBoost.h"
#include "player.h"

class attackBoostTest {
private:
    void testItemCreation() {
        Item item("Sword", 100, 50);
        if (item.get_name() != "Sword" || item.get_buyPrice() != 100 || item.get_sellPrice() != 50) {
            std::cout << "Error in test 1: Item creation." << std::endl;
        }
    }

    void testAttackBoostCreation() {
        AttackBoost boost("Boost");
        if (boost.get_name() != "Boost" || boost.get_buyPrice() != 10 || boost.get_sellPrice() != 5 || boost.get_damageIncrease() != 3) {
            std::cout << "Error in test 2: AttackBoost creation." << std::endl;
        }
    }

    void testAttackBoostEffect() {
        Player player(
          (std::string) "Sprites/halfling ranger/HalflingRangerIdleSide.gif",
          200, 200, 100, 100, 10, 0);
        AttackBoost boost;
        
        int initialDamage = player.get_damage();
        boost.itemEffect(&player);

        if (player.get_damage() != initialDamage + boost.get_damageIncrease()) {
            std::cout << "Error in test 3: AttackBoost effect." << std::endl;
        }
    }

public:
    void ItemTest() {
        testItemCreation();
        testAttackBoostCreation();
        testAttackBoostEffect();
    }
};

#endif