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
  rectangles[0].setPosition(0, 425);              // Set position as needed
  rectangles[1].setSize(sf::Vector2f(100, 25));
  rectangles[1].setPosition(1325, 425);
}

// To remove barrier between areas, to be added if enough time (would just
// delete the rectangle that sits in between a door) void
// Collision::removeCollision(){

// }

// This is for debugging to show where the hitboxes are
void Collision::drawRectangles(sf::RenderWindow& window) {
  for (int i = 0; i < 10; i++) {
    window.draw(rectangles[i]);
  }
}

// bool Collision::willHit(Entity& player) {
//   if ((player.get_x() + 12  || player.get_x() - 12 || player.get_y() + 12 ||
//        player.get_y() - 12)) {

//   }
// }

bool Collision::willHit(Entity& player) {
  sf::FloatRect playerBounds = player.get_EntitySprite().getGlobalBounds();

  for (int i = 0; i < 2; i++) {
    if (playerBounds.intersects(rectangles[i].getGlobalBounds())) {
      // There's a collision
      std::cout << "collision" << std::endl;
      return true;
    }
  }

  return false;  // No collision
}

// bool Collision::willHitDown(){
// if player1.get_x()  player1.get_y()
// }

// bool Collision::willHitLeft(){
// if player1.get_x()  player1.get_y()
// }

// bool Collision::willHitRight(){
// if player1.get_x()  player1.get_y()
// }