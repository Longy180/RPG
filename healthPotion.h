#ifndef HEALTHPOTION_H
#define HEALTHPOTION_H
#include "item.h"
#include "player.h"
class HealthPotion : public Item{
    private:
    int healthIncrease;
    public:
    HealthPotion();
    int get_healthIncrease();
    void itemEffect(Player * player);
};
#endif