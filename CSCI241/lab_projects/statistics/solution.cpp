#include <cmath>

using std::sqrt;

/**
    * @brief Find the minimum value in an array.
    *
    * @param array The array.
    * @param n The number of elements in the array.
    *
    * @return The minimum value in the array.
    */
int minimum ( int array[], int n ) {
    int min = array[0];
    
    for ( int i = 0; i < n; i ++ ) {
        if ( array[i] < min ) {
            min = array[i];
        }
    }

    return min;
}

/**
    * @brief Find the maximum value in an array.
    *
    * @param array The array.
    * @param n The number of elements in the array.
    *
    * @return The maximum value in the array.
    */
int maximum ( int array[], int n ) {
    int max = array[0];
    
    for ( int i = 0; i < n; i ++ ) {
        if ( array[i] > max ) {
            max = array[i];
        }
    }

    return max;
};

/**
    * @brief Find the range of an array.
    *
    * @param array The array.
    * @param n The number of elements in the array.
    *
    * @return The range of the array.
    */
int range ( int array[], int n ) {
    return maximum(array, n) - minimum(array, n);
};

/**
    * @brief Find the average of an array.
    *
    * @param array The array.
    * @param n The number of elements in the array.
    *
    * @return The average of the array.
    */
double average ( int array[], int n ) {
    double sum = 0;
    
    for ( int i = 0; i < n; i ++ ) {
        sum += array[i];
    }

    return sum / n;
};

/**
    * @brief Find the median of an array.
    *
    * @param array The array.
    * @param n The number of elements in the array.
    *
    * @return The median of the array.
    */
double median ( int array[], int n ) {
    if ( n % 2 == 0 ) {
        return ( array[n / 2 - 1] + array[n / 2] ) / 2.0;
    } else {
        return array[n / 2];
    }
};

/**
    * @brief Find the standard deviation of an array.
    *
    * @param array The array.
    * @param n The number of elements in the array.
    *
    * @return The standard deviation of the array.
    */
double stddev ( int array[], int n ) {
    double avg = average(array, n);
    double sum = 0;
    
    for ( int i = 0; i < n; i ++ ) {
        sum += ( array[i] - avg ) * ( array[i] - avg );
    }

    return sqrt( sum / n );
};