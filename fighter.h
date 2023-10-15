#ifndef FIGHTER_H
#define FIGHTER_H
#include "player.h"
#include "enemy.h"
#include <string>
class Fighter : public Player{
private:

public:
Fighter();
void tackle(Enemy * opponent);
void takeDown(Enemy * opponent);
void recover(); 
void takeDamage(int damage);
};
#endif