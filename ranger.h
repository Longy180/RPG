#ifndef RANGER_H
#define RANGER_H
#include "player.h"
#include "enemy.h"
#include <string>
class Ranger : public Player{
private:

public:
Ranger();
void stab(Enemy * opponent);
void volley(Enemy * opponent);
void survivalSkills(); 
void takeDamage(int damage);
};
#endif