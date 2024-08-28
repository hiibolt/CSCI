#include <iostream>
#include <iomanip>
#include <algorithm>

int build_array (double array[] ) {
    int n = 0;

    // While there are remaining items, read doubles
    while (std::cin >> array[n] ) {
        n++;
    }

    return n;
};
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