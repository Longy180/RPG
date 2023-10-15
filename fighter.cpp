#include "fighter.h"
#include "player.h"
#include <string>
#include <iostream>
Fighter::Fighter() : Player((std::string)"Sprites/halfling ranger/HalflingRangerIdleSide.gif", 200, 200, 100, 100, 10, 0){
}

void Fighter::tackle(Enemy * opponent){
opponent->set_Health(opponent->get_Health() - Fighter::damage);
};
void Fighter::takeDown(Enemy * opponent){
if ((rand()%10 + 1) >= 7){
        opponent->set_Health(opponent->get_Health() - (Fighter::damage * 2));
    }else{
        std::cout << "You missed\n";
    }
};
void Fighter::recover(){
    if(currHealth + 5> maxHealth){
        currHealth = maxHealth;
    }else{
    currHealth += 5;   
    }
};

void Fighter::takeDamage(int damage){
currHealth = currHealth - damage;
}
