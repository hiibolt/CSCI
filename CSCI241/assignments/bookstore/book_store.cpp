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
#include "book_store.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

/**
 * Default constructor for the book_store class
 */
book_store::book_store ( ) {
    num_books = 0;
}

/**
 * Print the book inventory listing
 */
void book_store::print () {
    cout << "Book Inventory Listing" << endl << endl;
    cout << left << setw(14) << "ISBN" << setw(44) << "Title" << setw(5) << right << fixed << "Price" << setw(7) << right << "   Qty" << "." << endl << endl;
    for (int i = 0; i < num_books; i++) {
        books[i].print();
    }
}

/**
 * Read the books from a file
 * 
 * @param filename The filename to read the books from
 */
void book_store::read_books ( const char *filename ) {
    ifstream file;

    file.open(filename);
    if ( !file ) {
        cout << "Error: Could not open file `" << filename << "`" << endl;
        exit(1);
    }

    string ISBN;
    string title;
    string price_buffer;
    string quantity_buffer;

    // NOTE FOR TA GRADING:
    //  I'm using a stringstream to ensure it's not an empty line,
    //  the reason for this is because the last line of the file
    //  on the auto-grader is an empty line, and the program would
    //  process it as a book with empty data.
    //
    // Side Note:
    //  Pls fix 3:
    while (!file.eof()) {
        // Read the line
        string line;
        getline(file, line);

        // Ensure the line is not empty
        if (line == "") {
            continue;
        }

        // Convert it to a stringstream
        stringstream line_stream(line);

        // Book Data Format: `ISBN:TITLE:PRICE:QUANTITY`
        getline(line_stream, ISBN, ':');
        getline(line_stream, title, ':');
        getline(line_stream, price_buffer, ':');
        getline(line_stream, quantity_buffer);

        double price = stod(price_buffer);
        int quantity = stoi(quantity_buffer);

        (this -> books)[num_books] = Book(ISBN, title, price, quantity);
        num_books++;
        
    }

    // Sort the books by ISBN by selection sort
    for (int i = 0; i < num_books - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < num_books; j++) {
            if (books[j].get_ISBN() < books[min_index].get_ISBN()) {
                min_index = j;
            }
        }
        Book temp = books[i];
        books[i] = books[min_index];
        books[min_index] = temp;
    }

    file.close();
}

/**
 * Process the orders from a file
 * 
 * @param filename The filename to read the orders from
 */
void book_store::process_orders (const char *filename) {
    ifstream file;

    file.open(filename);
    if ( !file ) {
        cout << "Error: Could not open file `" << filename << "`" << endl;
        exit(1);
    }

    // Print a report header
    cout << "Order Listing" << endl << endl;

    string order_numbers;
    string ISBN;
    string quantity_buffer;

    while (!file.eof()) {
        // Read the line
        string line;
        getline(file, line);

        // Ensure the line is not empty
        if (line == "") {
            continue;
        }

        // Convert it to a stringstream
        stringstream line_stream(line);

        // Order Data Format: `ORDER_NUMBER:ISBN:QUANTITY`
        getline(line_stream, order_numbers, ' ');
        getline(line_stream, ISBN, ' ');
        getline(line_stream, quantity_buffer);

        int quantity = stoi(quantity_buffer);

        // Find the book with the matching ISBN by binary search
        int book_index = -1;
        int low = 0;
        int high = num_books - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (books[mid].get_ISBN() == ISBN) {
                book_index = mid;
                break;
            } else if (books[mid].get_ISBN() < ISBN) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (book_index == -1) {
            cout << "Order #" << order_numbers << ": error - ISBN " << ISBN << " does not exist" << endl;
        } else {
            int fulfilled_quantity = books[book_index].fulfill_order(quantity);
            float total = fulfilled_quantity * books[book_index].get_price();
            cout << "Order #" << order_numbers << ": ISBN " << ISBN << ", " << fulfilled_quantity << " of " << quantity << " shipped, order total $" << total << endl;
        }
    }

    file.close();
}