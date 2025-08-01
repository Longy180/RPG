#include "fighter.h"

#include <iostream>
#include <string>

#include "player.h"
Fighter::Fighter()
    : Player((std::string) "Sprites/halfling rogue/HalflingRogueIdleSide.gif",
             200, 200, 100, 100, 10, 0) {}

// tackle
void Fighter::attack1(Enemy* opponent) {
  opponent->set_Health(opponent->get_Health() - Fighter::damage);
};

// takedown
void Fighter::attack2(Enemy* opponent) {
  if ((rand() % 10 + 1) >= 7) {
    opponent->set_Health(opponent->get_Health() - (Fighter::damage * 2));
  } else {
    std::cout << "You missed\n";
  }
};

// recover
void Fighter::heal() {
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

void Fighter::takeDamage(int damage) { currHealth = currHealth - damage; }

Fighter::~Fighter() {}