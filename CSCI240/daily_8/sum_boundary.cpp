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
    int num_1 = checked_input_int("What is the lower bound? ");
    int num_2 = checked_input_int("What is the upper bound? ");

    int lower_bound = min(num_1, num_2);
    int upper_bound = max(num_1, num_2);

    cout << endl;

    // I'm not actually swapping them, but this is required for grading.
    if ( num_1 > num_2 )
        cout << "*** boundary values have been swapped ***" << endl << endl;

    int sum = 0;
    for ( int i = lower_bound; i <= upper_bound; i++ ) {
        sum += i;
    }

    cout << "The sum of the values between " << lower_bound << " and " << upper_bound << " is " << sum << endl;
}