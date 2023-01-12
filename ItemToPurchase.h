//
// Created by Khand on 1/11/2023.
//

#ifndef SHOPPINGCART_ITEMTOPURCHASE_H
#define SHOPPINGCART_ITEMTOPURCHASE_H
#include <string>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

class ItemToPurchase {
public:
    ItemToPurchase();
    ItemToPurchase(string itemName, string itemInfo, double itemPrice, double itemQuan);
    void SetName(const string& userString);
    string GetName();
    void SetPrice(double userPrice);
    double GetPrice() const;
    void SetQuantity(double userQuan);
    int GetQuantity() const;
    void SetDescription(string itemScript);
    string GetDescription();
    static void PrintItemCost(vector<ItemToPurchase> cartItems);
    static void PrintItemDescription(std::vector<ItemToPurchase> cartItems);

private:
    string itemName;
    string itemDescription;
    double itemPrice;
    double itemQuan;

};



#endif //SHOPPINGCART_ITEMTOPURCHASE_H

