#include "healthBoost.h"

#include "player.h"
HealthBoost::HealthBoost() : Item(" ", 10, 5) { healthIncrease = 25; }
HealthBoost::HealthBoost(std::string name) : Item(name, 10, 5) {
  healthIncrease = 25;
}
int HealthBoost::get_healthIncrease() { return (healthIncrease); }

void HealthBoost::itemEffect(Player* player) {
  if (player->get_Health() == player->get_maxHealth()) {
    player->set_maxHealth(get_healthIncrease() + player->get_maxHealth());
    player->set_Health(player->get_maxHealth());
  } else {
    player->set_maxHealth(get_healthIncrease() + player->get_maxHealth());
  }
}
