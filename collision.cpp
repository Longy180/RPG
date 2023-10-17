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
  rectangles[0].setSize(sf::Vector2f(1235, 25));  // Set size of rectangle
  rectangles[0].setPosition(25, 425);  // Set position of the rectangle
  rectangles[1].setSize(sf::Vector2f(400, 105));
  rectangles[1].setPosition(1340, 425);
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
  rectangles[10].setSize(sf::Vector2f(40, 125));
  rectangles[10].setPosition(960, 150);
  rectangles[11].setSize(sf::Vector2f(40, 150));
  rectangles[11].setPosition(960, 150);
  rectangles[12].setSize(sf::Vector2f(40, 150));
  rectangles[12].setPosition(960, 150);
  rectangles[13].setSize(sf::Vector2f(50, 25));
  rectangles[13].setPosition(1800, 425);
  rectangles[14].setSize(sf::Vector2f(50, 25));
  rectangles[14].setPosition(1800, 500);
  rectangles[15].setSize(sf::Vector2f(200, 25));
  rectangles[15].setPosition(1050, 500);
  rectangles[16].setSize(sf::Vector2f(220, 290));
  rectangles[16].setPosition(900, 500);
  rectangles[17].setSize(sf::Vector2f(1000, 140));
  rectangles[17].setPosition(900, 650);
  rectangles[18].setSize(sf::Vector2f(75, 75));
  rectangles[18].setPosition(1800, 425);
  rectangles[19].setSize(sf::Vector2f(60, 350));
  rectangles[19].setPosition(1850, 350);
  rectangles[20].setSize(sf::Vector2f(125, 100));
  rectangles[20].setPosition(1850, 150);
  rectangles[21].setSize(sf::Vector2f(90, 305));
  rectangles[21].setPosition(1385, 150);
  rectangles[22].setSize(sf::Vector2f(1150, 75));
  rectangles[22].setPosition(950, 100);
  rectangles[23].setSize(sf::Vector2f(100, 25));
  rectangles[23].setPosition(1850, 250);
  rectangles[24].setSize(sf::Vector2f(90, 50));
  rectangles[24].setPosition(510, 200);
  rectangles[25].setSize(sf::Vector2f(90, 50));
  rectangles[25].setPosition(680, 200);
  rectangles[26].setSize(sf::Vector2f(25, 170));
  rectangles[26].setPosition(730, 30);
  rectangles[27].setSize(sf::Vector2f(25, 170));
  rectangles[27].setPosition(510, 30);
  rectangles[28].setSize(sf::Vector2f(325, 25));
  rectangles[28].setPosition(510, 30);
  rectangles[29].setSize(sf::Vector2f(25, 530));
  rectangles[29].setPosition(1995, 260);
  rectangles[30].setSize(sf::Vector2f(25, 200));
  rectangles[30].setPosition(2020, 770);
  rectangles[31].setSize(sf::Vector2f(1550, 25));
  rectangles[31].setPosition(450, 920);
  rectangles[32].setSize(sf::Vector2f(500, 25));
  rectangles[32].setPosition(450, 500);
  rectangles[33].setSize(sf::Vector2f(40, 500));
  rectangles[33].setPosition(450, 500);
  rectangles[34].setSize(sf::Vector2f(70, 50));
  rectangles[34].setPosition(1184, 450);
}

// This is for debugging to show where the hitboxes are
void Collision::drawRectangles(sf::RenderWindow& window) {
  for (int i = 0; i < 35; i++) {
    window.draw(rectangles[i]);
  }
}

// Checks if player is about to move into wall
bool Collision::willHit(Entity& player) {
  sf::FloatRect playerBounds = player.get_EntitySprite().getGlobalBounds();

  for (int i = 0; i < 35; i++) {
    if (playerBounds.intersects(rectangles[i].getGlobalBounds())) {
      // There's a collision
      std::cout << "collision" << std::endl;
      return true;
    }
  }

  return false;  // No collision
}