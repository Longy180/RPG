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
    sf::RectangleShape rectangles[10];

  public:
    Collision();
    // void removeCollision();
    bool willHit(Player& player);
    void drawRectangles(sf::RenderWindow& window);
};

#endif
