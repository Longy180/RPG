#ifndef ENEMY_H
#define ENEMY_H
#include <time.h>

#include <SFML/Graphics.hpp>
#include <cmath>
#include <random>

#include "character.h"
#include "entity.h"

class Enemy : public Character {
 private:
  sf::RectangleShape* body;
  bool alive;
  int _depth;

 public:
  // Constructor
  Enemy(std::string spriteLocation, int positionX, int positionY, int maxHealth,
        int currHealth, int damage);

  // Returns enemy's x coordinate
  int get_x();
  // Returns enemy's y coordinate
  int get_y();
  // Returns hitbox depth of enemy
  int get_depth();
  // Returns true if enemy is alive
  bool isAlive();
  // Sets alive boolean to false
  void die();
  
  // Sets health to full and sets alive to true, used in load / save
  void revive();

  // Checks if player is within enemy combat range

  bool isInProximityToPlayer(int target_x, int target_y, int target_depth);
  // Draws enemy to window
  void draw(sf::RenderWindow* win);
  // Deconstructor
  ~Enemy();
};

#endif