#include <Item.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class Item{
    private:
        int id;
        string name;
        string category;
        int quantity;
        double price;
    public:
        Item(int id, string name, string category, int quantity, double price)
            : id(id), name(name), category(category), quantity(quantity), price(price){}


        int getId() const { return id; }
        string getName() const { return name; }
        int getQuantity() const { return quantity; }
        double getPrice() const { return price; }

        void setQuantity(int quantity) { this -> quantity = quantity; }
        void setPrice(double price) { this -> price = price; }

        void display() const {
        cout << "ID: " << id << ", Name: " << name
             << ", Quantity: " << quantity << ", Price: $" << price << endl;
    }

};