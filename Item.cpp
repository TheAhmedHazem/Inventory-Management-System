#include <Item.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class Item{
    private:
        static int nextID;
        int id;
        string name;
        string category;
        int quantity;
        double price;
    public:
        Item(std::string name, int quantity, double price, std::string category)
           : name(name), quantity(quantity), price(price), category(category) {
            this->id = nextID++;
        }

        int getId() const { return id; }
        string getName() const { return name; }
        int getQuantity() const { return quantity; }
        double getPrice() const { return price; }
        string getCategory() const { return category; }

        void setQuantity(int quantity) { this -> quantity = quantity; }
        void setPrice(double price) { this -> price = price; }

        void display() const {
        cout << "ID: " << id << ", Name: " << name
             << ", Quantity: " << quantity << ", Price: $" << price << endl;
    }
};
int Item::nextID = 1;  // Initialize the static counter
