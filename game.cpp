#include <enemy.h>
#include <map.h>
#include <player.h>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>

Game::Game(int size, std::string title, int num_spells, int army_size) {
  player = new Player(10, 250, 250, num_spells);
  enemy = new Enemy[army_size];
  this->_army_size = army_size;
  this->_num_spells = num_spells;
  _score = 0;
  if (!font.loadFromFile("Fonts/VideoGame_Font.ttf")) {
    std::cout << "Font not Found\n";
    exit(0);
  }
  info.setFont(font);
  info.setFillColor(sf::Color::White);
  info.setCharacterSize(20);
}

void Game::check_score() {
  for (int i = 0; i < _army_size; i++) {
    if (enemy[i].isAlive()) {
      if (enemy[i].isHit(player->get_x(), player->get_y(),
                         player->get_depth())) {
        _score--;
        enemy[i].die();
        enemy[i].spawn(win->getSize().x - 10, win->getSize().y);
      }
      if (player->isHit(enemy[i].get_x(), enemy[i].get_y(),
                        enemy[i].get_depth())) {
        _score++;
        enemy[i].die();
        enemy[i].spawn(win->getSize().x - 10, win->getSize().y);
      }
    }
  }
}

void Game::run() {
  while (win->isOpen()) {
    sf::Event e;
    while (win->pollEvent(e)) {
      if (e.type == sf::Event::Closed) {
        win->close();
      }
      if (Keyboard::isKeyPressed(Keyboard::A)) {
        map->move_left(6);
      } else if (Keyboard::isKeyPressed(Keyboard::D)) {
        map->move_right(6);
      } else if (Keyboard::isKeyPressed(Keyboard::W)) {
        map->move_up(6);
      } else if (Keyboard::isKeyPressed(Keyboard::S)) {
        map->move_down(6);
      }

      if (Keyboard::isKeyPressed(Keyboard::E)) {
        for (int i = 0; i < _army_size; i++) {
          enemy[i].spawn(win->getSize().x - 10, win->getSize().y);
        }
      }
    }
    win->clear();
    check_score();
    if (_score < 0) {
      break;
    }
    map->draw(win);
    player->draw(win);
    for (int i = 0; i < _army_size; i++) {
      enemy[i].draw(win);
    }
    std::string msg;
    msg = "Score: " + std::to_string(_score) + " ";
    info.setString(msg);
    win->draw(info);
    win->display();
  }
}
~Game::Game() {
  delete this->win;
  delete this->player;
  delete[] this->enemy;
}