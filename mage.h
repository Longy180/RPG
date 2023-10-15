#ifndef MAGE_H
#define MAGE_H
#include "player.h"
#include "enemy.h"
#include <string>
class Mage : public Player{
private:

public:
Mage();
void cast(Enemy * opponent);
void summon(Enemy * opponent);
void meditate(); 
void takeDamage(int damage);
};
#endif