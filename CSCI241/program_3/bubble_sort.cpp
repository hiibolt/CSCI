/***************************************************************
CSCI 241         John White     Spring 2024

Programmer: z19942444

Section: 241-0002

Date Due: Friday, August 31rst

Purpose: Perform a bubble (sinking) sort.
***************************************************************/

/*

    /ᐠ - ˕ -マ

    @hiibolt on GitHub 

*/


#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;


/**
    * @brief Build an array from input
    *
    * @param array[] The array to populate
    *
    * @return The number of elements in the array
    */
int build_array ( string array[] ) {
    int n = 0;

    // While there is input, populate the array
    //  and increment `n`
    while ( cin >> array[n] ) {
        n ++;
    }

    return n;
};

/**
    * @brief Print an array
    *
    * @param array[] The array to print
    * @param n The number of elements in the array
    */
void print_array ( string array[], int n ) {
    for ( int i = 0; i < n; i++ ) {
        // Print the current element
        std::cout << std::setw(8) << std::left << array[i];

        // If the current index is divisible by 8 and not
        //  0, print a newline
        if ( i % 8 == 7 || (i == n - 1) ) {
            std::cout << std::endl;
        }
    }
};

/**
    * @brief Sort an array using bubble sort
    *
    * @param array[] The array to sort
    * @param n The number of elements in the array
    */
void bubble_sort ( string array[], int n ) {
    int cap = n - 1;

    // Pass through the array until the cap is at 0
    while ( cap > 0 ) {
        int cursor = 0;

        // Pass through the array, ignoring the last
        //  element after each pass
        while ( cursor < cap ) {
            // If the element is larger than the next, swap them
            if ( array[cursor] > array[cursor + 1] ) {
                std::swap( array[cursor], array[cursor + 1] );
            }

            cursor ++;
        }

        cap --;
    }
};