#ifndef ENEMY_H
#define ENEMY_H
#include <time.h>

#include <SFML/Graphics.hpp>
#include <cmath>
#include <random>

#include "entity.h"

class Enemy : public Entity {
 private:
  sf::RectangleShape* body;
  bool alive;
  int _depth;

 public:
  Enemy(std::string spriteLocation, int positionX, int positionY);

  int get_x();
  int get_y();
  int get_depth();
  bool isAlive();
  void die();
  void spawn(int x, int y);

  bool isHit(int target_x, int target_y, int target_depth);

  void draw(sf::RenderWindow* win);

  ~Enemy();
};

#endif