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
  sf::RenderWindow window(sf::VideoMode(1300, 732), "Game_Name");

  sf::Texture backgroundTexture;
  backgroundTexture.loadFromFile("images/map.jpeg");
  sf::Sprite background(backgroundTexture);
  background.setPosition(0, 0);

    Player player1;

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        player1.move_left(6);
      } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        player1.move_right(6);
      } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        player1.move_up(6);
      } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        player1.move_down(6);
      }
    }

    window.clear();
    window.draw(background);
    player1.draw(&window);
    window.display();
  }

  return 0;
}

// while (win->isOpen()) {
//   sf::Event e;
//   while (win->pollEvent(e)) {
//     if (e.type == sf::Event::Closed) {
//       win->close();
//     }
//   }
//   win->clear();
//   check_score();
//   if (_score < 0) {
//     break;
//   }
//   map->draw(win);
//   player->draw(win);
//   for (int i = 0; i < _army_size; i++) {
//     enemy[i].draw(win);
//   }
//   std::string msg;
//   msg = "Score: " + std::to_string(_score) + " ";
//   info.setString(msg);
//   win->draw(info);
//   win->display();
// }