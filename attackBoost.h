#ifndef ATTACKBOOST_H
#define ATTACKBOOST_H
#include "item.h"
#include "player.h"
class AttackBoost : public Item {
 private:
  int damageIncrease;

 public:
  // constructors
  AttackBoost();
  AttackBoost(std::string name);
  // Returns damage increase variable
  int get_damageIncrease();
  // Adds damage boost to target player
  void itemEffect(Player* player);
};
#endif