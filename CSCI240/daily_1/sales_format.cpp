/***************************************************************
CSCI 240         Daily 1     Spring 2024

Programmer: John White (z1994244)

Section: 240-0002

Date Due: Feb 02nd, 2024

Purpose: Calculate total cost of a grocery trip.
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/**
 * @brief A checked input that prevents an invalid conversion.
 *
 * @param string String which will prompt prior to taking input
 * @return Returns a now-parsed value
 */
double checked_input_double ( string msg ) {
    double ret;

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

int main(){
    double item_price = checked_input_double("What is the price for a single item? ");
    int number_items = checked_input_int("How many items were purchased? ");

    double total_cost = item_price * number_items;

    cout << endl;
    cout << right << setw(5) << number_items << " items at $" << fixed << setprecision(2) << item_price << " each will cost $" << setprecision(2) << total_cost << endl;

    return 0;
}
