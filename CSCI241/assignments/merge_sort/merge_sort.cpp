#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

/**
    * @brief Build an array from input
    *
    * @param array[] The array to populate
    *
    * @return The number of elements in the array
    */
int build_array ( double array[] ) {
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
    * @brief Merge two arrays
    *
    * @param array[] The array to merge
    * @param start The start index
    * @param mid The middle index
    * @param end The end index
    */
void merge( double array[], int start, int mid, int end ) {
    // Temporary vector of size (end - start + 1)
    vector<double> temp(end - start + 1);
    
    int i = start;
    int j = mid + 1;
    int k = 0;
    
    // Merge the two arrays
    while ( i <= mid && j <= end ) {
        if ( array[i] < array[j] ) {
            temp[k] = array[i];
            i = i + 1;
        } else {
            temp[k] = array[j];
            j = j + 1;
        }
        k = k + 1;
    }
    
    // Copy the remaining elements of the left array
    while ( i <= mid ) {
        temp[k] = array[i];
        i = i + 1;
        k = k + 1;
    }
    
    // Copy the remaining elements of the right array
    while ( j <= end ) {
        temp[k] = array[j];
        j = j + 1;
        k = k + 1;
    }
    
    // Copy the elements of the vector temp back into array
    for ( i = start; i <= end; i++ ) {
        array[i] = temp[i - start];
    }
}

/**
    * @brief Merge sort an array
    *
    * @param array[] The array to sort
    * @param start The start index
    * @param end The end index
    */
void merge_sort_recursive ( double array[], int start, int end ) {
    if ( start < end ) {
        int mid = (start + end) / 2;
    
        // Recursively sort the left and right halves
        merge_sort_recursive(array, start, mid);
        merge_sort_recursive(array, mid + 1, end);
    
        // Merge the two halves
        merge(array, start, mid, end);
    }
};

/**
    * @brief Merge two arrays
    *
    * @param array[] The array to merge
    * @param int The number of elements in the array
    */
void merge_sort ( double array[], int n ) {
    merge_sort_recursive(array, 0, n - 1);
};