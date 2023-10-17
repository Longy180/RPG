#ifndef HEALTHBOOST_H
#define HEALTHBOOST_H
#include "item.h"
#include "player.h"
#include "string.h"
class HealthBoost : public Item{
    private:
    int healthIncrease;
    public:
    HealthBoost();
    HealthBoost(std::string name);
    int get_healthIncrease();
    void itemEffect(Player * player);
};
#endif