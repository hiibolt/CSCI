/***************************************************************
CSCI 240         Program 4     Spring 2024

Programmer: John White (z1994244)

Section: 240-0002

Date Due: Feb 06th, 2024

Purpose: To generate three sets of random numbers.
***************************************************************/

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

const int    NUM_FIRST_SET             = 45;
const int    MAXIMUM_VALUES_SECOND_SET = 75;
const int    MAXIMUM_VALUES_THIRD_SET  = 50;
const double MIN_RANGE_THIRD_SET       = 0.0f;
const double MAX_RANGE_THIRD_SET       = 300.0f;
const int    VALUES_PER_LINE           = 7;
const int    VALUE_ENTRY_WIDTH         = 13;

/**
 * @brief Outputs a value padded to VALUE_ENTRY_WIDTH with an asterisk if needed.
 *
 * @param int, double Input to be outputted
 * @param bool Whether to add the asterisk
 */
void cout_int_with_asterisk ( int input, bool needs_asterisk ) {
    cout << setw(VALUE_ENTRY_WIDTH) << right << input << ( needs_asterisk ? "*" : " " );
}
void cout_double_with_asterisk ( double input, bool needs_asterisk ) {
    cout << setw(VALUE_ENTRY_WIDTH) << right << fixed << setprecision(1) << input << ( needs_asterisk ? "*" : " " );
}


/**
 * @brief Outputs Set One, which is NUM_FIRST_SET random numbers.
 */
void set_one () {
// Display label for set 1
    cout << "Set 1 has exactly " << NUM_FIRST_SET << " values" << endl;


    // Output NUM_FIRST_SET values on lines with VALUES_PER_LINE values each.
    int first_set_odd_count = 0;
    for ( int first_set_ind = 0; first_set_ind < NUM_FIRST_SET; first_set_ind++ ) {
        // If it's the first entry in a line (but not the first period), create a new line
        if ( first_set_ind > 0 && first_set_ind % VALUES_PER_LINE == 0 )
            cout << endl;

        // Generate a number and check if it's odd
        int num = rand();
        bool is_odd = num % 2 == 1;

        // Check if the number is odd
        if ( is_odd )
            first_set_odd_count ++;

        // Output the number, and an asterisk if it's odd
        cout_int_with_asterisk( num, is_odd );
    }

    cout << endl << endl << "There are " << first_set_odd_count << " odd numbers in Set 1" << endl << endl;
}
/**
 * @brief Outputs Set Two, which is a random maximum of MAXIMUM_VALUES_SECOND_SET
 *        random numbers.
 */
void set_two () {
        // Determine how many values will be included in the second set.
    int values_second_set = rand() % MAXIMUM_VALUES_SECOND_SET + 1;

    // Display label for set 2
    cout << "Set 2 has exactly " << values_second_set << " values" << endl;

    // Output <second_set_ind> values on lines with 7 values each.
    int second_set_even_count = 0;
    int second_set_ind = 0;
    while ( second_set_ind < values_second_set ) {
        // If it's the first entry in a line (but not the first period), create a new line
        if ( second_set_ind > 0 && second_set_ind % VALUES_PER_LINE == 0 )
            cout << endl;

        // Generate a number and check if it's even
        int num = rand();
        bool is_even = num % 2 == 0;
        
        // Check if the number is even
        if ( is_even )
            second_set_even_count ++;

        // Output the number, and an asterisk if it's even
        cout_int_with_asterisk( num, is_even );

        second_set_ind++;
    }

    cout << endl << endl << "There are " << second_set_even_count << " even numbers in Set 2" << endl << endl;
}
/**
 * @brief Outputs Set Three, which is a random maximum of MAXIMUM_VALUES_THIRD_SET
 *        random numbers between MIN_RANGE_THIRD_SET and MAX_RANGE_THIRD_SET.
 */
void set_three () {
    // Determine how many values will be included in the second set.
    int values_third_set = rand() % MAXIMUM_VALUES_THIRD_SET + 1;

    // Display label for set 3
    cout << "Set 3 has exactly " << values_third_set << " values" << endl;

    // Output <second_set_ind> values on lines with 7 values each.
    int third_set_values_over_200_count = 0;
    int third_set_ind = 0;
    do {
        // If it's the first entry in a line (but not the first period), create a new line
        if ( third_set_ind > 0 && third_set_ind % VALUES_PER_LINE == 0 )
            cout << endl;

        
        // Generate a number and check if it's even
        double num = rand() / (RAND_MAX / (MAX_RANGE_THIRD_SET - MIN_RANGE_THIRD_SET)) + MIN_RANGE_THIRD_SET;
        bool is_over_200 = num > 200.0f;
        
        // Check if the number is even
        if ( is_over_200 )
            third_set_values_over_200_count ++;

        // Output the number, and an asterisk if it's even
        cout_double_with_asterisk( num, is_over_200 );

        third_set_ind++;
    } while (third_set_ind < values_third_set);

    cout << endl << endl << "There are " << third_set_values_over_200_count << " numbers greater than 200.0 in Set 3" << endl;
}

int main(){
    // Set the seed of random to be 33
    srand(33);

    // Run the three sets
    set_one();
    set_two();
    set_three();
}