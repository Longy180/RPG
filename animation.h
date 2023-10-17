#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include <iostream>
#include <string>

#include "character.h"
#include "enemy.h"
#include "entity.h"
#include "player.h"

class Animation {
 protected:
  int selection;
  int lastMove;

 public:
  Animation();
  void bodyMoveLeft(Entity& entityBody);
  void bodyMoveRight(Entity& entityBody);
  int get_lastMove();
  void set_lastMove(int oneTwo);
  int get_charSelection();
  void set_charSelection(int _selection);
};

#endif