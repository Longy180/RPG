#include "attackBoost.h"

#include "player.h"
// constructors
AttackBoost::AttackBoost() : Item("", 10, 5) { damageIncrease = 3; }
AttackBoost::AttackBoost(std::string name) : Item(name, 10, 5) {
  damageIncrease = 3;
}

// Returns damage increase variable
int AttackBoost::get_damageIncrease() { return (damageIncrease); }

// Adds damage boost to target player
void AttackBoost::itemEffect(Player* player) {
  player->set_damage(get_damageIncrease() + player->get_damage());
}
