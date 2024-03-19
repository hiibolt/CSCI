/***************************************************************
CSCI 240         Program 7     Spring 2024

Programmer: John W (z1994244)

Section: 240-0002

Date Due: March 22nd

Purpose: Use file IO to gather data and perform a statistical
 analysis, while maintaining file safety.
***************************************************************/

/*

    /ᐠ - ˕ -マ

    @hiibolt on GitHub 

*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <array>
#include <string>
#include <cmath>

using namespace std;


/* Constants */
#define DATASET_SIZE 20
#define EOF_MARKER -999.99
#define ENTRY_PRINT_WIDTH 8


/* Array Manipulation */
void print_array ( string,  double*, int );
void sort_array  ( double*, int          );
int  build_array ( string,  double*      );

/* Data Analytics */
double mean               ( double*, int );
double median             ( double*, int );
double low                ( double*, int );
double high               ( double*, int );
double standard_deviation ( double*, int );

int main(){
    double dataset_a[DATASET_SIZE];
    double dataset_b[DATASET_SIZE];

    // Build the arrays
    int dataset_a_len = build_array( "./data7A.txt", dataset_a );
    int dataset_b_len = build_array( "./data7B.txt", dataset_b );

    print_array( "Unsorted Set A", dataset_a, dataset_a_len );
    print_array( "Unsorted Set B", dataset_b, dataset_b_len );

    // Sort the arrays
    sort_array( dataset_a, dataset_a_len );
    sort_array( dataset_b, dataset_b_len );

    print_array( "Sorted Set A", dataset_a, dataset_a_len );
    print_array( "Sorted Set B", dataset_b, dataset_b_len );

    // Analyze dataset A
    double dataset_a_mean   = mean               ( dataset_a, dataset_a_len );
    double dataset_a_median = median             ( dataset_a, dataset_a_len );
    double dataset_a_low    = low                ( dataset_a, dataset_a_len );
    double dataset_a_high   = high               ( dataset_a, dataset_a_len );
    double dataset_a_dev    = standard_deviation ( dataset_a, dataset_a_len );

    cout << "Set A Statistics" << endl << endl <<
            " | Mean: "               << dataset_a_mean   << endl <<
            " | Median: "             << dataset_a_median << endl <<
            " | Low: "                << dataset_a_low    << endl <<
            " | High: "               << dataset_a_high   << endl <<
            " | Standard Deviation: " << dataset_a_dev    << endl << endl;

    // Analyze dataset B
    double dataset_b_mean   = mean               ( dataset_b, dataset_b_len );
    double dataset_b_median = median             ( dataset_b, dataset_b_len );
    double dataset_b_low    = low                ( dataset_b, dataset_b_len );
    double dataset_b_high   = high               ( dataset_b, dataset_b_len );
    double dataset_b_dev    = standard_deviation ( dataset_b, dataset_b_len );

    cout << "Set B Statistics" << endl << endl <<
            " | Mean: "               << dataset_b_mean   << endl <<
            " | Median: "             << dataset_b_median << endl <<
            " | Low: "                << dataset_b_low    << endl <<
            " | High: "               << dataset_b_high   << endl <<
            " | Standard Deviation: " << dataset_b_dev    << endl << endl;

    // Analyze the differences between dataset A and B
    double difference_mean   = abs( dataset_a_mean   - dataset_b_mean   );
    double difference_median = abs( dataset_a_median - dataset_b_median );
    double difference_dev    = abs( dataset_a_dev    - dataset_b_dev    );

    cout << "Difference between Set A vs Set B (abs value)" << endl << endl <<
            " | Mean: "               << difference_mean   << endl <<
            " | Median: "             << difference_median << endl <<
            " | Standard Deviation: " << difference_dev    << endl;
}

/**
 * @brief Calculates the mean of an array.
 *
 * @param double* Pointer to input array to be printed
 * @param int The number of values in the array
 */
double mean ( double* array, int array_len ) {
    double total = 0;

    for ( int i = 0; i < array_len; ++i ) {
        total += array[i];
    }
    
    return total / array_len;
}
/**
 * @brief Calculates the median value of an array.
 *
 * @param double* Pointer to input array to be printed
 * @param int The number of values in the array
 */
double median ( double* array, int array_len ) {
    return array[array_len / 2];
}
/**
 * @brief Calculates the lowest value of an array.
 *
 * @param double* Pointer to input array to be printed
 * @param int The number of values in the array
 */
double low ( double* array, int array_len ) {
    double smallest = array[0];

    for ( int i = 1; i < array_len; ++i ) {
        smallest = min( smallest, array[i] );
    }

    return smallest;
}
/**
 * @brief Calculates the highest value of an array.
 *
 * @param double* Pointer to input array to be printed
 * @param int The number of values in the array
 */
double high ( double* array, int array_len ) {
    double largest = array[0];

    for ( int i = 1; i < array_len; ++i ) {
        largest = max( largest, array[i] );
    }

    return largest;
}
/**
 * @brief Calculates the standard deviation of an array.
 *
 * @param double* Pointer to input array to be printed
 * @param int The number of values in the array
 */
double standard_deviation ( double* array, int array_len ) {
    // Calculate \suma{x^2}
    double sum_array_squared = 0;
    for ( int i = 0; i < array_len; ++i ) {
        sum_array_squared += pow(array[i], 2);
    }

    // Calculate \suma{x}
    double sum_array = 0;
    for ( int i = 0; i < array_len; ++i ) {
        sum_array += array[i];
    }
    
    // Calculate \sqrt{\frac{ \suma{x^2} - \frac{\suma{x}^2}{n} }{ n - 1 }}
    return sqrt( ( sum_array_squared - ( pow(sum_array, 2) / array_len ) ) / ( array_len - 1 ));
}
/**
 * @brief Print an array.
 *
 * @param string Title heading the array output
 * @param double* Pointer to input array to be printed
 * @param int The number of values in the array
 */
void print_array ( string title, double* array, int array_len ) {
    // Print the title
    cout << title << endl << endl;

    for ( int i = 0; i < array_len; i ++ ) {
        cout << right << fixed << setprecision(2) << setw(ENTRY_PRINT_WIDTH) << array[i] << " ";

        // Ensure 8 values per line
        if ( (i + 1) % 8 == 0 ) {
            cout << endl;
        }
    }

    cout << endl << endl;
}
/**
 * @brief Sorts an array using the selection sort approach.
 *
 * @param double* Pointer to input array to be printed
 * @param int The number of values in the array
 */
void sort_array ( double* array, int array_len ) {
    int marker = 0;

    // Move the morker throughout the whole array
    while ( marker < array_len ) {
        // Start the smallest at the marker
        double smallest = array[marker];
        int smallest_index = marker;

        // Find the smallest element right of the marker
        for ( int i = marker; i < array_len; i++ ) {
            // Ignore if it's equal or larger than the marker
            if ( array[i] >= smallest ) {
                continue;
            }

            // Update the smallest entry
            smallest = array[i];
            smallest_index = i;
        }

        // Swap the marker and the smallest entry
        array[smallest_index] = array[marker];
        array[marker] = smallest;

        marker ++;
    }
}
/**
 * @brief Reads as many values as possible to an array
 * from a filename.
 *
 * @param string String representing the relative input path
 * @param double[] Input array
 * @return Returns the number of elements read to array
 */
int build_array( string path, double* input_array ) {
    ifstream input_file;

    // Open the file
    input_file.open( path );

    // Verify the file opened
    if( input_file.fail() ) {
        cout << "Failed to open '" << path << "'! Is the file present and not in use?" << endl;
        exit(-1);
    }

    // Define an input string and index for holding our total elements written
    int index = 0;
    string line;

    // Read file while we're under the array max
    while ( !input_file.eof() && index < DATASET_SIZE ) {
        // Read the next character
        char next_char;
        input_file.get(next_char);

        // If it's not the endline, add it and move on
        if ( next_char != '\n' && !input_file.eof() ) {
            line += next_char;
            continue;
        }

        // Ensure we're not looking at the arbitrary EOF marker
        if ( stod(line) == EOF_MARKER ) {
            input_file.close();
            return index;
        }

        // Assign the value to the proper array index
        input_array[index] = stod(line);

        // Reset the line and increment our index
        index ++;
        line = "";
        continue;
    }

    // Close the input file
    input_file.close();

    return index;
}