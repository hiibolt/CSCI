/***************************************************************
CSCI 241         John White     Spring 2024

Programmer: z19942444

Section: 241-0002

Date Due: ASAP

Purpose: Reverse the diagonals of a 4x4 array.
***************************************************************/

/*

    /ᐠ - ˕ -マ

    @hiibolt on GitHub 

*/

#include <algorithm>

/**
 * Reverses the diagonal of a 4x4 array.
 * 
 * @param array The 4x4 array to reverse the diagonal of.
 */
void reverse_diagonal ( int array[][4] ) {
    for ( int i = 0; i < 2; i++ ) {
        // Swap the top left and bottom right corners
        std::swap( array[i][i], array[3-i][3-i] );

        // Swap the top right and bottom left corners
        std::swap( array[i][3-i], array[3-i][i] );
    }
}