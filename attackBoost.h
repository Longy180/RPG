#ifndef ATTACKBOOST_H
#define ATTACKBOOST_H
#include "item.h"
#include "player.h"
class AttackBoost : public Item{
    private:
    int damageIncrease;
    public:
    AttackBoost();
    int get_damageIncrease();
    void itemEffect(Player * player);
};
#endif