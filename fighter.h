#ifndef FIGHTER_H
#define FIGHTER_H
#include "player.h"
#include "enemy.h"
#include <string>
class Fighter : public Player{
private:

public:
Fighter();
virtual void attack1(Enemy * opponent);
virtual void attack2(Enemy * opponent);
virtual void heal(); 
virtual void takeDamage(int damage);
~Fighter();
};
#endif