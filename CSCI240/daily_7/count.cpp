/***************************************************************
CSCI 240         Daily 7     Spring 2024

Programmer: John White (z1994244)

Section: 240-0002

Date Due: Feb 16th, 2024

Purpose: Learn I/O checks and output N elements.
***************************************************************/

#include <iostream>
#include <unistd.h>

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
    int n = checked_input_int("N value (must be greater than or equal to 1)? ");

    while ( n <= 0 ) {
        n = checked_input_int("Error: the N-value must be greater than or equal to 1. Try again: ");
    }

    cout << endl;

    for ( int i = 0; i < n; i ++ ) {
        cout << i + 1 << endl;
    }
}