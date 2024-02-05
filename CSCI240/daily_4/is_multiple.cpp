/***************************************************************
CSCI 240         Daily 2     Spring 2024

Programmer: John White (z1994244)

Section: 240-0002

Date Due: Feb 06th, 2024

Purpose: Learn the use of various operators in C++
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
            cout << "\tInvalid input!" << endl;
        }
    }

    return ret;
}

int main(){
    // Request the two numbers from the users
    int num_1 = checked_input_int("What is the first number? ");
    int num_2 = checked_input_int("What is the second number? ");

    cout << endl;

    if ( num_1 <= 0 || num_2 <= 0 ) {
        cout << "*** Invalid input: one or both values is not positive" << endl;
        return -1;
    }

    cout << num_1 << " is " << ((num_1 % num_2 == 0) ? "": "NOT ") << "a multiple of " << num_2 << endl;
}
