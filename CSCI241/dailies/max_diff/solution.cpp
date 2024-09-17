/**
    * @brief  Given an array of integers, find the maximum difference between any 
    *          two elements such that the larger element appears after the smaller element.
    *
    * @param a The array.
    * @param len The length of the array.
    *
    * @return The maximum difference between any two elements.
    */
int max_diff_seq ( int a[], int len ) {
    int max = -1;
    
    for ( int i = 0; i < len; i++ ) {
        for ( int g = i + 1; g < len; g++ ) {
            int diff = a[g] - a[i];

            max = diff > max ? diff : max;
        }
    }

    return max;
}