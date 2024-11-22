#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>
#include "Item.h"

class Inventory {
private:
    std::vector<Item> items;

public:
    void addItem(const Item& item);
    void listItems() const;
    void searchItemByName(const std::string& name) const;
    bool removeItem(int id);
    bool updateQuantity(int id, int newQuantity);
    bool updatePrice(int id, double newPrice);
    Item* findItemByID(int id);
};

#endif // INVENTORY_H
