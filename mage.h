#ifndef MAGE_H
#define MAGE_H
#include <string>

#include "enemy.h"
#include "player.h"
class Mage : public Player {
 private:
 public:
  Mage();
  void attack1(Enemy* opponent);
  void attack2(Enemy* opponent);
  void heal();
  void takeDamage(int damage);
  ~Mage();
};
#endif