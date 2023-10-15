#include "player.h"
#include "character.h"
#include <SFML/Graphics.hpp>
#include <iostream>

//Constructor, sets default player sprite and position
Player::Player(std::string spriteLocation, int positionX, int positionY, int maxHealth, int currHealth, int damage, int currGold)
: Character(spriteLocation, positionX, positionY, maxHealth, currHealth, damage) {
  Player::currGold = currGold;
  Player::_depth = 100;
}


//draws player sprite to game window
void Player::draw(sf::RenderWindow* win){ 
  win->draw(entitySprite); 
  }

//Get hitbox depth
int Player::get_depth() { return _depth; }

//Movement of player
void Player::move_right(float distance) {
  sf::Vector2f position = entitySprite.getPosition();
  position.x += distance;  // Move to the right by 'distance' units
  entitySprite.setPosition(position);
}
void Player::move_left(float distance) {
  sf::Vector2f position = entitySprite.getPosition();
  position.x -= distance;
  entitySprite.setPosition(position);
}
void Player::move_up(float distance) {
  sf::Vector2f position = entitySprite.getPosition();
  position.y -= distance;  // Move to the right by 'distance' units
  entitySprite.setPosition(position);
}
void Player::move_down(float distance) {
  sf::Vector2f position = entitySprite.getPosition();
  position.y += distance;  // Move to the right by 'distance' units
  entitySprite.setPosition(position);
}

//Collision for player
bool Player::isHit(int t_x, int t_y, int t_depth) {
  bool hit = false;

  return hit;
}

//Destructor
Player::~Player(){ 
  delete entityBody;
}