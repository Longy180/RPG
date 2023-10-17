#include "animation.h"

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

Animation::Animation() { selection = 0; }

void Animation::bodyMoveLeft(Entity& entityBody) {
  if (get_charSelection() == 1) {
    entityBody.set_entitySprite("Sprites/halfling rogue/fighterLeft1.png",
                                entityBody.get_x(), entityBody.get_y());
    set_lastMove(1);
  } else if (get_charSelection() == 2) {
    entityBody.set_entitySprite("Sprites/halfling assassin/assassinLeft1.png",
                                entityBody.get_x(), entityBody.get_y());
    set_lastMove(1);
  } else if (get_charSelection() == 3) {
    entityBody.set_entitySprite("Sprites/halfling ranger/rangerLeft1.png",
                                entityBody.get_x(), entityBody.get_y());
    set_lastMove(1);
  }
}

void Animation::bodyMoveRight(Entity& entityBody) {
  if (get_charSelection() == 1) {
    entityBody.set_entitySprite("Sprites/halfling rogue/fighterRight1.png",
                                entityBody.get_x(), entityBody.get_y());
    set_lastMove(2);
  } else if (get_charSelection() == 2) {
    entityBody.set_entitySprite("Sprites/halfling assassin/assassinRight1.png",
                                entityBody.get_x(), entityBody.get_y());
    set_lastMove(2);
  } else if (get_charSelection() == 3) {
    entityBody.set_entitySprite("Sprites/halfling ranger/rangerRight1.png",
                                entityBody.get_x(), entityBody.get_y());
    set_lastMove(2);
  }
}

int Animation::get_charSelection() { return selection; }

void Animation::set_charSelection(int _selection) {
  selection = _selection;
  std::cout << _selection << std::endl;
}

int Animation::get_lastMove() { return lastMove; }

void Animation::set_lastMove(int oneTwo) { lastMove = oneTwo; }