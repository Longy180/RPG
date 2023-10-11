#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include "spell.h"
#include <SFML/Graphics.hpp>

class Player {
 protected:
  sf::Texture* playerBody;
  int _depth;
  sf::Sprite playerSprite;
  float dampingFactor;

 public:
  Player();
  void draw(sf::RenderWindow* win);

  int get_x();
  int get_y();
  sf::Sprite get_playerSprite();
  sf::Vector2f get_PlayerPosition();
  void move_down(float distance);
  void move_up(float distance);
  void move_left(float distance);
  void move_right(float distance);
  bool isHit(int t_x, int t_y, int t_depth);

  ~Player();
};

#endif