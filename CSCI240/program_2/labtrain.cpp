/***************************************************************
CSCI 240         Program 1     Fall 2019

Programmer: John White

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

const short int LABEL_GRAPHEME_WIDTH = 20;
const short int VALUE_GRAPHEME_WIDTH = 11;

using namespace std;

/**
 * @brief A checked input that prevents an invalid conversion.
 *
 * @param string String which will prompt prior to taking input
 * @return Returns a now-parsed double
 */
int checked_input ( string msg ) {
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

/**
 * @brief An object representing a mathematical parabola.
 *
 * It's worth noting that the coefficients are
 * integers, while the x and y vertices are doubles.
 */
class Parabola {
    int a_coefficient = 0;
    int b_coefficient;
    int c_coefficient;

    double vertex_x;
    double vertex_y;
public:
    /**
    * @brief Constructor that accepts three input arguments via stdin
    * and generates the X and Y coordinates of the vertex.
    *
    * @return Returns a Parabola object.
    */
    Parabola () {
        // The a coefficient must be non-zero to prevent div_by_zero
        while ( !a_coefficient ) {
            a_coefficient = checked_input("Enter the a coefficient: ");

            if ( !a_coefficient ) {
                cout << "\tMust be non-zero!" << endl;
            }
        }
        b_coefficient = checked_input("Enter the b coefficient: ");
        c_coefficient = checked_input("Enter the c coefficient: ");

        cout << "\n\n";
        
        // Calculate the X and Y vertex based their standard mathematical formulas
        vertex_x = (double) -b_coefficient / (2 * a_coefficient); 
        vertex_y = ( (double) a_coefficient * pow(vertex_x, 2) ) + ( b_coefficient * vertex_x ) + c_coefficient;
    }


    /**
    * @brief Outputs a human-readable representation of self to stdout.
    */
    void display () {
        cout << "-------------------------------\n"
                "  Quadratic Equation Analyzer\n"
                "-------------------------------" << endl;

        // Output base coefficients, with labels padded 20W-L and values 11W-R
        // (Rounded to 4 digits)
        cout << left << setw(LABEL_GRAPHEME_WIDTH) << "a Coefficient" << right << setw(VALUE_GRAPHEME_WIDTH) << setprecision(4) << a_coefficient << endl;
        cout << left << setw(LABEL_GRAPHEME_WIDTH) << "b Coefficient" << right << setw(VALUE_GRAPHEME_WIDTH) << setprecision(4) << b_coefficient << endl;
        cout << left << setw(LABEL_GRAPHEME_WIDTH) << "c Coefficient" << right << setw(VALUE_GRAPHEME_WIDTH) << setprecision(4) << c_coefficient << endl;
        
        cout << "-------------------------------\n"
                "Vertex" << endl;
        
        // Output the vertice coordinates with labes padded 20W-L and values 11W-R 
        // (Rounded to 4 digits)
        cout << left << setw(LABEL_GRAPHEME_WIDTH) << "X Coordinate" << right << setw(VALUE_GRAPHEME_WIDTH) << fixed << setprecision(4) << vertex_x << endl;
        cout << left << setw(LABEL_GRAPHEME_WIDTH) << "Y Coordinate" << right << setw(VALUE_GRAPHEME_WIDTH) << fixed << setprecision(4) << vertex_y << endl;
    }
};

int main () {
    Parabola parabola;
    
    parabola.display();

    return 0;
}