#include "collision.h"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>

#include "character.h"
#include "player.h"

// Constructor that creates all border collisions
Collision::Collision() {
  rectangles[0].setSize(sf::Vector2f(1275, 25));  // Set size of rectangle
  rectangles[0].setPosition(25, 425);              // Set position of the rectangle
  rectangles[1].setSize(sf::Vector2f(90, 25));
  rectangles[1].setPosition(1325, 425);
  rectangles[2].setSize(sf::Vector2f(25, 400));
  rectangles[2].setPosition(0, 0);
  rectangles[3].setSize(sf::Vector2f(90, 25));
  rectangles[3].setPosition(0, 150);
  rectangles[4].setSize(sf::Vector2f(250, 25));
  rectangles[4].setPosition(190, 150);
  rectangles[5].setSize(sf::Vector2f(25, 70));
  rectangles[5].setPosition(275, 170);
  rectangles[6].setSize(sf::Vector2f(450, 30));
  rectangles[6].setPosition(0, 0);
  rectangles[7].setSize(sf::Vector2f(25, 290));
  rectangles[7].setPosition(430, 0);
  rectangles[8].setSize(sf::Vector2f(170, 25));
  rectangles[8].setPosition(430, 270);
  rectangles[9].setSize(sf::Vector2f(280, 25));
  rectangles[9].setPosition(680, 270);
  rectangles[10].setSize(sf::Vector2f(40, 150));
  rectangles[10].setPosition(960, 150);
  rectangles[10].setSize(sf::Vector2f(40, 150));
  rectangles[10].setPosition(960, 150);
}

// This is for debugging to show where the hitboxes are
void Collision::drawRectangles(sf::RenderWindow& window) {
  for (int i = 0; i < 20; i++) {
    window.draw(rectangles[i]);
  }
}

bool Collision::willHit(Entity& player) {
  sf::FloatRect playerBounds = player.get_EntitySprite().getGlobalBounds();

  for (int i = 0; i < 20; i++) {
    if (playerBounds.intersects(rectangles[i].getGlobalBounds())) {
      // There's a collision
      std::cout << "collision" << std::endl;
      return true;
    }
  }

  return false;  // No collision
}

// To remove barrier between areas, to be added if enough time (would just
// delete the rectangle that sits in between a door) void
// Collision::removeCollision(){