#include "attackBoost.h"
#include "player.h"
AttackBoost::AttackBoost() : Item("",10, 5){
    damageIncrease = 3;
}
AttackBoost::AttackBoost(std::string name) : Item(name, 10, 5){
    damageIncrease = 3;
}
int AttackBoost::get_damageIncrease(){
return(damageIncrease);
}

void AttackBoost::itemEffect(Player * player){
    player->set_damage(get_damageIncrease() + player->get_damage());
}

