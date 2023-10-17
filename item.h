#ifndef ITEM_H
#define ITEM_H
#include <string>
class Item{
private:
int buyPrice, sellPrice;
std::string name;
public:
Item();
Item(std::string name, int buyPrice, int sellPrice);

int get_buyPrice();
int get_sellPrice();
std::string get_name();
};
#endif