#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include <string>
class Entity {
 protected:
  sf::Texture* entityBody;
  int _depth;
  sf::Sprite entitySprite;

 public:
  // Constructors
  Entity();
  Entity(std::string spriteLocation, int positionX, int positionY);
  // Return location of entity
  int get_x();
  void set_position(int _x, int _y);
  int get_y();

  // Returns entity position
  sf::Vector2f get_EntityPosition();

  // Returns entity sprite
  sf::Sprite get_EntitySprite();

  // Sets the entity sprite to the sprite location provided, used in animation
  void set_entitySprite(std::string spriteLocation, int positionX,
                        int positionY);

  virtual void draw(sf::RenderWindow* win) = 0;
  // Destructor
  ~Entity();
};

#endif