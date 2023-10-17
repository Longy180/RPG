#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <string>

#include "character.h"
#include "enemy.h"
#include "item.h"
class Player : public Character {
 protected:
  int currGold;
  int _depth;
  Item** inventory;
  int currInventorySize;
  int maxInventorySize;
  int healingCounter;

 public:
  Player(std::string spriteLocation, int positionX, int positionY,
         int maxHealth, int currHealth, int damage, int currGold);

  void move_down(float distance);
  void move_up(float distance);
  void move_left(float distance);
  void move_right(float distance);
  bool isHit(int t_x, int t_y, int t_depth);
  int get_depth();
  int get_Gold();
  void set_gold(int _gold);
  int get_currInventorySize();
  void add_Gold(int gold);
  virtual void attack1(Enemy* opponent);
  virtual void attack2(Enemy* opponent);
  virtual void heal();
  virtual void takeDamage(int damage);
  void addToInventory(Item* item);
  void removeFromInventory(int index);
  Item* getInventoryItem(int index);
  void draw(sf::RenderWindow* win);
  int get_healingCounter();
  void set_healingCounter(int _healingCounter);
  ~Player();
};

#endif