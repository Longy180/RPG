#ifndef RANGERTEST_H
#define RANGERTEST_H
#include <iostream>
#include <string>

#include "enemy.h"
#include "ranger.h"

class RangerTest {
 private:
  Ranger ranger;
  Enemy enemy;

  void testEntityProperties() {
    if (ranger.get_x() != 200) {
      std::cout << "Error in test 1: Getting ranger x." << std::endl;
    }
    if (ranger.get_y() != 200) {
      std::cout << "Error in test 2: Getting ranger y." << std::endl;
    }
  }

  void testCharacterProperties() {
    if (ranger.get_Health() != 100) {
      std::cout << "Error in test 3: Getting ranger health." << std::endl;
    }
    if (ranger.get_maxHealth() != 100) {
      std::cout << "Error in test 4: Getting ranger maxHealth." << std::endl;
    }
    if (ranger.get_damage() != 10) {
      std::cout << "Error in test 5: Getting ranger damage." << std::endl;
    }
  }

  void testPlayerProperties() {
    if (ranger.get_Gold() != 0) {
      std::cout << "Error in test 6: Getting ranger gold." << std::endl;
    }
  }

  void testMovement() {
    ranger.move_right(10);
    if (ranger.get_x() != 210) {
      std::cout << "Error in test 7: Getting ranger x after move right."
                << std::endl;
    }

    ranger.move_left(5);
    if (ranger.get_x() != 205) {
      std::cout << "Error in test 8: Getting ranger x after move left."
                << std::endl;
    }
  }

  void testAttacks() {
    if (enemy.get_Health() != 100) {
      std::cout << "Error in test 9: Getting correct enemy health before fight."
                << std::endl;
    }

    ranger.attack1(&enemy);
    if (enemy.get_Health() != 90) {
      std::cout
          << "Error in test 10: Getting correct enemy health after attack1."
          << std::endl;
    }

    ranger.attack2(&enemy);
    if (enemy.get_Health() != 90 || enemy.get_Health() != 70) {
      std::cout
          << "Error in test 11 RANGER: Getting correct enemy health after attack2."
          << std::endl;
    }
  }

  void testInventory() {
    HealthPotion potion((std::string) "Potion");
    ranger.addToInventory(&potion);
    if (ranger.get_currInventorySize() != 1) {
      std::cout << "Error in test 12: Getting correct inventory size after add."
                << std::endl;
    }

    ranger.removeFromInventory(0);
    if (ranger.get_currInventorySize() != 0) {
      std::cout
          << "Error in test 13: Getting correct inventory size after remove."
          << std::endl;
    }
  }

  void testHealing() {
    ranger.set_Health(40);
    ranger.heal();
    if (ranger.get_Health() != 55) {
      std::cout << "Error in test 14: Getting correct health after healing."
                << std::endl;
    }
  }

 public:
  RangerTest() : ranger(), enemy("SomeSpritePath", 250, 250, 100, 100, 5) {
    std::cout << "Ranger created!" << std::endl;

    testEntityProperties();
    testCharacterProperties();
    testPlayerProperties();
    testAttacks();
    testHealing();
  }
};

#endif