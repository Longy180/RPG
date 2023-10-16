#include "ranger.h"
#include "player.h"
#include "enemy.h"

#include <iostream>
#include <string>
Ranger::Ranger() : Player((std::string)"Sprites/halfling ranger/HalflingRangerIdleSide.gif", 200, 200, 100, 100, 10, 0){

}

//stab
void Ranger::attack1(Enemy * opponent){
opponent->set_Health(opponent->get_Health() - Ranger::damage);
}

//volley
void Ranger::attack2(Enemy * opponent){
    if ((rand()%10 + 1) >= 4){
        opponent->set_Health(opponent->get_Health() - (Ranger::damage * 1.5));
    }else{
        std::cout << "Your volley missed\n";
    }
}
//survival skills
void Ranger::heal(){
    if(currHealth + 15 > maxHealth){
        currHealth = maxHealth;
    }else{
    currHealth += 15;   
    }
}
void Ranger::takeDamage(int damage){
currHealth = currHealth - damage;
}
Ranger::~Ranger(){

}