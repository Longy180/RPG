#ifndef RANGERTEST_H
#define RANGERTEST_H

#include <iostream>
#include <string>
#include "ranger.h"
#include "enemy.h"

class RangerTest {
private:
    Ranger ranger;
    Enemy enemy;

    void testEntityProperties() {
        std::cout << "Ranger X position: " << ranger.get_x() << std::endl;
        std::cout << "Ranger Y position: " << ranger.get_y() << std::endl;
    }

    void testCharacterProperties() {
        std::cout << "Ranger Health: " << ranger.get_Health() << std::endl;
        std::cout << "Ranger Max Health: " << ranger.get_maxHealth() << std::endl;
        std::cout << "Ranger Damage: " << ranger.get_damage() << std::endl;
    }

    void testPlayerProperties() {
        std::cout << "Ranger Gold: " << ranger.get_Gold() << std::endl;
    }

    void testAttacks() {
        std::cout << "Enemy Health before attack: " << enemy.get_Health() << std::endl;

        ranger.attack1(&enemy);
        std::cout << "After Ranger's attack1 (stab), Enemy Health: " << enemy.get_Health() << std::endl;

        ranger.attack2(&enemy);
        std::cout << "After Ranger's attack2 (volley), Enemy Health: " << enemy.get_Health() << std::endl;
    }

    void testHealing() {
        ranger.takeDamage(50); // Just to ensure the ranger has lost some health for testing
        std::cout << "Ranger Health after taking damage: " << ranger.get_Health() << std::endl;
        
        ranger.heal();
        std::cout << "Ranger Health after healing: " << ranger.get_Health() << std::endl;
    }

public:
    RangerTest() 
        : ranger(),
          enemy("SomeSpritePath", 250, 250, 100, 100, 5) {
        std::cout << "Ranger created!" << std::endl;
        
        testEntityProperties();
        testCharacterProperties();
        testPlayerProperties();
        testAttacks();
        testHealing();
    }
};

#endif