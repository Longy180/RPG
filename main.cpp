#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>

#include "character.h"
#include "collision.h"
#include "enemy.h"
#include "entity.h"
#include "map.h"
#include "player.h"
#include "ranger.h"
int main() {
  sf::RenderWindow window(sf::VideoMode(1300, 732), "Dog Thief");
  sf::Clock clock;
  sf::Time elapsedTime;
  sf::View view;
  window.setView(view);
  bool inCombat = false;
  Enemy* enemyInProximity = nullptr;
  sf::Sprite combatTextBox;
  bool mapOpen = true;

  // Set background
  sf::Texture backgroundTexture;
  backgroundTexture.loadFromFile("images/GameMap4.png");
  sf::Sprite background(backgroundTexture);
  background.setPosition(0, 0);

  // Create Player
  Ranger player1;

  // Create Enemy
  Enemy enemy1("Sprites/orc savage/OrcSavageIdleSide.gif", 1200, 280, 50, 50,
               5);
  Enemy enemy2("Sprites/orc savage/OrcSavageIdleSide.gif", 1700, 280, 50, 50,
               5);
  Enemy boss1("Sprites/orc juggernaut/OrcJuggernautIdleSide.gif", 650, 700, 50,
              50, 5);

  // Create Collisions
  Collision mapCollision;

  // Game loop
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      // Combat check and handling
      if (!inCombat) {
        // Check for proximity to an enemy
        if (enemy1.isInProximityToPlayer(player1.get_x(), player1.get_y(),
                                         player1.get_depth())) {
          enemyInProximity = &enemy1;
        } else if (enemy2.isInProximityToPlayer(
                       player1.get_x(), player1.get_y(), player1.get_depth())) {
          enemyInProximity = &enemy2;
        } else if (boss1.isInProximityToPlayer(player1.get_x(), player1.get_y(),
                                               player1.get_depth())) {
          enemyInProximity = &boss1;
        }

        // debug stuff
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
          inCombat = true;
        }

        if (enemyInProximity) {
          inCombat = true;
          // You can add combat initialization logic here
        }
      } else {
        // Handle combat logic here

        // Check for conditions to exit combat
        if (enemyInProximity == &boss1) {
          if (!boss1.isAlive()) {
            inCombat = false;
          }
        } else if (enemyInProximity == &enemy2) {
          if (!enemy2.isAlive()) {
            inCombat = false;
          }
        } else if (enemyInProximity == &enemy1) {
          if (!enemy1.isAlive()) {
            inCombat = false;
          }
        }
      }

      // Player movement (Only allowed when not in combat)
      if (!inCombat) {
        elapsedTime = clock.getElapsedTime();
        if (elapsedTime.asSeconds() > 0.1) {
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
              sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player1.move_left(12);
            std::cout << "Left" << std::endl;
            clock.restart();
          } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
                     sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player1.move_right(12);
            std::cout << "Right" << std::endl;
            clock.restart();
          } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
                     sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            player1.move_up(12);
            std::cout << "Up" << std::endl;
            clock.restart();
          } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
                     sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            player1.move_down(12);
            std::cout << "Down" << std::endl;
            clock.restart();
          }
          // Closes the map until pressed twice
        }
      }
    }

    // Update the view to follow the player
    view.setCenter(player1.get_EntityPosition());

    // Set the view's size to control the area visible on the screen
    view.setSize(sf::Vector2f(800, 450));

    // Apply the view to the window
    window.setView(view);

    // Clear and Draw window
    window.clear();
    window.draw(background);
    enemy1.draw(&window);
    enemy2.draw(&window);
    boss1.draw(&window);
    player1.draw(&window);
    mapCollision.drawRectangles(window);

    // Combat ui
    if (inCombat) {
      sf::Texture combatTexture;
      combatTexture.loadFromFile("images/Textbox.png");
      sf::Sprite combatTextBox(combatTexture);
      combatTextBox.setPosition(
          view.getCenter().x - combatTextBox.getGlobalBounds().width / 4,
          view.getCenter().y + 90);
      combatTextBox.setScale(0.5, 0.5);
      window.draw(combatTextBox);
    }

    window.display();
  }

  return 0;
}