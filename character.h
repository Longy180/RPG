#ifndef CHARACTER_H
#define CHARACTER_H
#include <SFML/Graphics.hpp>

#include "entity.h"
class Character : public Entity {
 protected:
  int maxHealth;
  int currHealth;
  int damage;

 public:
  // Constructor
  Character(std::string spriteLocation, int positionX, int positionY,
            int maxHealth, int currHealth, int damage);
  // Returns current character health
  int get_Health();
  // Sets current character health
  void set_Health(int health);
  // Returns characters max health
  int get_maxHealth();
  // Sets characters max health
  void set_maxHealth(int maxHealth);
  // Returns character damage
  int get_damage();
  // Sets characters damage
  void set_damage(int damage);
};

#endif