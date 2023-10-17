#ifndef HEALTHPOTION_H
#define HEALTHPOTION_H
#include "item.h"
#include "player.h"
class HealthPotion : public Item{
    private:
    int healthIncrease;
    public:
    HealthPotion();
    HealthPotion(std::string name);
    int get_healthIncrease();
    void itemEffect(Player * player);
};
#endif