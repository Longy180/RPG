#include "player.h"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "character.h"
#include "item.h"
// Constructor, sets default player sprite and position
Player::Player(std::string spriteLocation, int positionX, int positionY,
               int maxHealth, int currHealth, int damage, int currGold)
    : Character(spriteLocation, positionX, positionY, maxHealth, currHealth,
                damage) {
  Player::currGold = currGold;
  Player::_depth = 100;
  maxInventorySize = 4;
  inventory = new Item*[maxInventorySize];
  currInventorySize = 0;
  
}

// draws player sprite to game window
void Player::draw(sf::RenderWindow* win) { win->draw(entitySprite); }

// Get hitbox depth
int Player::get_depth() { return _depth; }

// Movement of player
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

// Collision for player
bool Player::isHit(int t_x, int t_y, int t_depth) {
  bool hit = false;

  return hit;
}
int Player::get_Gold(){
return(currGold);
}
int Player::get_currInventorySize(){
  return(currInventorySize);
}
void Player::add_Gold(int gold){
currGold += gold;
}
void Player::addToInventory(Item* item) {
  if(currInventorySize < maxInventorySize){
    inventory[currInventorySize] = item;
    currInventorySize++;
  }else{
  std::cout<<"Inventory is full";
  }
  
}
void Player::removeFromInventory(int index){
    if (index >= 0 && index < currInventorySize) {
        inventory[index] = nullptr;
        
        for (int i = index; i < currInventorySize - 1; i++) {
            inventory[i] = inventory[i + 1];
        }

        currInventorySize--;

        inventory[currInventorySize] = nullptr;
    } else {
        std::cout << "Invalid index\n";
    }
}
Item* Player::getInventoryItem(int index) {
  if (index >= 0 && index < currInventorySize) {
    return inventory[index];
  }
  return nullptr;
}

// Virtual functions
void Player::attack1(Enemy* opponent) {
  opponent->set_Health(opponent->get_Health() - Player::damage);
}
void Player::attack2(Enemy* opponent) {
  if ((rand() % 10 + 1) >= 4) {
    opponent->set_Health(opponent->get_Health() - (Player::damage * 1.5));
  } else {
    std::cout << "Your volley missed\n";
  }
}
void Player::heal() {
  if (currHealth + 15 > maxHealth) {
    currHealth = maxHealth;
  } else {
    currHealth += 15;
  }
}
void Player::takeDamage(int damage) { currHealth = currHealth - damage; }

// Destructor
Player::~Player() {
  for (int i = 0; i < currInventorySize; i++) {
    delete inventory[i];
  }
  delete[] inventory;
}