#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <SFML/Graphics.hpp>
#include "character.h"
class Player : public Character{
 protected:
  int currGold;
  //Inventory, will need to be added to initialiser
 public:
  Player(std::string spriteLocation, int positionX, int positionY, int maxHealth, int currHealth, int damage, int currGold);
  

  void move_down(float distance);
  void move_up(float distance);
  void move_left(float distance);
  void move_right(float distance);
  bool isHit(int t_x, int t_y, int t_depth);

  void draw(sf::RenderWindow* win) override;
  ~Player();
};

#endif