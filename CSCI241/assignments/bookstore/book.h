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


#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
    public:
        Book ( );
        Book ( const std::string& ISBN, const std::string& title, double price, int quantity );

        std::string get_ISBN      ( );
        double  get_price     ( );

        int    fulfill_order ( int quantity );
        void   print         ( );
    private:
        std::string ISBN;
        std::string title;
        double      price;
        int         quantity;
};

#endif