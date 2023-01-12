//
// Created by Khand on 1/11/2023.
//
#include <string>
#include "ShoppingCart.h"
#include <iostream>
#include <iomanip>
#include <utility>
using namespace std;

ShoppingCart::ShoppingCart() { //Default constructor.
    custName = "none";
    currDate = "January 1, 2016";
    coupCode = 0;
}
ShoppingCart::ShoppingCart(string userName, string userDate) {
    custName = userName; // Parameterized constructor.
    currDate = userDate;
    coupCode = 0;

}
string ShoppingCart::GetCustomerName() { //Get customer name.
    return custName;
}
string ShoppingCart::GetDate() { //Get current date.
    return currDate;
}
void ShoppingCart::AddItem(ItemToPurchase access) { // Add item to the cart.
    ItemToPurchase addItem;
    string itemName;
    string addScript;
    int i;
    double userPrice;
    double userQuan;
    cout << "ADD ITEM TO CART" << endl << "Enter the item name:" << endl;
    cin.ignore();
    getline(cin, itemName);
    for (i = 0; i < itemName.length(); ++i){
        itemName[i] = toupper(itemName[i]);
    }
    addItem.SetName(itemName);
    cout << "Enter the item description:" << endl;
    getline(cin, addScript);
    addItem.SetDescription(addScript);
    cout << "Enter the item price:" << endl;
    cin  >> userPrice;
    while (userPrice < 0){
        cout << "Price cannot be negative. Please try again." << endl;
        cin  >> userPrice;
    }
    addItem.SetPrice(userPrice);
    cout << "Enter the item quantity:" << endl;
    cin  >> userQuan;
    while (userQuan < 1){
        cout << "You must have at least one item. Please try again." << endl;
        cin  >> userQuan;

    }
    addItem.SetQuantity(userQuan);

    cartItems.push_back(addItem);

}
void ShoppingCart::RemoveItem(string itemName) { //Remove item from the cart.
    int i;
    string found;
    int pos = 0;

    for (i = 0; i < cartItems.size(); ++i) {
        if (itemName == cartItems[i].GetName()) {
            found = cartItems[i].GetName();
            itemName = found;
            pos = i;
        }
    }
    if (itemName == found) {
        cartItems.erase(cartItems.begin() + pos);
    }
    else {
        cout << "Item not found in cart. Nothing removed." << endl;
    }
}
void ShoppingCart::ModifyItem(ItemToPurchase itemAccess) { //Modify the quantity of an item in the cart.
    int i;
    string itemName;
    string found;
    int pos;
    double itemQuan;
    cout << "CHANGE ITEM QUANTITY" << endl << "Enter the item name:" << endl;
    cin.ignore();
    getline(cin, itemName);
    for (i = 0; i < itemName.length(); ++i){
        itemName[i] = toupper(itemName[i]);
    }
    cout << "Enter the new quantity:" << endl;
    cin  >> itemQuan;
    for (i = 0; i < cartItems.size(); ++i) {
        if (itemName == cartItems[i].GetName()) {
            found = itemName;
            pos = i;
        }
    }
    if (itemName == found){
        cartItems[pos].SetQuantity(itemQuan);
    }
    else {
        cout << "Item not found in cart. Nothing modified." << endl;
    }
}
int ShoppingCart::GetNumItemsInCart(int items, int numItems){
    if (items == cartItems.size()){ //Get number of items in the cart.
        return numItems;
    }
    else{
        numItems = numItems + cartItems.at(items).GetQuantity();
        return GetNumItemsInCart(items + 1, numItems);
    }
}
double ShoppingCart::GetCostOfCart() { // Get total cost of all items in the cart.
    int i;                             //Returns value to PrintTotal function.
    double itemPrice;
    double totCost = 0;
    cout << fixed;
    cout << setprecision(2);
    for (i = 0; i < cartItems.size(); ++i){
        itemPrice = cartItems[i].GetPrice() * cartItems[i].GetQuantity();
        totCost = totCost + itemPrice;
    }
    if (coupCode == 0){
        cout << endl << "Total: $" << totCost << endl;
    }
    else {
        cout << endl << "Total with discount: $" << totCost - (totCost * coupCode) << endl;
    }
    return totCost;
}
void ShoppingCart::PrintTotal(ItemToPurchase cartAccess) {
    int i = 0;                            //Output customer's name, date, number of items in the cart,
    int numItems = 0;                     //the name, quantity and cost of each individual item, and
    if (!cartItems.empty()) {             //the total cost of all items in the cart.
        cout << GetCustomerName() << "'s Shopping Cart - " << GetDate() <<
             endl << "Number of Items: " << GetNumItemsInCart(i, numItems) << endl << endl;
        ItemToPurchase::PrintItemCost(cartItems);
    }
    else{
        cout << GetCustomerName() << "'s Shopping Cart - " << GetDate() <<
             endl << "Number of Items: " << GetNumItemsInCart(i, numItems) << endl << endl;
        ItemToPurchase::PrintItemCost(cartItems);
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
    GetCostOfCart();
}
void ShoppingCart::PrintDescriptions(ItemToPurchase cartAccess) {       //Prints customer's name, date,
    cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl << GetCustomerName() <<//each item in cart, and its description.
         "'s Shopping Cart - " << GetDate() << endl << endl <<
         "Item Descriptions" << endl;
    ItemToPurchase::PrintItemDescription(cartItems);
}
void ItemToPurchase::PrintItemCost(vector<ItemToPurchase> cartItems){
    int i;                                     //Calculates cost of each item per its quantity.
    for (i = 0; i < cartItems.size(); ++i) {   //Sends item name, quantity and cost to PrintTotal function.
        cout << cartItems[i].GetName() << " " << cartItems[i].GetQuantity()
             << " @ $" << cartItems[i].GetPrice() << " = $" <<
             cartItems[i].GetPrice() * cartItems[i].GetQuantity() << endl;
    }
}
void ItemToPurchase::PrintItemDescription(vector<ItemToPurchase> cartItems) {
    int i;                                      //Gets item name and description and sends to
    for (i = 0; i < cartItems.size(); ++i) {    // PrintDescriptions function.
        cout << cartItems[i].GetName() << ": " << cartItems[i].GetDescription() << endl;
    }
}
int ShoppingCart::CouponCode() { //Validates coupon codes and applies to total cost of cart.
    string code;
    double newTot;
    cout << fixed;
    cout << setprecision(2);

    if (coupCode == 0) {
        int i;
        double discount = .10;
        vector<string> validCoup = {"SAV10", "SAV15", "SAV20"};
        cout << "Please enter coupon code:" << endl;
        cin >> code;
        for (i = 0; i < validCoup.size(); ++i) {
            if (validCoup.at(i) == code) {
                newTot = GetCostOfCart() - (GetCostOfCart() * discount);
                cout << "After discount: $" << newTot << endl;
                coupCode = discount;
            }
            discount = discount + .05;
        }
        if (coupCode == 0) {
            cout << "Invalid code. Please try again." << endl;
        }
    }
    else {
        cout << "Coupon already applied." << endl;
    }
    return coupCode;
}
void ShoppingCart::PrintMenu() { //Prints menu of options for customer to choose from.
    char menuOption;

    cout << endl << "MENU" << endl << "a - Add item to cart" <<
         endl << "d - Remove item from cart" << endl << "c - Change item quantity"
         << endl << "i - Output items' descriptions" << endl << "o - Output shopping cart"
         << endl << "u - Input coupon code" << endl << "q - Quit" << endl << endl <<
         "Choose an option:" << endl;
    cin  >> menuOption;

    while (menuOption != 'q'){
        while(menuOption != 'a' && menuOption != 'd' && menuOption != 'c'
              && menuOption != 'i' && menuOption != 'o' && menuOption != 'q' &&
              menuOption != 'u'){
            cout << "Choose an option:" << endl;
            cin  >> menuOption;
            if (menuOption == 'q'){
                exit(0);
            }
        }

        if (menuOption == 'a'){
            ItemToPurchase access;
            AddItem(access);
        }
        else if (menuOption == 'd'){
            string nameToRemove;
            int i;
            cout << "REMOVE ITEM FROM CART" << endl <<
                 "Enter name of item to remove:" << endl;
            cin.ignore();
            getline(cin, nameToRemove);
            for (i = 0; i < nameToRemove.length(); ++i){
                nameToRemove[i] = toupper(nameToRemove[i]);
            }
            RemoveItem(nameToRemove);
        }
        else if (menuOption == 'c'){
            ItemToPurchase access;
            ModifyItem(access);
        }
        else if (menuOption == 'i'){
            ItemToPurchase access;
            PrintDescriptions(access);
        }
        else if (menuOption == 'u'){
            CouponCode();
        }
        else {
            ItemToPurchase access;
            cout << "OUTPUT SHOPPING CART" << endl;
            PrintTotal(access);
        }

        cout << endl << "MENU" << endl << "a - Add item to cart" <<
             endl << "d - Remove item from cart" << endl << "c - Change item quantity"
             << endl << "i - Output items' descriptions" << endl << "o - Output shopping cart"
             << endl << "u - Input coupon code" << endl << "q - Quit" << endl << endl <<
             "Choose an option:" << endl;
        cin  >> menuOption;
    }
}
