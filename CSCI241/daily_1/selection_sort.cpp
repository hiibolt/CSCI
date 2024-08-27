/***************************************************************
CSCI 241         John White     Spring 2024

Programmer: z19942444

Section: 241-0002

Date Due: Friday, August 31rst

Purpose: Perform a selection sort.
***************************************************************/

/*

    /ᐠ - ˕ -マ

    @hiibolt on GitHub 

*/

#include <iostream>
#include <iomanip>
#include <algorithm>

int build_array ( int array[] ) {
    int n = 0;

    // While there are remaining items, read integers
    //  from the standard input and store them in the array
    while (std::cin >> array[n]) {
        n++;
    }

    return n;
};
void print_array ( int array[], int n ) {
    for ( int i = 0; i < n; i++ ) {
        // If the current index is divisible by 8 and not 
        //  0, print a newline
        if ( i % 8 == 0 && i != 0 ) {
            std::cout << std::endl;
        }

        // Print the current element
        std::cout << std::setw(8) << std::right << array[i];

        // If the current index is the last index and the total number
        //  of elements is not divisible by 8, print a newline
        if ( i == n - 1 && n % 8 != 0 ) {
            std::cout << std::endl;
        }
    }
};
void selection_sort (int array[], int n ) {
    // Start at the first index
    int cursor = 0;

    // Pass through the array, moving the smallest element to the front
    while ( cursor < n - 1 ) {
        int inner_cursor = cursor;

        // Find the smallest element in the array 
        //  (if it is not already at the front)
        while ( inner_cursor < n - 1 ) {
            inner_cursor ++;

            // If a candidate is found, swap it with the current element
            if ( array[inner_cursor] < array[cursor] ) {
                std::swap(array[inner_cursor], array[cursor]);
            }
        }

        cursor ++;
    }

};