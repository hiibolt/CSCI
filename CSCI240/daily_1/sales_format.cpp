#include <iostream>
#include <iomanip>
#include <unistd.h>

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
    double item_price = checked_input<double>("What is the price for a single item? ");
    int number_items = checked_input<int>("How many items were purchased? ");

    double total_cost = item_price * number_items;

    cout << endl;
    cout << right << setw(5) << number_items << " items at $" << fixed << setprecision(2) << item_price << " each will cost $" << setprecision(2) << total_cost;

    return 0;
}
