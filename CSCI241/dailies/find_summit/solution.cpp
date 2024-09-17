/**
    * @brief  Find the summit of an array
    *
    * @param a The array.
    * @param len The length of the array.
    *
    * @return The summit of the array.
    */
int find_summit ( int a[], int len ) {
    int summit = a[0];

    for ( int i = 1; i < len; i++ ) {
        if ( a[i] > summit ) {
            summit = a[i];
        }
    }

    return summit;
}