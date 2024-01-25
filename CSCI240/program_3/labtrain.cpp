/***************************************************************
CSCI 240         Program 3     Spring 2024

Programmer: John White (z1994244)

Section: 240-0002

Date Due: Feb 9th, 2024

Purpose: The purpose of this program is to calculate and display
         the vertex, probable roots, and concavity of a mathematical
         parabola given its coefficients.

         The user provides the a, b, and c coefficients of the parabola.
***************************************************************/

#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

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

    string concavity = "NO CONCAVITY";
    vector<double> roots;
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
        
        /* Calculate the X and Y vertex based their standard mathematical formulas */
        vertex_x = (double) -b_coefficient / (2 * a_coefficient); 
        vertex_y = ( (double) a_coefficient * pow(vertex_x, 2) ) + ( b_coefficient * vertex_x ) + c_coefficient;

        /* Calculate the concavity */
        concavity = a_coefficient < 0 ? "DOWNWARD" : "UPWARD";

        /* Calculate roots */
        // First, check if there can be roots at all.
        // There are two edge cases to check for:
        // Negative concavity and a vertex below y = 0
        // Positive concavity and a vertex above y = 0
        if ((concavity == "DOWNWARD" && vertex_y < 0) || (concavity == "UPWARD" && vertex_y > 0)) {
            return;
        }

        // Calculate the discriminant
        double discriminant = pow(b_coefficient, 2) - (4 * a_coefficient * c_coefficient);

        // We do not need to check if the discriminant is negative because of our above edge cases.
        // There will always be one root at this point in the program.
        roots.push_back( ( -b_coefficient + sqrt( discriminant )) / ( 2 * a_coefficient ) );

        // The second root can only exist if the discriminant is greater than zero.
        if ( discriminant > 0 ) {
            roots.push_back( ( -b_coefficient - sqrt( discriminant )) / ( 2 * a_coefficient ) );
        }
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
        cout << left << setw(LABEL_GRAPHEME_WIDTH) << "a Coefficient" << right << setw(VALUE_GRAPHEME_WIDTH) << setprecision(3) << a_coefficient << endl;
        cout << left << setw(LABEL_GRAPHEME_WIDTH) << "b Coefficient" << right << setw(VALUE_GRAPHEME_WIDTH) << setprecision(3) << b_coefficient << endl;
        cout << left << setw(LABEL_GRAPHEME_WIDTH) << "c Coefficient" << right << setw(VALUE_GRAPHEME_WIDTH) << setprecision(3) << c_coefficient << endl;
        
        cout << "-------------------------------\n"
                "Vertex" << endl;
        
        // Output the vertice coordinates with labes padded 20W-L and values 11W-R 
        // (Rounded to 4 digits)
        cout << left << setw(LABEL_GRAPHEME_WIDTH) << "X Coordinate" << right << setw(VALUE_GRAPHEME_WIDTH) << fixed << setprecision(3) << vertex_x << endl;
        cout << left << setw(LABEL_GRAPHEME_WIDTH) << "Y Coordinate" << right << setw(VALUE_GRAPHEME_WIDTH) << fixed << setprecision(3) << vertex_y << endl;

        // Output the concavity of the parabola
        cout << "-------------------------------\n"
                "The parabola opens " << concavity << endl;

        // Count the number of roots
        cout << "-------------------------------\n"
                "The parabola has " 
                << (roots.size() == 0 ? "NO roots" : (roots.size() == 1 ? "ONE root" : "TWO roots"))
                << endl;

        // Iterate and output each root
        for ( vector<double>::size_type i = 0; i < roots.size(); i++ ) {
            string label = "Root " + to_string(i + 1) + " - X Coordinate";

            cout << left << setw(LABEL_GRAPHEME_WIDTH) 
                << label
                << right << setw(VALUE_GRAPHEME_WIDTH) << fixed << setprecision(3) 
                << roots[i] << endl;
        }
    }
};

int main () {
    Parabola parabola;
    
    parabola.display();

    return 0;
}