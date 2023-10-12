#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>

#include "enemy.h"
#include "map.h"
#include "player.h"
#include "character.h"
#include "entity.h"
int main() {
  sf::RenderWindow window(sf::VideoMode(1300, 732), "Dog Thief");
  sf::Clock clock;
  sf::Time elapsedTime;
  sf::View view;
  window.setView(view);

//Set background
  sf::Texture backgroundTexture;
  backgroundTexture.loadFromFile("images/GameMap.png");
  sf::Sprite background(backgroundTexture);
  background.setPosition(0, 0);

//Create Player
  std::string spriteLocation = "Sprites/halfling ranger/HalflingRangerIdleSide.gif";
  int startingX = 200, startingY =200;
  int maxHealth = 100, currHealth = 100, damage = 10, currGold = 0;
  Player player1(spriteLocation,startingX, startingY, maxHealth, currHealth, damage, currGold);

  //Create Enemy
  Enemy enemy1("Sprites/orc savage/OrcSavageIdleSide.gif", 1200, 280, 50, 50, 5);
  Enemy enemy2("Sprites/orc savage/OrcSavageIdleSide.gif", 1700, 280, 50, 50, 5);
  Enemy boss1("Sprites/orc juggernaut/OrcJuggernautIdleSide.gif", 650, 700, 50, 50, 5);
//Game loop
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }

//Player movement
      elapsedTime = clock.getElapsedTime();
      if (elapsedTime.asSeconds() > 0.1) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
          player1.move_left(12);
          std::cout << "Left" << std::endl;
          clock.restart();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
          player1.move_right(12);
          std::cout << "Right" << std::endl;
          clock.restart();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
          player1.move_up(12);
          std::cout << "Up" << std::endl;
          clock.restart();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
          player1.move_down(12);
          std::cout << "Down" << std::endl;
          clock.restart();
        }
      }
    }

  // Update the view to follow the player
  view.setCenter(player1.get_EntityPosition());

  // Set the view's size to control the area visible on the screen
  view.setSize(sf::Vector2f(800, 450)); 

  // Apply the view to the window
  window.setView(view);

  //Clear and Draw window
    window.clear();
    window.draw(background);
    enemy1.draw(&window);
    enemy2.draw(&window);
    boss1.draw(&window);
    player1.draw(&window);

    window.display();
  }

  return 0;
}