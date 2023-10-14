#include "enemy.h"

#include <time.h>

#include <SFML/Graphics.hpp>
#include <cmath>
#include <random>
#include <iostream>
#include "entity.h"
#include"character.h"

Enemy::Enemy(std::string spriteLocation, int positionX, int positionY, int maxHealth, int currHealth, int damage)
: Character(spriteLocation, positionX, positionY, maxHealth, currHealth, damage) {
  _depth = 100;
  
  alive = true;
}
int Enemy::get_x() { return entitySprite.getPosition().x; }
int Enemy::get_y() { return entitySprite.getPosition().y; }
int Enemy::get_depth() { return _depth; }
bool Enemy::isAlive() { return alive; }
void Enemy::die() { alive = false; }

bool Enemy::isInProximityToPlayer(int target_x, int target_y, int target_depth) {
  bool hit = false;
  int x = get_x();
  int y = get_y();
  float dist_between =
      sqrt((x - target_x) * (x - target_x) + (y - target_y) * (y - target_y));
  if (dist_between < (100)) {
    hit = true;
  }

  std::cout << "Player x: " << target_x << "  Player y: " << target_y << "  Distance between: " << dist_between << "  Random greater than num: " << (100) << "\n";
  return hit;
}

void Enemy::draw(sf::RenderWindow* win){ 
  win->draw(entitySprite); 
  }

Enemy::~Enemy() { delete this->body; }