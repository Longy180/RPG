#ifndef GAME_H
#define GAME_H
#include <enemy.h>
#include <map.h>
#include <player.h>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Game {
 private:
  sf::RenderWindow* win;
  Player* player;
  Enemy* enemy;
  int _army_size;
  int _num_spells;
  int _score;
  sf::Text info;
  sf::Font font;
  Map* map;

 public:
  Game(int size, std::string title, int num_spells, int army_size);
  void check_score();
  void run();
  ~Game();
};

#endif
