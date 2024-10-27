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

int evaluate(const std::string& postfix) {
	// Create our `stringstream` to make reading 
	//  extremely convenient
	std::stringstream ss ( postfix );

	// Define our buffers and eval stack
	std::string op;
	mystack eval_stack;

	while ( ss >> op ) {
		if ( isdigit( op[0] ) ) {
			eval_stack.push( stoi(op) );

			continue;
		}

		if ( isalpha( op[0] ) ) {
			int value = op[0] - 'a';
			eval_stack.push( value );

			continue;
		}

		if ( op[0] == '~' ) {
			int top = eval_stack.top();

			eval_stack.pop();
			eval_stack.push( -1 * top );

			continue;
		}

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
