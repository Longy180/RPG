#ifndef MAGETEST_H
#define MAGETEST_H

#include <iostream>
#include <string>

#include "mage.h"
#include "enemy.h"

class MageTest {
private:
    Mage mage;
    Enemy enemy;

    void testFireballAttack() {
        int initialEnemyHealth = enemy.get_Health();
        mage.attack1(&enemy);
        int afterAttackHealth = enemy.get_Health();

        if (afterAttackHealth != initialEnemyHealth - mage.get_damage()) {
            std::cout << "Error in Fireball Attack test: Expected Enemy Health to decrease by Mage's damage." << std::endl;
        }
    }

    void testLightningAttack() {
        int initialEnemyHealth = enemy.get_Health();
        mage.attack2(&enemy);
        int afterAttackHealth = enemy.get_Health();

        // Since Lightning attack has a randomness factor, we can't be certain about its effect.
        // Hence, we're just checking if the health did not remain the same after attack.
        if (afterAttackHealth == initialEnemyHealth) {
            std::cout << "Error in Lightning Attack test: Expected Enemy Health to decrease or the summon failed message." << std::endl;
        }
    }

    void testHeal() {
        mage.takeDamage(50);
        int postDamageHealth = mage.get_Health();
        mage.heal();
        int afterHealHealth = mage.get_Health();

        if (afterHealHealth <= postDamageHealth) {
            std::cout << "Error in Heal test: Mage's health did not increase after meditating." << std::endl;
        }
    }

    void testDamageTaken() {
        int initialHealth = mage.get_Health();
        mage.takeDamage(20);
        int postDamageHealth = mage.get_Health();

        if (postDamageHealth != initialHealth - 20) {
            std::cout << "Error in Damage Taken test: Mage's health did not decrease by the expected damage value." << std::endl;
        }
    }

public:
    MageTest() 
        : mage(),
          enemy("SomeSpritePath", 250, 250, 100, 100, 5) {
        testFireballAttack();
        testLightningAttack();
        testHeal();
        testDamageTaken();
    }
};

#endif