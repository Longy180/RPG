#include "item.h"
Item::Item(){
    buyPrice = 0;
    sellPrice = 0;
    name = "";
}
Item::Item(std::string name, int buyPrice, int sellPrice){
    Item::buyPrice = buyPrice;
    Item::sellPrice = sellPrice;
    Item::name = name;
}

int Item::get_buyPrice(){
return(Item::buyPrice);
}
int Item::get_sellPrice(){
return(Item::sellPrice);
}

std::string Item::get_name(){
return(Item::name);
}
