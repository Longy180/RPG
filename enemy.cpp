#include "enemy.h"

#include <time.h>

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <random>

#include "character.h"
#include "entity.h"

// Constructor

Enemy::Enemy(std::string spriteLocation, int positionX, int positionY,
             int maxHealth, int currHealth, int damage)
    : Character(spriteLocation, positionX, positionY, maxHealth, currHealth,
                damage) {
  _depth = 100;

  alive = true;
}
// Returns enemy's x coordinate
int Enemy::get_x() { return entitySprite.getPosition().x; }
// Returns enemy's y coordinate
int Enemy::get_y() { return entitySprite.getPosition().y; }
// Returns hitbox depth of enemy
int Enemy::get_depth() { return _depth; }
// Returns true if enemy is alive
bool Enemy::isAlive() { return alive; }
// Sets alive boolean to false
void Enemy::die() { alive = false; }

// Sets alive to true, and allocates full health
void Enemy::revive() {
  alive = true;
  currHealth = maxHealth;
}

// Checks if player is within enemy combat range
bool Enemy::isInProximityToPlayer(int target_x, int target_y,
                                  int target_depth) {
  bool hit = false;
  int x = get_x();
  int y = get_y();
  float dist_between =
      sqrt((x - target_x) * (x - target_x) + (y - target_y) * (y - target_y));
  if (dist_between < (_depth + target_depth)) {
    hit = true;
  }
  return hit;
}

// Draws enemy to window
void Enemy::draw(sf::RenderWindow* win) { win->draw(entitySprite); }

// Deconstructor
Enemy::~Enemy() {}