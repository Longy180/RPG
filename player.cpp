#include "player.h"

#include <SFML/Graphics.hpp>
#include <iostream>

//Constructor, sets default player sprite and position
Player::Player() : playerBody(new sf::Texture) {
  if (!playerBody->loadFromFile(
          "Sprites/halfling ranger/HalflingRangerIdleSide.gif")) {
    std::cout << "Error loading player model." << std::endl;
  }

  playerSprite.setTexture(*playerBody);
  playerSprite.setPosition(200, 200);
}

//draws player sprite to game window
void Player::draw(sf::RenderWindow* win) { win->draw(playerSprite); }

//returns positions of player
int Player::get_x() { return playerSprite.getPosition().x; }
int Player::get_y() { return playerSprite.getPosition().y; }
sf::Vector2f Player::get_PlayerPosition(){
  return playerSprite.getPosition();
}

//Returns player sprite
sf::Sprite Player::get_playerSprite() { return playerSprite; }


//Movement of player
void Player::move_right(float distance) {
  sf::Vector2f position = playerSprite.getPosition();
  position.x += distance;  // Move to the right by 'distance' units
  playerSprite.setPosition(position);
}
void Player::move_left(float distance) {
  sf::Vector2f position = playerSprite.getPosition();
  position.x -= distance;
  playerSprite.setPosition(position);
}
void Player::move_up(float distance) {
  sf::Vector2f position = playerSprite.getPosition();
  position.y -= distance;  // Move to the right by 'distance' units
  playerSprite.setPosition(position);
}
void Player::move_down(float distance) {
  sf::Vector2f position = playerSprite.getPosition();
  position.y += distance;  // Move to the right by 'distance' units
  playerSprite.setPosition(position);
}

//Collision for player
bool Player::isHit(int t_x, int t_y, int t_depth) {
  bool hit = false;

  return hit;
}

//Destructor
Player::~Player() { delete playerBody; }