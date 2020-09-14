/*
 *        File: invoice.cc
 *      Author: Nathan Chan
 *        Date: 9/14/2020
 * Description: Hard drive sales and invoice
 *              
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {

    const double westerndigital = 90.00;
    const double seagate = 95.00;
    double discount, total, discountamount, finaltotal, subtotal, tax;
    int quantity;
    char type, state;
    string brand;
    string price;
    string resident;
    cout << "Enter a hard drive type (w, s) followed by the quantity:";
    cin >> type >> quantity;
    cout << "Do you live in Ohio (yes/no)?";
    cin >> state;
    if (type == 'w')  {
      total = westerndigital * quantity;
      brand = "Western Digital";
      price = "$90.00";
    }
    if (type == 's') {
      total = seagate * quantity;
      brand = "Seagate";
      price = "$95.00";
    }
    if (state == 'y') {
      tax = 1.07;
      resident = "Yes";
    } else {
      tax = 1;
      resident = "No";
    }
    if (quantity >= 5) {
      discount = 0.95;
      subtotal = (total * discount);
      discountamount = (total - subtotal);
      finaltotal = (total * discount) * tax;
    } else {
      subtotal = (total * 1);
      finaltotal = total * tax;
      discountamount = 0;
    }
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);  
    cout << "Hard Drives Invoice" << endl;
    cout << "---------------------------------" << endl;
    cout << "  Drive brand: " << brand << endl;
    cout << "     Quantity: " << quantity << endl;
    cout << "        Price: " << price << endl;
    cout << "Ohio Resident: " << resident << endl;
    cout << "  Total price: $" << total << endl;
    cout << "------------------------------" << endl;
    cout << "     Discount: $" << discountamount << endl;
    cout << "     Subtotal: $" << subtotal << endl;
    cout << "        Taxes: $" << (finaltotal - subtotal) << endl;
    cout << "==============================" << endl;
    cout << "        Total: $" << finaltotal << endl;
    cout << "==============================";
    return 0;
}// main
