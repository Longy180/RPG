#ifndef HEALTHBOOST_H
#define HEALTHBOOST_H
#include "item.h"
#include "player.h"
class HealthBoost : public Item{
    private:
    int healthIncrease;
    public:
    HealthBoost();
    int get_healthIncrease();
    void itemEffect(Player * player);
};
#endif