/***************************************************************
CSCI 241         John White     Spring 2024

Programmer: z19942444

Section: 241-0002

Date Due: ASAP

Purpose: Simulate a book store.
***************************************************************/

/*

    /ᐠ - ˕ -マ

    @hiibolt on GitHub 

*/


#include "book.h"
#include <iostream>
#include <iomanip>

using namespace std;

Book::Book ( ) {
    ISBN = "";
    title = "";
    price = 0.0;
    quantity = 0;
}
Book::Book ( const string& ISBN, const string& title, double price, int quantity ) {
    this->ISBN = ISBN;
    this->title = title;
    this->price = price;
    this->quantity = quantity;
}
string Book::get_ISBN ( ) {
    return ISBN;
}
double Book::get_price     ( ) {
    return price;
}
int Book::fulfill_order ( int quantity ) {
    if ( quantity > this->quantity ) {
        int temp = this->quantity;
        this->quantity = 0;
        return temp;
    } else {
        this->quantity -= quantity;
        return quantity;
    }
}
void Book::print ( ) {
    /*
    The method
    should print the ISBN, title, price, and quantity members on the console using cout. Use
    setw() to line the printed values up in columns (a width of 14 for the ISBN, 44 for the title,
    5 for the price, and 6 for the quantity will match the sample output). The ISBN and title
    should be left justified; the price and quantity should be right justified. The price should be
    printed using fixed-point notation with two places after the decimal point
    */

    cout << left << setw(14) << ISBN << setw(44) << title << right << fixed << setprecision(2) << setw(5) << price << setw(6) << right << quantity << endl;

}