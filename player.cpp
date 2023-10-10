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
void draw(sf::RenderWindow* win) { win->draw(*body); }

int get_x() { return body->getPosition().x; }
int get_y() { return body->getPosition().y; }
int get_depth() { return _depth; }

void Player::move_right(sf::Texture& player, sf::Sprite& playerBody,
                        float distance) {
  sf::Vector2f pose = playerBody.getPosition();
  pose.x += distance;  // Move to the right by 'distance' units
  playerBody.setPosition(pose);
}

void Player::move_left(sf::Texture& player, sf::Sprite& playerBody,
                       float distance) {
  sf::Vector2f pose = playerBody.getPosition();
  pose.x -= distance;  // Move to the right by 'distance' units
  playerBody.setPosition(pose);
}

void Player::move_up(sf::Texture& player, sf::Sprite& playerBody,
                     float distance) {
  sf::Vector2f pose = playerBody.getPosition();
  pose.y -= distance;  // Move to the right by 'distance' units
  playerBody.setPosition(pose);
}

void Player::move_down(sf::Texture& player, sf::Sprite& playerBody,
                       float distance) {
  sf::Vector2f pose = playerBody.getPosition();
  pose.y += distance;  // Move to the right by 'distance' units
  playerBody.setPosition(pose);
}

bool isHit(int t_x, int t_y, int t_depth) {
  bool hit = false;

  return hit;
}

~Player() { delete this->body; }
}
;

#endif