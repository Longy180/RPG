#ifndef RANGER_H
#define RANGER_H
#include "player.h"
#include "enemy.h"
#include <string>
class Ranger : public Player{
private:

public:
Ranger();
void attack1(Enemy * opponent);
void attack2(Enemy * opponent);
virtual void heal(); 
virtual void takeDamage(int damage);
~Ranger();
};
#endif