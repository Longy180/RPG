#ifndef FIGHTER_H
#define FIGHTER_H
#include "player.h"
#include "enemy.h"
#include <string>
class Fighter : public Player{
private:

public:
Fighter();
void attack1(Enemy * opponent);
void attack2(Enemy * opponent);
void heal(); 
void takeDamage(int damage);
~Fighter();
};
#endif