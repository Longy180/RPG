#ifndef OldWEAPON_H
#define OldWEAPON_H
#include "item.h"
#include "player.h"
class OldWeapon : public Item{
    private:
    int damageIncrease;
    public:
    OldWeapon();
    int get_damageIncrease();
};
#endif