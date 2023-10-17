#ifndef COLLISIONTEST_H
#define COLLISIONTEST_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "collision.h"
#include "player.h"
#include "entity.h"

class CollisionTest {
private:
    Collision collision;

    void testWillHit() {
        Player entity(
          (std::string) "Sprites/halfling ranger/HalflingRangerIdleSide.gif",
          200, 200, 100, 100, 10, 0);
        entity.get_EntitySprite().setPosition(100, 450); // Setting position where there should be a collision
        
        if(!collision.willHit(entity)) {
            std::cout << "Error in test 1: Entity should hit." << std::endl;
        }

        entity.get_EntitySprite().setPosition(0, 0); // Setting position where there shouldn't be a collision

        if(collision.willHit(entity)) {
            std::cout << "Error in test 2: Entity shouldn't hit." << std::endl;
        }
    }

public:
    CollisionTest() {
        testWillHit();

    }
};

#endif