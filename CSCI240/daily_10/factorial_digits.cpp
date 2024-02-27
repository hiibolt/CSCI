/***************************************************************
CSCI 240         Daily 8     Spring 2024

Programmer: John White (z1994244)

Section: 240-0002

Date Due: Feb 16th, 2024

Purpose: Calculate the sum of values between two numbers.
***************************************************************/

#include <iostream>
#include <unistd.h>
#include <algorithm>

using namespace std;

/**
 * @brief A checked input that prevents an invalid conversion.
 *
 * @param string String which will prompt prior to taking input
 * @return Returns a now-parsed value
 */
int checked_input_int ( string msg ) {
    int ret;

    // Continually ask for input until manual loop termination
    while ( true ) {
        try {
            string input;

            // Output template message and direct to input string
            cout << msg;
            cin >> input;

            // Attempt to parse to a float
            ret = stod(input);

            // Only reachable if the input parses
            break;
        } catch ( const std::invalid_argument& e ) {
            cout << "\tInvalid input! Please try again." << endl;
        }
    }

    return ret;
}

int main(){
    int n = checked_input_int("N value (must be greater than or equal to 0)? ");
    
    // Check the input
    if ( n < 0 || n > 12 ) {
        cout << endl << "Invalid Input: " << n << endl;
        return -1;
    }

    // Calculate the factorial
    int n_factorial = 1;
    for ( int i = 1; i <= n; i++ ) {
        n_factorial *= i;
    }

    // Calculate the digits
    string n_factorial_string = to_string(n_factorial);
    int digits = n_factorial_string.length();

    // Output
    cout << endl << n << "! is equal to " << n_factorial << ". There are " << digits << " digits." << endl;
}