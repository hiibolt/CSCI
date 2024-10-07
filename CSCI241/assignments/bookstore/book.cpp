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

/**
 * Default constructor for the Book class
 */
Book::Book ( ) {
    ISBN = "";
    title = "";
    price = 0.0;
    quantity = 0;
}

/**
 * Constructor for the Book class
 * 
 * @param ISBN The ISBN of the book
 * @param title The title of the book
 * @param price The price of the book
 * @param quantity The quantity of the book
 */
Book::Book ( const string& ISBN, const string& title, double price, int quantity ) {
    this->ISBN = ISBN;
    this->title = title;
    this->price = price;
    this->quantity = quantity;
}

/**
 * Get the ISBN of the book
 * 
 * @return The ISBN of the book
 */
string Book::get_ISBN ( ) {
    return ISBN;
}

/**
 * Get the price of the book
 * 
 * @return The price of the book
 */
double Book::get_price     ( ) {
    return price;
}

/**
 * Fulfill an order for the book
 * 
 * @param quantity The quantity of the book to fulfill
 * @return The quantity of the book that was fulfilled
 */
int Book::fulfill_order ( int quantity ) {
    // Check if the quantity is negative
    if ( quantity < 0 ) {
        cout << "Error: Quantity cannot be negative" << endl;
        return 0;
    }

    // Check if the quantity is greater than the quantity of the book
    if ( quantity > this -> quantity ) {
        int temp = this -> quantity;
        this -> quantity = 0;
        return temp;
    } else {
        this->quantity -= quantity;
        return quantity;
    }
}

/**
 * Print the book
 */
void Book::print ( ) {
    cout << left << setw(14) << ISBN << setw(44) << title << right << fixed << setprecision(2) << setw(5) << price << setw(6) << right << quantity << endl;
}