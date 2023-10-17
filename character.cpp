#include "character.h"

#include <SFML/Graphics.hpp>

#include "entity.h"

// Constructor
Character::Character(std::string spriteLocation, int positionX, int positionY,
                     int maxHealth, int currHealth, int damage)
    : Entity(spriteLocation, positionX, positionY) {
  Character::maxHealth = maxHealth;
  Character::currHealth = currHealth;
  Character::damage = damage;
};

// Returns current character health
int Character::get_Health() { return (currHealth); }
// Sets current character health
void Character::set_Health(int health) { Character::currHealth = health; }
// Returns characters max health
int Character::get_maxHealth() { return (maxHealth); }
// Sets characters max health
void Character::set_maxHealth(int maxHealth) {
  Character::maxHealth = maxHealth;
}
// Returns character damage
int Character::get_damage() { return (damage); }
// Sets characters damage
void Character::set_damage(int damage) { Character::damage = damage; }