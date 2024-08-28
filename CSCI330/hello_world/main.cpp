/***************************************************************
CSCI 240         <name>     Spring 2024

Programmer: <me>

Section: 240-0002

Date Due: <date>

Purpose: <purpose>
***************************************************************/

/*

    /ᐠ - ˕ -マ

    @hiibolt on GitHub 

*/

#include <iostream>
#include <array>
#include <algorithm>
#include <string>

using namespace std;

/**
 * @brief A checked input that prevents an invalid conversion.
 *
 * @param string String which will prompt prior to taking input
 * @return Returns a now-parsed int
 */
int checked_int_input ( string msg ) {
    int ret;

    // Continually ask for input until manual loop termination
    while ( true ) {
        try {
            string input;

            // Output template message and direct to input string
            cout << msg;
            cin >> input;

            // Attempt to parse to a float
            ret = stoi(input);

            // Only reachable if the input parses
            break;
        } catch ( const std::invalid_argument& e ) {
            cout << "\tInvalid input!" << endl;
        }
    }

    return ret;
}

int main(){
    cout << ":3" << endl;
}
