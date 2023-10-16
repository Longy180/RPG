#ifndef ITEM_H
#define ITEM_H
class Item{
private:
int buyPrice, sellPrice;

public:
Item();
Item(int buyPrice, int sellPrice);

int get_buyPrice();
int get_sellPrice();
};
#endif