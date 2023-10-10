#include "player.h"

#include <SFML/Graphics.hpp>
#include <iostream>

Player::Player() {
  if (!playerBody.loadFromFile("path_to_your_image.png")) {
    std::cout << "Error loading player model." << std::endl;
  }

  sf::Sprite playerSprite;
  playerSprite.setTexture(playerSprite);
}
void draw(sf::RenderWindow* win) { win->draw(*playerBody); }

int get_x() { return body->getPosition().x; }

int get_y() { return body->getPosition().y; }

int get_depth() { return _depth; }

sf::Texture* get_playerBody(){
  return (Player::playerBody);
}
sf::Vector2f get_PlayerPosition(){
  Player::playerBody.getposition();
}

//gets keypress from main and moves the player model accordingly

void Player::movePlayer(char key){
  // up movement
  if (key == 'w'){
  sf::Vector2f pose = playerBody.getPosition();
  pose.y += 6;  // Move to the right by 6 units
  playerBody.setPosition(pose);
  }
  // left movement
  else if (key == 'a'){
  sf::Vector2f pose = playerBody.getPosition();
  pose.x -= 6;  // Move left by 6 units
  playerBody.setPosition(pose);
  }
  // down movement
  else if(key == 's'){
  sf::Vector2f pose = playerBody.getPosition();
  pose.y -= 6;  // Move down by 6 units
  playerBody.setPosition(pose);
  }
  // right movement
  else if (key == 'd'){
  sf::Vector2f pose = playerBody.getPosition();
  pose.x += 6;  // Move to the right by 6 units
  playerBody.setPosition(pose);
  }
}


bool isHit(int t_x, int t_y, int t_depth) {
  bool hit = false;

  return hit;
}

~Player() { delete this->body; }
};

#endif