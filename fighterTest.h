#ifndef FIGHTERTEST_H
#define FIGHTERTEST_H

#include <iostream>
#include <string>

#include "fighter.h"
#include "enemy.h"
#include "healthPotion.h"

class FighterTest {
private:
    Fighter fighter;
    Enemy enemy;

    void testEntityProperties() {
        std::cout << "Fighter X position: " << fighter.get_x() << std::endl;
        std::cout << "Fighter Y position: " << fighter.get_y() << std::endl;
    }

    void testCharacterProperties() {
        std::cout << "Fighter Health: " << fighter.get_Health() << std::endl;
        std::cout << "Fighter Max Health: " << fighter.get_maxHealth() << std::endl;
        std::cout << "Fighter Damage: " << fighter.get_damage() << std::endl;
    }

    void testPlayerProperties() {
        std::cout << "Fighter Gold: " << fighter.get_Gold() << std::endl;
    }

    void testMovement() {
        fighter.move_right(10);
        std::cout << "Fighter moved right. New X position: " << fighter.get_x() << std::endl;
        
        fighter.move_left(5);
        std::cout << "Fighter moved left. New X position: " << fighter.get_x() << std::endl;
    }

    void testAttacks() {
        std::cout << "Enemy Health before attack: " << enemy.get_Health() << std::endl;

        fighter.attack1(&enemy);
        std::cout << "After Fighter's attack1, Enemy Health: " << enemy.get_Health() << std::endl;

        fighter.attack2(&enemy);
        std::cout << "After Fighter's attack2, Enemy Health: " << enemy.get_Health() << std::endl;
    }

    void testInventory() {
        HealthPotion potion((std::string)"Potion"); 
        fighter.addToInventory(&potion);

        std::cout << "Item added to inventory. Current inventory size: " << fighter.get_currInventorySize() << std::endl;

        fighter.removeFromInventory(0);
        std::cout << "Item removed from inventory. Current inventory size: " << fighter.get_currInventorySize() << std::endl;
    }

public:
    FighterTest() 
        : fighter(),
          enemy("SomeSpritePath", 250, 250, 100, 100, 5) {
        std::cout << "Fighter created!" << std::endl;
        
        testEntityProperties();
        testCharacterProperties();
        testPlayerProperties();
        testMovement();
        testAttacks();
        testInventory();
    }
};

#endif