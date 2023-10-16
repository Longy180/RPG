#include "item.h"
Item::Item(){
    buyPrice = 0;
    sellPrice = 0;
}
Item::Item(int buyPrice, int sellPrice){
    Item::buyPrice = buyPrice;
    Item::sellPrice = sellPrice;
}

int Item::get_buyPrice(){
return(Item::buyPrice);
}
int Item::get_sellPrice(){
return(Item::sellPrice);
}
