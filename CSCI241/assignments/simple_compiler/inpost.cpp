/***************************************************************
CSCI 241         John White     Spring 2024

Programmer: z19942444

Section: 241-0002

Date Due: October 27th

Purpose: To convert an infix expression to postfix
***************************************************************/

/*

    /ᐠ - ˕ -マ

    @hiibolt on GitHub 

*/


#include <string>
#include <iostream>
#include <cctype>

#include "inpost.h"
#include "mystack.h"


std::string convert ( const std::string& _infix ) {
	// Define our operator stack and postfix buffer
	mystack opstack = mystack();
	std::string postfix;

	// Get our infix and surround it with
	//  another set of parenthesis (this way,
	//  we don't have to do a final step)
	std::string infix = _infix;
	infix.insert( infix.begin(), '(' );
	infix += ')';

	// Primary loop
	for ( size_t i = 0; i < infix.size(); i ++ ) {
		// Digits
		if ( isdigit( infix[i] ) ) {
			// Append the first digit
			postfix += infix[i];

			// Append all subsequential digits as well
			while ( i + 1 < infix.size() && isdigit( infix[ i + 1 ] ) ) {
				i ++;
				postfix += infix[i];
			}

			// Add a space and move on
			postfix += ' ';
			continue;
		}

		// Variables 
		if ( isalpha( infix[i] ) ) {
			// Append the variable
			postfix += infix[i];

			// Add a space and move on
			postfix += ' ';
			continue;
		}

		// Parentheses
		if ( infix[i] == '(' ) {
			// Add the token to the opstack
			opstack.push( '(' );

			continue;
		}
		if ( infix[i] == ')' ) {
			// Remove and append operators until you
			//  reach a left parenthesis
			while ( opstack.top() != '(' ) {
				postfix += opstack.top();
				postfix += ' ';
				
				opstack.pop();
			}

			// Remove the last left parenthesis
			opstack.pop();
			continue;
		}

		// Operators
		switch ( infix[i] ) {
			case '+':
			case '-':
				// Low Precedence Operators
				//
				// Notes:
				// - These ignore only a left parenthesis
				while ( !opstack.empty() && opstack.top() != '(' ) {
					postfix += opstack.top();
					postfix += ' ';

					opstack.pop();
				}
				
				opstack.push( infix[i] );
				break;
			case '*':
			case '/':
				// Medium Precendence Opertors 
				//
				// Notes:
				// - These ignore the above as well as '+' and '-'
				while ( !opstack.empty() &&
					 opstack.top() != '(' && 
					 opstack.top() != '+' && 
					 opstack.top() != '-' ) {
					postfix += opstack.top();
					postfix += ' ';

					opstack.pop();
				}

				opstack.push( infix[i] );

				break;
			case '~':
			case '^':
				// High Precedence Operators
				//
				// Notes:
				// - These ignore the above as well as '~' and '^'
				while ( !opstack.empty() && opstack.top() != '(' &&
					 opstack.top() != '+' && 
					 opstack.top() != '-' &&
					 opstack.top() != '*' && 
					 opstack.top() != '/' ) {
					//std::cout << ":3 - " << opstack.top();

					postfix += opstack.top();
					postfix += ' ';

					opstack.pop();
				}

				opstack.push( infix[i] );

				break;
			default:
				// Whitespace or invalid character,
				//  ignore and move on
				continue;
		}
	}

	// Finally, return our result
	return postfix;
}
