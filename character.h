#ifndef CHARACTER_H
#define CHARACTER_H
#include "entity.h"
#include <SFML/Graphics.hpp>
class Character : public Entity {
 protected:
 int maxHealth;
 int currHealth;
 int damage;
 public:
  Character(std::string spriteLocation, int positionX, int positionY, int maxHealth, int currHealth, int damage);
 int get_Health();
 void set_Health(int health);
 int get_maxHealth();
 void set_maxHealth(int maxHealth);
 int get_damage();
 void set_damage(int damage);

};

#endif