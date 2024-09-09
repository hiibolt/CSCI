/***************************************************************
CSCI 241         John White     Spring 2024

Programmer: z19942444

Section: 241-0002

Date Due: Friday, September 13th

Purpose: Find if the sum of four elements in an array is equal to a given number.
***************************************************************/

/*

    /ᐠ - ˕ -マ

    @hiibolt on GitHub 

*/

/**
    * @brief Check if the sum of four elements in an array is equal to a given number.
    *
    * @param a The array.
    * @param len The length of the array.
    * @param n The number to check for.
    *
    * @return True if the sum of four elements is equal to n, false otherwise.
    */
bool quad_sum_is_n ( int a[], int len, int n ) {
    // This uses a four-pointer approach to check all possible combinations
    //  of four elements in the array. It should be duley noted that this
    //  is not the most efficient way to solve this problem, but it is
    //  the most straightforward.
    for ( int p_1 = 0; p_1 < len - 3; p_1++ ) {
        for ( int p_2 = p_1; p_2 < len - 2; p_2 ++ ) {
            for ( int p_3 = p_2; p_3 < len - 1; p_3 ++ ) {
                for ( int p_4 = p_3; p_4 < len; p_4++ ) {
                    // Grab each element
                    int e_1 = a[p_1];
                    int e_2 = a[p_2];
                    int e_3 = a[p_3];
                    int e_4 = a[p_4];

                    // Check if the sum is equal to n
                    if ( e_1 + e_2 + e_3 + e_4 == n ) {
                        return true;
                    }
                }
            }
        }
    }

    // If no combination is found, return false
    return false;
}