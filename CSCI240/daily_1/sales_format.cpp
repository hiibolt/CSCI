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
 * @return Returns a now-parsed double
 */
template <typename T> T checked_input ( string msg ) {
    T ret;

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

int main(){
    float item_price = checked_input<float>("What is the price for a single item? ");
    int number_items = checked_input<int>("How many items were purchased? ");

    float total_cost = item_price * number_items;
    
    cout << right << setw(5) << number_items << " items at $" << setprecision(2) << fixed << round(item_price * 100) / 100 << " each will cost $" << setprecision(2) << total_cost << endl;

    return 0;
}
