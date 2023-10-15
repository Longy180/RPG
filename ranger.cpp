#include "ranger.h"
#include "player.h"
#include "enemy.h"

#include <iostream>
#include <string>
Ranger::Ranger() : Player((std::string)"Sprites/halfling ranger/HalflingRangerIdleSide.gif", 200, 200, 100, 100, 10, 0){

}

void Ranger::stab(Enemy * opponent){
opponent->set_Health(opponent->get_Health() - Ranger::damage);
}

void Ranger::volley(Enemy * opponent){
    if ((rand()%10 + 1) >= 4){
        opponent->set_Health(opponent->get_Health() - (Ranger::damage * 1.5));
    }else{
        std::cout << "Your volley missed\n";
    }
}

void Ranger::survivalSkills(){
    if(currHealth + 15 > maxHealth){
        currHealth = maxHealth;
    }else{
    currHealth += 15;   
    }
}

void Ranger::takeDamage(int damage){
currHealth = currHealth - damage;
}
