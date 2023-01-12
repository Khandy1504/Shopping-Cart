
#include "ItemToPurchase.h"
#include "ShoppingCart.h"
#include <iostream>
#include <string>
using namespace std;

//Shopping cart program.

int main() {
    string userName;
    string userDate;

    // Get customer name and date.
    cout << "Enter customer's name:" << endl;
    getline(cin, userName);
    cout << "Enter today's date:" << endl;
    getline(cin, userDate);
    cout << endl << "Customer name: " << userName <<
         endl << "Today's date: " << userDate << endl;
    // Store in parameterized constructor.
    ShoppingCart constr(userName, userDate);

    constr.PrintMenu();


    return 0;
}
