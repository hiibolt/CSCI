/***************************************************************
CSCI 240         Program 5     Spring 2024

Programmer: John White (z1994244)

Section: 240-0002

Date Due: March 8st, 2024

Purpose: To improve upon the previous calculator.
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

// Input functions
int get_value ( string );
int get_nonzero_value ( string );
int get_nonnegative_value ( string );
char menu ( string );

// Operation functions
int addition ( int, int );
int subtraction ( int, int );
int division ( int, int );
int multiplication ( int, int );
int quotient ( int, int );
int remainder ( int, int );
int power ( int, int );
int factorial ( int );

int main(){

    while ( true ) {
        char op = menu( 
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

            int num = get_nonnegative_value("Input a (non-negative) number: ");

            cout << "\nCompleted operation: " << num << "! = " << factorial( num ) << endl << endl << endl;
            continue;
        }

        // Get number 1
        cout << "\nCurrent planned operation: _ " << op << " _ " << endl;
        int num_1 = get_value("Input the first number: ");

        // Get number 2
        cout << "\nCurrent planned operation: " << num_1 << " " << op << " _ " << endl;
        
        // We need to handle two edge cases,
        // division (cannot divide by zero)
        // and exponentiation (cannot exponentiate
        // with a negative number)
        int num_2;
        if ( op == '/' ) {
            num_2 = get_nonzero_value("Input the second (non-zero) number: ");
        } else if ( op == '^') {
            num_2 = get_nonnegative_value("Input the second (non-negative) number: ");
        } else {
            num_2 = get_value("Input the second number: ");
        }

        switch ( op ) {
            case '+':
                cout << "\nCompleted operation: " << num_1 << " + " << num_2 << " = " << addition(num_1, num_2) << endl << endl << endl;
                break;
            case '-':
                cout << "\nCompleted operation: " << num_1 << " - " << num_2 << " = " << subtraction(num_1, num_2) << endl << endl << endl;
                break;
            case '*':
                cout << "\nCompleted operation: " << num_1 << " * " << num_2 << " = " << multiplication(num_1, num_2) << endl << endl << endl;
                break;
            case '/':
                cout << "\nCompleted operation: " << num_1 << " / " << num_2 << " = " << division(num_1, num_2) << " + " << remainder(num_1, num_2) << endl;
                break;
            case '^':
                cout << "\nCompleted operation: " << num_1 << " ^ " << num_2 << " = " << power(num_1, num_2) << endl << endl << endl;
                break;
        }
    }
}


/**
 * @brief A checked input that prevents an invalid conversion.
 *
 * @param string String which will prompt prior to taking input
 * @return Returns a now-parsed double
 * @note None
 */
int get_value ( string msg ) {
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
 * @brief Wraps get_value, preventing return values of 0.
 *
 * @param string String which will prompt prior to taking input
 * @return Returns an int
 * @note None
 */
int get_nonzero_value ( string msg ) {
    int ret = get_value( msg );

    while ( ret == 0 ) {
        ret = get_value( "\tThat's not a NON-ZERO value, please try again: ");
    }

    return ret;
}
/**
 * @brief Wraps get_value, preventing return values < 0.
 *
 * @param string String which will prompt prior to taking input
 * @return Returns an int
 * @note None
 */
int get_nonnegative_value ( string msg ) {
    int ret = get_value( msg );

    while ( ret < 0 ) {
        ret = get_value( "\tThat's not a NON-NEGATIVE value, please try again: ");
    }

    return ret;
}
/**
 * @brief A checked input that prevents an invalid operators
 *
 * @param string String which will prompt prior to taking input
 * @return Returns a proper operator [ + | - | * | / | ^ | ! | q ]
 * @note Not self-sufficient, requires a pre-defined and in-scope valid operator array
 */
char menu ( string msg ) {
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



/**
 * @brief Adds two ints
 *
 * @param int First number
 * @param int Second number
 * @return The two numbers added
 * @note None
 */
int addition ( int num_1, int num_2 ) {
    return num_1 + num_2;
}
/**
 * @brief Subtracts two ints
 *
 * @param int First number
 * @param int Second number
 * @return The second number subtracted from the first
 * @note None
 */
int subtraction ( int num_1, int num_2 ) {
    return num_1 - num_2;
}
/**
 * @brief Multiplies two ints
 *
 * @param int First number
 * @param int Second number
 * @return The two numbers multiplied
 * @note None
 */
int multiplication ( int num_1, int num_2 ) {
    return num_1 * num_2;
}
/**
 * @brief Divides two ints
 *
 * @param int First number
 * @param int Second number
 * @return The first number divided by the second
 * @note Uses _integer division_.
 */
int division ( int num_1, int num_2 ) {
    return num_1 / num_2;
}
/**
 * @brief Gets the remainder of dividing two ints
 *
 * @param int First number
 * @param int Second number
 * @return The remainder of the divsion of the first number by the second
 * @note None
 */
int remainder ( int num_1, int num_2 ) {
    return num_1 % num_2;
}
/**
 * @brief Exponentiates two ints
 *
 * @param int First number
 * @param int Second number
 * @return The first number exponentiated by the second
 * @note The second number must be non-zero.
 */
int power ( int num_1, int num_2 ) {
    // Basic exponentiation implementation
    int ret = num_1;
    for ( int i = 1; i < num_2; i++ ) {
        ret *= num_1;
    }

    // Zero powers
    if ( num_2 == 0 ) {
        ret = 1;
    }

    return ret;
}
/**
 * @brief Gets the factorial of an int.
 *
 * @param int First number
 * @return The factorial of the first number.
 * @note Doesn't implement the Gamma Function, so 
 *  inputs must be >= 0 and floor(x) must equal x.
 */
int factorial ( int num ) {
    int ret = 1;

    // Multiply all numbers less than num and greater than 1
    for ( int i = 1; i < num + 1; i++ ) {
        ret *= i;
    }

    return ret;
}