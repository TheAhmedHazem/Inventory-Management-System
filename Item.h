#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
private:
    static int nextID;
    int id;
    std::string name;
    int quantity;
    double price;
    std::string category;

public:
    Item(std::string& name, int quantity, double price, std::string& category);

    int getId() const;
    std::string getName() const;
    int getQuantity() const;
    double getPrice() const;
    std::string getCategory() const;

    void setQuantity(int quantity);
    void setPrice(double price);
    void display() const;
};

#endif // ITEM_H
