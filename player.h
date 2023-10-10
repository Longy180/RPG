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

  void move_right(sf::Texture& player, sf::Sprite& playerBody, float distance);
  void move_left(sf::Texture& player, sf::Sprite& playerBody, float distance);
  void move_up(sf::Texture& player, sf::Sprite& playerBody, float distance);
  void move_down(sf::Texture& player, sf::Sprite& playerBody, float distance);

  bool isHit(int t_x, int t_y, int t_depth);

  ~Player();
};

#endif