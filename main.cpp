#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>

// #include "enemy.h"
#include "map.h"
#include "player.h"

int main() {
  sf::RenderWindow window(sf::VideoMode(1300, 732), "They stole your dog.");
  sf::Clock clock;
  sf::Time elapsedTime;

  sf::Texture backgroundTexture;
  backgroundTexture.loadFromFile("images/mapfile.png");
  sf::Sprite background(backgroundTexture);
  background.setPosition(0, 0);

  Player player1;

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      elapsedTime = clock.getElapsedTime();
      if (elapsedTime.asSeconds() > 0.25) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
          player1.move_left(6);
          std::cout << "Left" << std::endl;
          clock.restart();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
          player1.move_right(6);
          std::cout << "Right" << std::endl;
          clock.restart();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
          player1.move_up(6);
          std::cout << "Up" << std::endl;
          clock.restart();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
          player1.move_down(6);
          std::cout << "Down" << std::endl;
          clock.restart();
        }
      }
    }

    window.clear();
    window.draw(background);
    player1.draw(&window);

    window.display();
  }

  return 0;
}