#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int build_array ( string array[] ) {
    int n = 0;

    // While there is input, populate the array
    //  and increment `n`
    while ( cin >> array[n] ) {
        n ++;
    }

    return n;
};
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