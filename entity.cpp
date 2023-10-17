#include "entity.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
//-------------Use for anything that is placed on the map.

//-------------Initialise class
Entity::Entity() {
  entitySprite.setPosition(0, 0);
  entitySprite.setScale(3, 3);
}

Entity::Entity(std::string spriteLocation, int positionX, int positionY)
    : entityBody(new sf::Texture) {
  if (!entityBody->loadFromFile(spriteLocation)) {
    std::cout << "Error loading player model." << std::endl;
  }

  entitySprite.setTexture(*entityBody);
  entitySprite.setPosition(positionX, positionY);
  entitySprite.setScale(3, 3);
}

// returns positions of player
int Entity::get_x() { return entitySprite.getPosition().x; }
int Entity::get_y() { return entitySprite.getPosition().y; }

// sets positions of player
void Entity::set_position(int _x, int _y) { entitySprite.setPosition(_x, _y); }

sf::Vector2f Entity::get_EntityPosition() { return entitySprite.getPosition(); }

// Returns player sprite
sf::Sprite Entity::get_EntitySprite() { return entitySprite; }

// Sets player sprite
void Entity::set_entitySprite(std::string spriteLocation, int positionX, int positionY) {
  if (!entityBody->loadFromFile(spriteLocation)) {
    std::cout << "Error loading player model." << std::endl;
  }
  entitySprite.setTexture(*entityBody);
  entitySprite.setPosition(positionX, positionY);
  entitySprite.setScale(3, 3);
}

// Destructor
Entity::~Entity() {}