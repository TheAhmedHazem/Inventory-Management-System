#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
private:
    int id;
    std::string name;
    int quantity;
    double price;

public:
    Item(int id, const std::string& name, int quantity, double price);

    int getId() const;
    std::string getName() const;
    int getQuantity() const;
    double getPrice() const;

    void setQuantity(int quantity);
    void setPrice(double price);
    void display() const;
};

#endif // ITEM_H
