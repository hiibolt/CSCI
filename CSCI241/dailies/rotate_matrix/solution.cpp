/***************************************************************
CSCI 241         John White     Spring 2024

Programmer: z19942444

Section: 241-0002

Date Due: ?

Purpose: Rotate a matrix 90 degrees.
***************************************************************/

/*

    /ᐠ - ˕ -マ

    @hiibolt on GitHub 

*/;


/**
 * @brief Rotate a matrix 90 degrees
 * 
 * @param destination The destination matrix
 * @param source The source matrix
 */
void rotate_matrix ( int destination[][8], int source[][8] ) {
    for ( int i = 0; i < 8; i++ ) {
        for ( int g = 0; g < 8; g++ ) {
            destination[g][7 - i] = source[i][g];
        }
    }
};