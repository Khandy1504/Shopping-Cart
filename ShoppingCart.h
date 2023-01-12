//
// Created by Khand on 1/11/2023.
//

#ifndef SHOPPINGCART_SHOPPINGCART_H
#define SHOPPINGCART_SHOPPINGCART_H
#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include "ItemToPurchase.h"
using namespace std;


class ShoppingCart : public ItemToPurchase {
public:
    ShoppingCart();
    ShoppingCart(string custName, string currDate);
    string GetCustomerName();
    string GetDate();
    void AddItem(ItemToPurchase access);
    void RemoveItem(string itemName);
    void ModifyItem(ItemToPurchase itemAccess);
    int GetNumItemsInCart(int items, int numItems);
    double GetCostOfCart();
    void PrintTotal(ItemToPurchase cartAccess);
    void PrintDescriptions(ItemToPurchase cartAccess);
    int CouponCode ();
    void PrintMenu();

private:
    string custName;
    string currDate;
    double coupCode;
    vector<ItemToPurchase> cartItems;

};



#endif //SHOPPINGCART_SHOPPINGCART_H

