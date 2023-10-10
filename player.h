#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include "spell.h"

class Player {
 protected:
  sf::Texture* playerBody;
  int _depth;

 public:
  Player();
  void draw(sf::RenderWindow* win);

  int get_x();
  int get_y();
  sf::Texture* get_playerBody();
  sf::Vector2f get_PlayerPosition();
  void movePlayer(char key);
  bool isHit(int t_x, int t_y, int t_depth);

  ~Player();
};

#endif