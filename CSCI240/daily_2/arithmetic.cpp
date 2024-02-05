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
            ret = stoi(input);

            // Only reachable if the input parses
            break;
        } catch ( const std::invalid_argument& e ) {
            cout << "\tInvalid input!" << endl;
        }
    }

    return ret;
}
void display_operation( int _num_1, int _num_2, string opr, int result ) {
    cout << _num_1 << " " << opr << " " << _num_2 << " = " << result << endl;
}


int main(){
    // Request the two numbers from the users
    int num_1 = checked_input_int("First number? ");
    int num_2 = checked_input_int("Second number? ");

    cout << endl;

    display_operation(num_1, num_2, "+", num_1 + num_2);
    display_operation(num_1, num_2, "-", num_1 - num_2);
    display_operation(num_1, num_2, "*", num_1 * num_2);
    display_operation(num_1, num_2, "/", num_1 / num_2);
    display_operation(num_1, num_2, "%", num_1 % num_2);

    cout << endl;

    display_operation(num_2, num_1, "-", num_2 - num_1);
    display_operation(num_2, num_1, "/", num_2 / num_1);
    display_operation(num_2, num_1, "%", num_2 % num_1);

    cout << endl;
}
