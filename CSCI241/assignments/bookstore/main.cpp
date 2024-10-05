//*************************************************************************
//
// main.cpp
// CSCI 241 Assignment 9
//
// Created by Kurt McMahon (t90kjm1)
//
//*************************************************************************

#include <iostream>
#include "book_store.h"

using std::cout;
using std::endl;

int main()
{
    book_store store;

    store.read_books("books.txt");

    store.print();

    cout << endl;

    store.process_orders("orders.txt");

    cout << endl;

    store.print();

    return 0;
}
