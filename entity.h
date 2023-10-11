#ifndef ENTITY_H
#define ENTITY_H
#include <string>
#include <SFML/Graphics.hpp>
class Entity {
 protected:
  sf::Texture* entityBody;
  int _depth;
  sf::Sprite entitySprite;

 public:
  Entity(std::string spriteLocation, int positionX, int positionY);
  int get_x();
  int get_y();
  sf::Sprite get_EntitySprite();
  sf::Vector2f get_EntityPosition();
  virtual void draw(sf::RenderWindow* win) = 0;
  ~Entity();
};

#endif