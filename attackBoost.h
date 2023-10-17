#ifndef ATTACKBOOST_H
#define ATTACKBOOST_H
#include "item.h"
#include "player.h"
class AttackBoost : public Item{
    private:
    int damageIncrease;
    public:
    AttackBoost();
    AttackBoost(std::string name);
    int get_damageIncrease();
    void itemEffect(Player * player);
};
#endif