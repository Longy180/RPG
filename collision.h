#ifndef COLLISION_H
#define COLLISION_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>

#include "player.h"

class Collision {
 private:
  // Array of collision rectangles
  sf::RectangleShape rectangles[35];

 public:
  // Constructor
  Collision();
  // Checks if player is about to move into wall
  bool willHit(Entity& player);
  // For debugging collision
  void drawRectangles(sf::RenderWindow& window);
};

#endif