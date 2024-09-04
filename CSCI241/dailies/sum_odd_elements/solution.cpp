/**
    * @brief Calculate the sum of all odd elements in an array
    *
    * @param a[] The array of integers
    * @param n The number of elements in the array
    *
    * @return The sum of all odd elements in the array
    */
int sum_odd_elements ( int a[], int n ) {
    int ret = 0;

    for ( int i = 0; i < n; i++ ) {
        if ( a[i] % 2 != 0 ) {
            ret += a[i];
        }
    }

    return ret;
}