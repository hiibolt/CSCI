/***************************************************************
CSCI 240         Program 5     Spring 2024

Programmer: John White (z1994244)

Section: 240-0002

Date Due: March 1st, 2024

Purpose: To calculate the value of a given expression via 
 checked user input.
***************************************************************/

/*

    /ᐠ - ˕ -マ

    @hiibolt on GitHub 

*/

#include <iostream>
#include <array>
#include <algorithm>
#include <string>

using namespace std;

const array<char, 7> operators = {'+', '-', '*', '/', '^', '!', 'q'};

/**
 * @brief A checked input that prevents an invalid conversion.
 *
 * @param string String which will prompt prior to taking input
 * @return Returns a now-parsed double
 */
int checked_int_input ( string msg ) {
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
 * @brief A checked input that prevents an invalid operators
 *
 * @param string String which will prompt prior to taking input
 * @return Returns a proper operator [ + | - | * | / | ^ | ! | q ]
 */
char checked_operator_input ( string msg ) {
    char ret;

    // Continually ask for input until manual loop termination
    while ( true ) {
        // Output template message and direct to input string
        cout << msg;
        cin >> ret;

        // Check if it's in the operators array
        if ( find(operators.begin(), operators.end(), tolower(ret)) != operators.end() ) {
            break;
        }

        cout << "That is an invalid operation!\n\n" << endl;
    }

    return tolower(ret);
}

int main(){

    while ( true ) {
        char op = checked_operator_input( 
            "What operation would you like to perform:\n"
            "\t+ addition\n"
            "\t- subtraction\n"
            "\t* multiplication\n"
            "\t/ division\n"
            "\t^ exponentiation\n"
            "\t! factorial\n"
            "\tq quit\n\n"
            "Operation? "
        );
        
        // Exit operator
        if ( op == 'q' ) {
            break;
        }

        // Factorial only uses one input, we must deal
        // with it seperately.
        if ( op == '!' ) {
            cout << "\nCurrent planned operation: _!" << endl;

            int num = checked_int_input("Input the number: ");

            // I think the Gamma Function is a bit out of scope,
            // so we will only allow positive integers
            if ( num < 0 ) {
                cout << "This factorial implementation does not use the Gamma Function. Please use a *positive integer*." << endl;

                continue;
            }

            // Basic factorial implementation
            int ret = 1;
            for ( int i = 1; i < num + 1; i++ ) {
                ret *= i;
            }

            cout << "\nCompleted operation: " << num << "! = " << ret << endl << endl << endl;
            continue;
        }

        // Get number 1
        cout << "\nCurrent planned operation: _ " << op << " _ " << endl;
        int num_1 = checked_int_input("Input the first number: ");

        // Get number 2
        cout << "\nCurrent planned operation: " << num_1 << " " << op << " _ " << endl;
        int num_2 = checked_int_input("Input the second number: ");

        // Edge case for division by zero
        if ( op == '/' ) {
            while ( num_2 == 0 ) {
                cout << "\tYou cannot divide by zero!" << endl;
                num_2 = checked_int_input("Input the second number: ");
            }
        }

        switch ( op ) {
            case '+':
                cout << "\nCompleted operation: " << num_1 << " + " << num_2 << " = " << (num_1 + num_2) << endl << endl << endl;
                break;
            case '-':
                cout << "\nCompleted operation: " << num_1 << " - " << num_2 << " = " << (num_1 - num_2) << endl << endl << endl;
                break;
            case '*':
                cout << "\nCompleted operation: " << num_1 << " * " << num_2 << " = " << (num_1 * num_2) << endl << endl << endl;
                break;
            case '/':
                cout << "\nCompleted operation: " << num_1 << " / " << num_2 << " = " << (num_1 / num_2) << endl;
                
                // Remainder
                if ( num_1 % num_2 != 0 ) {
                    // It's worth noting that this is technically
                    // wrong, C++ has a seperate function which
                    // properly generates the remainder for negative
                    // numbers. However, I doubt you're expecting that.
                    cout << "\tWith remainder: " << (num_1 % num_2) << endl << endl << endl;
                }
                break;
            case '^':
                // Basic exponentiation implementation
                double ret = num_1;
                for ( int i = 1; i < abs(num_2); i++ ) {
                    ret *= num_1;
                }

                // Zero powers
                if ( num_2 == 0 ) {
                    ret = 1;
                }

                // Negative powers
                if ( num_2 < 0 ) {
                    ret = 1 / ret;
                }

                cout << "\nCompleted operation: " << num_1 << " ^ " << num_2 << " = " << ret << endl << endl << endl;
                break;
        }
    }
}