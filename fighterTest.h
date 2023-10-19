#ifndef FIGHTERTEST_H
#define FIGHTERTEST_H

#include <iostream>
#include <string>

#include "enemy.h"
#include "fighter.h"
#include "healthPotion.h"

class FighterTest {
 private:
  Fighter fighter;
  Enemy enemy;

  void testEntityProperties() {
    if (fighter.get_x() != 200) {
      std::cout << "Error in test 1: Getting fighter x." << std::endl;
    }
    if (fighter.get_y() != 200) {
      std::cout << "Error in test 2: Getting fighter y." << std::endl;
    }
  }

  void testCharacterProperties() {
    if (fighter.get_Health() != 100) {
      std::cout << "Error in test 3: Getting fighter health." << std::endl;
    }
    if (fighter.get_maxHealth() != 100) {
      std::cout << "Error in test 4: Getting fighter maxHealth." << std::endl;
    }
    if (fighter.get_damage() != 10) {
      std::cout << "Error in test 5: Getting fighter damage." << std::endl;
    }
  }

  void testPlayerProperties() {
    if (fighter.get_Gold() != 0) {
      std::cout << "Error in test 6: Getting fighter gold." << std::endl;
    }
  }

  void testMovement() {
    fighter.move_right(10);
    if (fighter.get_x() != 210) {
      std::cout << "Error in test 7: Getting fighter x after move right."
                << std::endl;
    }

    fighter.move_left(5);
    if (fighter.get_x() != 205) {
      std::cout << "Error in test 8: Getting fighter x after move left."
                << std::endl;
    }
  }

  void testAttacks() {
    if (enemy.get_Health() != 100) {
      std::cout << "Error in test 9: Getting correct enemy health before fight."
                << std::endl;
    }

    fighter.attack1(&enemy);
    if (enemy.get_Health() != 90) {
      std::cout
          << "Error in test 10: Getting correct enemy health after attack1."
          << std::endl;
    }
    
    fighter.attack1(&enemy);
    if (enemy.get_Health() != 80 || enemy.get_Health() != 70) {
      std::cout
          << "Error in test 11 FIGHTER: Getting correct enemy health after attack2."
          << std::endl;
    }
  }

  void testInventory() {
    HealthPotion potion((std::string) "Potion");
    fighter.addToInventory(&potion);
    if (fighter.get_currInventorySize() != 1) {
      std::cout << "Error in test 12: Getting correct inventory size after add."
                << std::endl;
    }

    fighter.removeFromInventory(0);
    if (fighter.get_currInventorySize() != 0) {
      std::cout
          << "Error in test 13: Getting correct inventory size after remove."
          << std::endl;
    }
  }

 public:
  FighterTest() : fighter(), enemy("SomeSpritePath", 250, 250, 100, 100, 5) {
    std::cout << "Fighter created!" << std::endl;

    testEntityProperties();
    testCharacterProperties();
    testPlayerProperties();
    testMovement();
    testAttacks();
    testInventory();
  }
};

#endif