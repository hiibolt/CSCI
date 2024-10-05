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


#ifndef BOOK_STORE_H
#define BOOK_STORE_H

#include "book.h"

class book_store {
    public:
        book_store ( );

        void print ();

        void read_books     (const char *filename);
        void process_orders (const char *filename);
    private:
        Book books[30];
        int num_books;
};

#endif