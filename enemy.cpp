#include "enemy.h"

#include <time.h>

#include <SFML/Graphics.hpp>
#include <cmath>
#include <random>

#include "entity.h"

Enemy::Enemy(std::string spriteLocation, int positionX, int positionY) {
  _depth = 10;
  body = new sf::RectangleShape(sf::Vector2f(_depth, _depth));
  body->setFillColor(sf::Color::Cyan);
  body->setPosition(-1, -1);
  body->setOrigin(_depth / 2, _depth / 2);
  alive = false;
  srand(time(0));
}
int Enemy::get_x() { return body->getPosition().x; }
int Enemy::get_y() { return body->getPosition().y; }
int Enemy::get_depth() { return _depth; }
bool Enemy::isAlive() { return alive; }
void Enemy::die() { alive = false; }
void Enemy::spawn(int x, int y) {
  int rand_y = rand() % y + 1;
  body->setPosition(x, rand_y);
  this->alive = true;
}

bool Enemy::isHit(int target_x, int target_y, int target_depth) {
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

void Enemy::draw(sf::RenderWindow* win) {
  if (this->alive) {
    body->move(-0.01, 0);
    win->draw(*body);
    if (body->getPosition().x < 0) {
      this->spawn(win->getSize().x - 10, win->getSize().y);
    }
  }
}

Enemy::~Enemy() { delete this->body; }