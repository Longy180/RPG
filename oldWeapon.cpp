#include "oldWeapon.h"
#include "player.h"
OldWeapon::OldWeapon() : Item(10, 5){
    damageIncrease = 3;
}
int OldWeapon::get_damageIncrease(){
return(damageIncrease);
}


