#include <Inventory.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

class Inventory{
    private:
        vector<Item> items;

    public:
        Item* findItemByID(int id){
            for (Item& item : items){
                if (item.getId() == id){
                    return &item;
                }
                else{
                    return nullptr;
                }
            }
        }
        void addItem(Item item){
            Item* tempItem = findItemByID;
            if(tempItem != nullptr){
                cout << "Item already exists." << endl;
            }
            else{
                items.push_back(item);
                cout << "Item added." << endl;
                cout << "-----------------------------------------------------------" <<endl;

            }
        }
        void removeItem(int id){
            Item* tempItem = findItemByID;
            if(tempItem != nullptr){
                items.erase(remove_if(items.begin(), items.end(), [id](Item& item){
                    return item.getId() == id;
                }), items.end());
                cout << "Item removed." << endl;
                cout << "-----------------------------------------------------------" <<endl;
            }
            else{
                cout << "Item not found." << endl;
                cout << "-----------------------------------------------------------" <<endl;
            }
        }
        void listItems(){
            if(items.size() == 0){
                cout << "No items in inventory." << endl;
                cout << "-----------------------------------------------------------" <<endl;
            }
            else{
                for(Item& item : items){
                    item.display();
                }
            }
        }
        void searchItemByName(string name){
            bool found = false;
            for(Item& item : items){
                if(item.getName() == name){
                    item.display();
                    found = true;
                }
                else{
                    cout << "Item no found" << endl;
                    found = false;
                }
            }
        }
        void updateQuantity(int id, int newQuantity){
            Item* tempItem = findItemByID(id);
            if(tempItem != nullptr){
                tempItem -> setQuantity(newQuantity);
                cout << "Quantity updated." << endl;
            } 
            else{
                cout << "Item not found." << endl;
            }
        }
        void updatePrice(int id, float newPrice){
            Item* tempItem = findItemByID(id);
            if(tempItem != nullptr){
                tempitem -> setPrice(newPrice);
                cout << "Price updated." << endl;
            }
            else{
                cout << "Item not found." << endl;
            }
        }
};