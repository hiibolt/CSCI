/***************************************************************
CSCI 241         John White     Spring 2024

Programmer: z19942444

Section: 241-0002

Date Due: ASAP

Purpose: Perform a heap sort.
***************************************************************/

/*

    /ᐠ - ˕ -マ

    @hiibolt on GitHub 

*/


#include <algorithm>

/**
 * @brief Sift down an element in the heap
 * 
 * @param array[] The array to sift down
 * @param start The starting index
 * @param end The ending index
 */
void sift_down ( int array[], int start, int end ) {
    int root = start;

    while ( ( 2 * root + 1 ) <= end ) {
        int child = 2 * root + 1;
        int largest = root;

        if ( array[largest] < array[child] ) {
            largest = child;
        }

        if ( ( child + 1 ) <= end && array[largest] < array[child + 1] ) {
            largest = child + 1;
        }

        if ( largest == root ) {
            return;
        } else {
            std::swap ( array[root], array[largest] );
            root = largest;
        }
    }
}

/**
 * @brief Heapify an array
 * 
 * @param array[] The array to heapify
 * @param n The number of elements in the array
 */
void heapify ( int array[], int n ) {
    int start = (n - 2) / 2;

    while ( start >= 0 ) {
        sift_down ( array, start, n - 1 );

        start = start - 1;
    }
}

/**
 * @brief Sort an array using the heap sort algorithm
 * 
 * @param array[] The array to sort
 * @param n The number of elements in the array
 */
void heap_sort ( int array[], int n ) {
    heapify ( array, n );

    int end = n - 1;
    while ( end > 0 ) {
        std::swap(array[end], array[0]);
        end --;

        sift_down( array, 0, end );
    }
}