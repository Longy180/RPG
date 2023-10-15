#include "mage.h"
#include "player.h"
#include <string>
#include <iostream>
Mage::Mage() : Player((std::string)"Sprites/halfling ranger/HalflingRangerIdleSide.gif", 200, 200, 100, 100, 10, 0){

}

void Mage::cast(Enemy * opponent){
opponent->set_Health(opponent->get_Health() - Mage::damage);
}

void Mage::summon(Enemy * opponent){
if ((rand()%10 + 1) >= 2){
        opponent->set_Health(opponent->get_Health() - (Mage::damage * 1.5));
    }else{
        std::cout << "Your summon failed\n";
    }
}

void Mage::meditate(){
if(currHealth + 5 > maxHealth){
        currHealth = maxHealth;
    }else{
    currHealth += 5;   
    }
}

void Mage::takeDamage(int damage){
currHealth = currHealth - damage;
}
