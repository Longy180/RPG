#ifndef MAGE_H
#define MAGE_H
#include "player.h"
#include "enemy.h"
#include <string>
class Mage : public Player{
private:

public:
Mage();
void attack1(Enemy * opponent);
void attack2(Enemy * opponent);
void heal(); 
void takeDamage(int damage);
};
#endif