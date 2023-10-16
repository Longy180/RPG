// Game.h
#ifndef GAME_H
#define GAME_H
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
#include "fighter.h"
#include "item.h"
#include "mage.h"
#include "map.h"
#include "player.h"
#include "ranger.h"

class Game {
 public:
  Game();          // Constructor
  void runGame();  // Function to run the game
                   // Add other public member functions here

 private:
  sf::RenderWindow window;
  sf::Text text;
  sf::Text combatText;
  sf::Font font;
  Player player1;
  int playerClass;
  bool validChoice;
  int moveChosen;
  sf::Clock clock;
  sf::Time elapsedTime;
  sf::View view;
  Enemy* enemyInProximity;
  bool inCombat;
  sf::Sprite combatTextBox;
  bool mapOpen;
  Enemy enemy1;
  Enemy enemy2;
  Enemy boss1;
  Collision mapCollision;
  sf::Sprite background;
  bool playerTurn;
  sf::Texture backgroundTexture;
  // Declare other member variables here

  void handleEvents();
  void update();
  void render();
  void chooseClass();
  // Add other private member functions here
};

#endif  // GAME_H
