#include "healthPotion.h"
#include "player.h"
HealthPotion::HealthPotion() : Item(10, 5){
    healthIncrease = 25;
}
int HealthPotion::get_healthIncrease(){
return(healthIncrease);
}

void HealthPotion::itemEffect(Player * player){
    if (player->get_Health() + 25 <= player->get_maxHealth()){
    player->set_Health(player->get_Health()+get_healthIncrease());
    }else{
    player->set_Health(player->get_maxHealth());
    }
}
