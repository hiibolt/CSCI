/***************************************************************
CSCI 241         John White     Spring 2024

Programmer: z19942444

Section: 241-0002

Date Due: Friday, September 13th

Purpose: Find the maximum length of a rope that can be cut into 
    n pieces of length a[i] such that the sum of the lengths of 
    the pieces is equal to a given number.
***************************************************************/

/*

    /ᐠ - ˕ -マ

    @hiibolt on GitHub 

*/

/**
    * @brief Find the maximum length of a rope that can be cut into 
    n pieces of length a[i] such that the sum of the lengths of 
    the pieces is equal to a given number.
    *
    * @param a The array of lengths.
    * @param n The number of elements in the array.
    * @param sum The sum of the lengths of the pieces.
    *
    * @return The maximum length of the rope that can be cut into n pieces
    *  such that the sum of the lengths of the pieces is equal to sum.
    */
int cutting_rope ( int a[], int n, int sum ) {
    int max_len = a[0];

    // Find the longest piece
    for ( int i = 1; i < n; i++ ) {
        if ( a[i] > max_len ) {
            max_len = a[i];
        }
    }
    
    // Find the maximum length of the rope that can be cut
    for ( int cut = max_len - 1; cut >= 0; cut-- ) {
        int total = 0;

        // Calculate the total length of the rope
        for ( int i = 0; i < n; i++ ) {
            int severed = a[i] - cut;

            // Add the severed length to the total if it is positive
            total += severed > 0 ? severed : 0;
        }

        // If the total is equal to the sum, return the cut
        if ( total == sum ) {
            return cut;
        }
    }

    // If no matching cut is found, return -1
    return -1;
}