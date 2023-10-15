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
void heal(); 
void takeDamage(int damage);
};
#endif