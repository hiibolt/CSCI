#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/**
    * @brief Build an array from input
    *
    * @param array[] The array to populate
    *
    * @return The number of elements in the array
    */
int build_array ( int array[] ) {
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
void print_array ( int array[], int n ) {
    for ( int i = 0; i < n; i++ ) {
        // Print the current element
        std::cout << std::setw(8) << std::right << array[i];

        // If the current index is divisible by 8 and not
        //  0, print a newline
        if ( i % 8 == 7 || (i == n - 1) ) {
            std::cout << std::endl;
        }
    }
};

/**
    * @brief Partition an array
    *
    * @param array[] The array to partition
    * @param start The start index
    * @param end The end index
    *
    * @return The pivot index
    */
int partition ( int array[], int start, int end ) {
    int mid = ( start + end ) / 2;

    std::swap ( array[start], array[mid] );

    int pivot_index = start;
    int pivot_value = array[start];

    int scan = start + 1;
    while ( scan <= end ) {
        if ( array[scan] < pivot_value ) {
            pivot_index ++;
            std::swap ( array[pivot_index], array[scan] );
        }

        scan ++;
    }

    std::swap(array[start], array[pivot_index]);

    return pivot_index;
};

/**
    * @brief Recursive quicksort
    *
    * @param array[] The array to sort
    * @param start The start index
    * @param end The end index
    */
void quicksort_recursive ( int array[], int start, int end ) {
    if ( start < end ) {
        int pivot = partition ( array, start, end );

        quicksort_recursive ( array, start, pivot - 1 );
        quicksort_recursive ( array, pivot + 1, end );
    }
};

/**
    * @brief Sort an array using the quick sort algorithm
    *
    * @note This function is the entrypoint for the recursive
    *        entrypoint for the quicksort algorithm
    *
    * @param array[] The array to sort
    * @param n The number of elements in the array
    */
void quicksort ( int array[], int n ) {
    quicksort_recursive ( array, 0, n - 1 );
};