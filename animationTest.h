#ifndef ANIMATIONTEST_H
#define ANIMATIONTEST_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include <iostream>
#include <string>

#include "animation.h"
#include "character.h"
#include "enemy.h"
#include "entity.h"
#include "player.h"

class AnimationTest {
 private:
  void testBodyMoveLeft(Entity& entityBody) {
    Animation animation;
    animation.set_charSelection(1);
    animation.bodyMoveLeft(entityBody);
    if (!animation.get_lastMove() == 1) {
      std::cout << "Error in test 1." << std::endl;
    }
  }

  void testBodyMoveRight(Entity& entityBody) {
    Animation animation;
    animation.set_charSelection(1);
    animation.bodyMoveRight(entityBody);
    if (!animation.get_lastMove() == 2) {
      std::cout << "Error in test 2." << std::endl;
    }
  }

  void testGetLastMove() {
    Animation animation;
    animation.set_lastMove(1);
    if (!animation.get_lastMove() == 1) {
      std::cout << "Error in test 3." << std::endl;
    }
  }

  void testSetLastMove() {
    Animation animation;
    animation.set_lastMove(2);
    if (!animation.get_lastMove() == 2) {
      std::cout << "Error in test 4." << std::endl;
    }
  }

  void testGetCharSelection() {
    Animation animation;
    animation.set_charSelection(3);
    if (!animation.get_charSelection() == 3) {
      std::cout << "Error in test 5." << std::endl;
    }
  }

  void testSetCharSelection() {
    Animation animation;
    animation.set_charSelection(2);
    if (!animation.get_charSelection() == 2) {
      std::cout << "Error in test 6." << std::endl;
    }
  }

 public:
  AnimationTest() {
    testGetLastMove();
    testSetLastMove();
    testGetCharSelection();
    testSetCharSelection();
  }
};

#endif