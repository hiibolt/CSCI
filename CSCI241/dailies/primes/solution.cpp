#include <iostream>

using std::cout;
using std::endl;

/**
    * @brief Check if a number is prime
    *
    * @param n The number to check
    *
    * @return True if the number is prime, false otherwise
    */
bool is_prime ( int n ) {
    if ( n < 2 ) {
        return false;
    }

    for ( int i = 2; i < n; i++ ) {
        if ( n % i == 0 ) {
            return false;
        }
    }

    return true;
}

/**
    * @brief Check if a number ends in a digit
    *
    * @param n The number to check
    * @param digit The digit to check for
    *
    * @return True if the number ends in the digit, false otherwise
    */
bool ends_in ( int n, int digit ) {
    return (n - digit) % 10 == 0;
}

/**
    * @brief Print all prime numbers less than a limit
    *  that do not end in a digit
    *
    * @param limit The upper limit of numbers to check
    * @param d The digit to avoid
    */
void print_primes(int limit, int d) {
    for ( int i = 0; i < limit; i ++ ) {
        if ( is_prime(i) && !ends_in(i, d) ) {
            cout << i << " ";
        }
    }

    cout << endl;
}