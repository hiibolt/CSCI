/***************************************************************
CSCI 240         Program 1     Spring 2024

Programmer: John White (z1994244)

Section: 240-0002

Date Due: Jan 26th, 2024

Purpose: The purpose of this program is to calculate and display
         the gravitational force between two objects.

         The user provides the mass of the two objects and the
         distance between the objects.
***************************************************************/

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

/**
 * @brief A checked input that prevents an invalid conversion.
 *
 * @param string String which will prompt prior to taking input
 * @return Returns a now-parsed double
 */
double checked_input ( string msg ) {
    float ret;

    // Continually ask for input until manual loop termination
    while ( true ) {
        try {
            string input;

            // Output template message and direct to input string
            cout << msg;
            cin >> input;

            // Attempt to parse to a float
            ret = stof(input);

            // Only reachable if the input parses
            break;
        } catch ( const std::invalid_argument& e ) {
            cout << "\tInvalid input!" << endl;
        }
    }

    return ret;
}

int main () {
    const double gravitational_constant = 6.67 * pow(10, -11);

    double mass_obj_1;
    double mass_obj_2;
    double distance_between = 0;

    mass_obj_1 = checked_input("Enter the mass of object 1 (in kilograms): ");

    mass_obj_2 = checked_input("Enter the mass of object 2 (in kilograms): ");

    // Prevent zero from being inputted (prevents div_by_zero errors)
    while (distance_between == 0) {
        distance_between = checked_input("Enter the (non-zero) distance between the 2 objects (in meters): ");

        if (distance_between == 0) {
            cout << "\tMust be non-zero!" << endl;
        }
    }

    double gravitational_force = gravitational_constant * mass_obj_1 * mass_obj_2 / pow(distance_between, 2);

    cout << "\n\nThe force of gravitational attraction is: " << gravitational_force << endl << " newtons.";

    return 0;
}
