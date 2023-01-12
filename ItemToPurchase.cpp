//
// Created by Khand on 1/11/2023.
//

#include "ItemToPurchase.h"
#include <string>
#include <utility>

using namespace std;

ItemToPurchase::ItemToPurchase(){ // Default constructor.
    itemName = "none";
    itemDescription = "none";
    itemPrice = 0;
    itemQuan = 0;
}
ItemToPurchase::ItemToPurchase(string itemNamed, string itemInfo, double itemCost, double numOfItems) {
    itemName = std::move(itemNamed); // Parameterized constructor.
    itemDescription = std::move(itemInfo);
    itemPrice = itemCost;
    itemQuan = numOfItems;
}
void ItemToPurchase::SetName(const string& userString) { // Set item name.
    itemName = userString;
}
string ItemToPurchase::GetName(){ // Get item name.
    return itemName;
}
void ItemToPurchase::SetPrice(double userPrice){ //Set item price.
    itemPrice = userPrice;
}
double ItemToPurchase::GetPrice() const { //Get item price.
    return itemPrice;
}
void ItemToPurchase::SetQuantity(double userQuan){ //Set number of items.
    itemQuan = userQuan;
}
int ItemToPurchase::GetQuantity() const{ // Get number of items.
    return itemQuan;
}
void ItemToPurchase::SetDescription(string userScript) { //Set description of item.
    itemDescription = std::move(userScript);
}
string ItemToPurchase::GetDescription(){ //Get description of item.
    return itemDescription;
}
