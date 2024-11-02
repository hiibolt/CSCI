/***************************************************************
CSCI 241         John White     Spring 2024

Programmer: z19942444

Section: 241-0002

Date Due: ASAP

Purpose: Evaluate a postfix expression with a linked stack
***************************************************************/

/*

    /ᐠ - ˕ -マ

    @hiibolt on GitHub 

*/


#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cmath>

#include "eval.h"
#include "mystack.h"

/**
 * @brief Evaluate a postfix expression
 * 
 * @param postfix The postfix expression to evaluate
 *
 * @return int The result of the evaluation
 */
int evaluate ( const std::string& postfix ) {
	// Create our `stringstream` to make reading 
	//  extremely convenient
	std::stringstream ss ( postfix );

	// Define our buffers and eval stack
	std::string op;
	mystack eval_stack;

	// Loop through the postfix expression
	while ( ss >> op ) {
		// If the operator is a digit, push it to the stack
		if ( isdigit( op[0] ) ) {
			eval_stack.push( stoi(op) );

			continue;
		}

		// If the operator is a letter, push the value of the letter
		if ( isalpha( op[0] ) ) {
			int value = op[0] - 'a';
			eval_stack.push( value );

			continue;
		}

		// If the operator is a ~, negate the top of the stack
		if ( op[0] == '~' ) {
			int top = eval_stack.top();

			eval_stack.pop();
			eval_stack.push( -1 * top );

			continue;
		}

		// If the operator is a +, -, *, /, or ^, perform the operation
		if ( op[0] == '+' || op[0] == '-' || op[0] == '*' || op[0] == '/' || op [0] == '^' ) {
			int rhs = eval_stack.top(); eval_stack.pop();
			int lhs = eval_stack.top(); eval_stack.pop();

			switch ( op[0] ) {
				case '+':
					eval_stack.push( lhs + rhs );
					break;
				case '-':
					eval_stack.push( lhs - rhs );
					break;
				case '*':
					eval_stack.push( lhs * rhs );
					break;
				case '/':
					// Check for division by 0
					if ( rhs == 0 ) {
						std::cout << "*** Division by 0 ***" << std::endl;
						return 0;
					}
					
					eval_stack.push( lhs / rhs );
					break;
				case '^':
					eval_stack.push( pow( lhs, rhs ) );
					break;
			}
		}
	}

	// Return
	return eval_stack.top();
};
