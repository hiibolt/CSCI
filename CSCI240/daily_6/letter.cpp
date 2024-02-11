/***************************************************************
CSCI 240         Daily 6     Spring 2024

Programmer: John White (z1994244)

Section: 240-0002

Date Due: Feb 16th, 2024

Purpose: Calculate letter grades
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
    int num_1 = checked_input_int("What is the test score? ");

    char letter_grade;

    if ( num_1 >= 92 ) {
        letter_grade = 'A';
    } else if ( num_1 >= 84 ) {
        letter_grade = 'B';
    } else if ( num_1 >= 76 ) {
        letter_grade = 'C';
    } else if ( num_1 >= 68 ) {
        letter_grade = 'D';
    } else {
        letter_grade = 'F';
    }

    cout << endl << "The score " << num_1 << " earns the grade " << letter_grade << endl;
}
