#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include "Item.h"

using namespace std;

class Inventory {
private:
    vector<Item> items;

public:
    Item* findItemByID(int id) {
        for (Item& item : items) {
            if (item.getId() == id) {
                return &item;
            }
        }
        return nullptr;
    }

    void addItem(string name, string category, float price, int quantity) {
    int newID = 1;
    if (!items.empty()) {
        newID = items.back().getId() + 1;
    }
    try {
        Item newItem(name, quantity, price, category);
        items.push_back(newItem);
        cout << "Item added successfully with ID: " << newItem.getId() << endl;
    } catch (const invalid_argument& e) {
        cout << "Error adding item: " << e.what() << endl;
    }
    cout << "-----------------------------------------------------------" << endl;
}

    void removeItem(int id) {
        auto initialSize = items.size();
        items.erase(
            remove_if(items.begin(), items.end(),
                [id](const Item& item) { return item.getId() == id; }),
            items.end()
        );
        
        if (items.size() < initialSize) {
            cout << "Item removed." << endl;
        } else {
            cout << "Item not found." << endl;
        }
        cout << "-----------------------------------------------------------" << endl;
    }

    void listItems() {
        if (items.empty()) {
            cout << "No items in inventory." << endl;
        } else {
            for (const Item& item : items) {
                item.display();
            }
        }
        cout << "-----------------------------------------------------------" << endl;
    }

    void searchItemByName(const string& name) {
        bool found = false;
        for (const Item& item : items) {
            if (item.getName() == name) {
                item.display();
                found = true;
            }
        }
        if (!found) {
            cout << "Item not found." << endl;
        }
        cout << "-----------------------------------------------------------" << endl;
    }

    void updateQuantity(int id, int newQuantity) {
        if (newQuantity < 0) {
            cout << "Invalid quantity. Quantity cannot be negative." << endl;
            return;
        }

        Item* tempItem = findItemByID(id);
        if (tempItem != nullptr) {
            tempItem->setQuantity(newQuantity);
            cout << "Quantity updated." << endl;
        } else {
            cout << "Item not found." << endl;
        }
        cout << "-----------------------------------------------------------" << endl;
    }

    void updatePrice(int id, float newPrice) {
        if (newPrice < 0) {
            cout << "Invalid price. Price cannot be negative." << endl;
            return;
        }

        Item* tempItem = findItemByID(id);
        if (tempItem != nullptr) {
            tempItem->setPrice(newPrice);
            cout << "Price updated." << endl;
        } else {
            cout << "Item not found." << endl;
        }
        cout << "-----------------------------------------------------------" << endl;
    }

    void filterByCategory(const string& category) {
        bool found = false;
        for (const Item& item : items) {
            if (item.getCategory() == category) {
                item.display();
                found = true;
            }
        }
        if (!found) {
            cout << "No items found in category: " << category << endl;
        }
        cout << "-----------------------------------------------------------" << endl;
    }

    void filterByPrice(double minPrice, double maxPrice) {
        if (minPrice > maxPrice) {
            cout << "Invalid price range. Minimum price cannot be greater than maximum price." << endl;
            return;
        }

        bool found = false;
        for (const Item& item : items) {
            if (item.getPrice() >= minPrice && item.getPrice() <= maxPrice) {
                item.display();
                found = true;
            }
        }
        if (!found) {
            cout << "No items found in price range: $" << fixed << setprecision(2) 
                 << minPrice << " - $" << maxPrice << endl;
        }
        cout << "-----------------------------------------------------------" << endl;
    }

    void filterByQuantity(int minQuantity, int maxQuantity) {
        if (minQuantity < 0 || maxQuantity < 0) {
            cout << "Invalid quantity range. Quantities cannot be negative." << endl;
            return;
        }
        if (minQuantity > maxQuantity) {
            cout << "Invalid quantity range. Minimum quantity cannot be greater than maximum quantity." << endl;
            return;
        }

        bool found = false;
        for (const Item& item : items) {
            if (item.getQuantity() >= minQuantity && item.getQuantity() <= maxQuantity) {
                item.display();
                found = true;
            }
        }
        if (!found) {
            cout << "No items found in quantity range: " << minQuantity << " - " << maxQuantity << endl;
        }
        cout << "-----------------------------------------------------------" << endl;
    }
};