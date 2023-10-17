#include "mage.h"

#include <iostream>
#include <string>

#include "player.h"
Mage::Mage()
    : Player(
          (std::
               string) "Sprites/halfling assassin/HalflingAssassinIdleSide.gif",
          200, 200, 100, 100, 10, 0) {}

// Cast Fireball
void Mage::attack1(Enemy* opponent) {
  opponent->set_Health(opponent->get_Health() - Mage::damage);
}

// Summon Lightning
void Mage::attack2(Enemy* opponent) {
  if ((rand() % 10 + 1) >= 2) {
    opponent->set_Health(opponent->get_Health() - (Mage::damage * 1.5));
  } else {
    std::cout << "Your summon failed\n";
  }
}

// meditate
void Mage::heal() {
    if (currHealth + 5 > maxHealth) {
        if (healingCounter <= 4) {
            currHealth = maxHealth;
            healingCounter++;
        }
    } else {
        if (healingCounter <= 4) {
            currHealth += 5;
            healingCounter++;
        }
    }
}

void Mage::takeDamage(int damage) { currHealth = currHealth - damage; }

Mage::~Mage(){

};