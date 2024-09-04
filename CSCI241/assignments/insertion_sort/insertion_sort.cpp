/***************************************************************
CSCI 241         John White     Spring 2024

Programmer: z19942444

Section: 241-0002

Date Due: Friday, August 31rst

Purpose: Perform an insertion sort.
***************************************************************/

/*

    /ᐠ - ˕ -マ

    @hiibolt on GitHub 

*/


#include <iostream>
#include <iomanip>
#include <algorithm>


/**
    * @brief Build an array from input
    *
    * @param array[] The array to populate
    *
    * @return The number of elements in the array
    */
int build_array (double array[] ) {
    int n = 0;

    // While there are remaining items, read doubles
    while (std::cin >> array[n] ) {
        n++;
    }

    return n;
};

/**
    * @brief Print an array
    *
    * @param array[] The array to print
    * @param n The number of elements in the array
    */
void print_array ( double array[], int n ) {
    for ( int i = 0; i < n; i++ ) {
        // Print the current element
        std::cout << std::setw(8) << std::right << std::fixed << std::setprecision(2) << array[i];

        // If the current index is divisible by 8 and not
        //  0, print a newline
        if ( i % 8 == 7 || (i == n - 1) ) {
            std::cout << std::endl;
        }
    }
};

/**
    * @brief Sort an array using insertion sort
    *
    * @param array[] The array to sort
    * @param n The number of elements in the array
    */
void insertion_sort ( double array[], int n) {
    int cursor = 1;

    // Pass through the entire element
    while ( cursor < n ) {
        int inner_cursor = cursor;

        // Continually swap down until the elements are equal, or 
        //  the inner cursor's element is less than the cursor element
        while ( inner_cursor > 0 && array[inner_cursor] < array[inner_cursor - 1] ) {
            std::swap( array[inner_cursor], array[inner_cursor - 1] );

            inner_cursor --;
        }

        cursor ++;
    }

};