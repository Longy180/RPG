#include "entity.h"
#include "character.h"
#include <SFML/Graphics.hpp>
Character::Character(std::string spriteLocation, int positionX, int positionY, int maxHealth, int currHealth, int damage) : Entity(spriteLocation, positionX, positionY){
    Character::maxHealth = maxHealth;
    Character::currHealth = currHealth;
    Character::damage = damage;
};

int Character::get_Health(){
return(currHealth);
}
void Character::set_Health(int health){
Character::currHealth = health;
}
int Character::get_maxHealth(){
return(maxHealth);
}
void Character::set_maxHealth(int maxHealth){
Character::maxHealth = maxHealth;
}
int Character::get_damage(){
return(damage);
}
void Character::set_damage(int damage){
    Character::damage = damage;
}