/***************************************************************
*                            scc.cpp
*
*
* CSCI 241         John White     Fall 2024
*
* Programmer: z19942444
*
* Section: 241-0002
*
* Date Due: ASAP
*
* Purpose: Implement a Simple Compiler which converts Simple
*          programs into SimpleSim programs.
***************************************************************/

/*

    /ᐠ - ˕ -マ

    @hiibolt on GitHub 

*/



#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cctype>
#include <cstdlib>

#include "scc.h"
#include "mystack.h"
#include "sml.h"
#include "inpost.h"



/**
 * @brief Default contructor for the scc class
 */
scc::scc ( ) {
	// 7777 represents an empty memory location,
	//  and -1 represents an empty flag, which
	//  we must use to fill the memory and flags
	for ( int i = 0; i < MEMORY_SIZE; i++ ) {
		memory[i] = 7777;
		flags[i] = -1;
	}
};
/**
 * @brief First pass of the Simple Compiler
 *
 * @notes This function reads in the Simple program,
 *        and processes it into a SimpleSim program.
 *        It accomplishes this by reading in the Simple
 *        program line by line, and processing each line
 *        into a SimpleSim instruction.
 */
void scc::first_pass ( ) {
	// Define our line buffer
	std::string line;

	// Repeatedly read in lines from standard input
	while ( getline( std::cin, line ) ) {
		// Define our line number and command
		std::string line_number_str;
		std::string command;

		// Create a stringstream from the line
		std::stringstream line_ss(line);
		
		// Extract the line number and command
		line_ss >> line_number_str;
		line_ss >> command;

		// Convert the line number to an integer, as
		//  an entry uses integers for line numbers
		int line_number = std::stoi ( line_number_str );

		// Process the line number into a 
		//  new symbol table entry
		this->symbol_table[ this->next_symbol_table_idx ] = table_entry {
			line_number,
			'L',
			this->next_instruction_addr
		};
		next_symbol_table_idx ++;
		
		// Next, process the command
		if ( command == "data" ) {
			this->process_data( &line_ss );
		} else if ( command == "input" || command == "print" ) {
			this->process_print_input( &line_ss, command );
		} else if ( command == "goto" ) {
			this->process_goto( &line_ss );
		} else if ( command == "if" ) {
			this->process_if( &line_ss );
		} else if ( command == "let" ) {
			this->process_let ( &line_ss );
		} else if ( command == "end" ) {
			this->process_end ( &line_ss );
		}
	}
};
/**
 * @brief Second pass of the Simple Compiler
 *
 * @notes This function completes the SimpleSim program
 *        by filling in any missing addresses in the
 *        SimpleSim program. It accomplishes this by
 *        traversing the flags array, and completing
 *        any instructions that are missing addresses.
 */
void scc::second_pass ( ) {
	// Traverse the `flags` array to complete
	//  any instructions missing addresses
	for ( int i = 0; i < MEMORY_SIZE; i++ ) {
		if ( this->flags[i] == -1 ) {
			continue;
		}

		// Handle forward references
		if ( this->flags[i] > 0 ) {
			// Find the specifed address
			int address = -1;
			for ( int j = 0; j < this->next_symbol_table_idx; j++ ) {
				table_entry entry = this->symbol_table[j];

				if ( entry.type == 'L' && entry.symbol == this->flags[i] ) {
					address = entry.location;
				}
			}

			memory[i] += address;
		}

		// Handle stack references
		if ( this->flags[i] < -1 ) {
			int stack_top = this->next_const_or_var_addr - (-3 - this->flags[i] + 1); 
			
			// Check for stack overflow
			if ( stack_top == next_instruction_addr - 1 ) {
				std::cout << "*** ERROR: insufficient stack space ***" << std::endl;
				exit( -1 );
			}

			memory[i] += stack_top;
		}
	}
};
/**
 * @brief Print the SimpleSim program
 *
 * @notes This function prints the SimpleSim program
 *        to standard output. It accomplishes this by
 *        printing the memory array, followed by the
 *        data array.
 */
void scc::print_program ( ) const {
	for ( int i = 0; i < MEMORY_SIZE; i++ ) {
		std::cout << ( this->memory[i] < 0 ? "-" : "+" )  
				  << std::setw(4) << std::setfill('0') 
				  << std::abs( this->memory[ i ] ) << std::endl;
	}

	std::cout << "-99999" << std::endl;

	// Next, print all of the data
	for ( int i = 0; i < this->ndata; i++ ) {
		std::cout << this->data[ i ] << std::endl;
	}
};

/**
 * @brief Add an instruction to the SimpleSim program
 *
 * @param instruction The instruction to add
 * @param flag        The flag to add
 *
 * @notes This function adds an instruction to the
 *        SimpleSim program. It accomplishes this by
 *        adding the instruction to the memory array,
 *        and the flag to the flags array.
 */
void scc::add_instruction ( int instruction, int flag ) {
	// Check for memory overflow
	if ( next_instruction_addr >= MEMORY_SIZE - 1 ) {	
		std::cout << "*** ERROR: ran out of Simplesim memory ***" << std::endl;
		exit( -1 );
	}

	this->memory[ this->next_instruction_addr ] = instruction;
	this->flags[ this->next_instruction_addr ] = flag;
	this->next_instruction_addr ++;
}
/**
 * @brief Find or insert a variable into the symbol table
 *
 * @param symbol The symbol to find or insert
 *
 * @return The memory address of the variable
 *
 * @notes This function finds or inserts a variable into
 *        the symbol table. It accomplishes this by
 *        searching the symbol table for the variable,
 *        and returning the memory address if found. If
 *        the variable is not found, it is inserted into
 *        the symbol table, and the memory address is
 *        returned.
 */
int scc::find_or_insert_var ( int symbol ) {
	int mem_address = -1;

	// Check if it already exists
	for ( int i = 0; i < this->next_symbol_table_idx; i ++ ) {
		table_entry entry = this->symbol_table[i];

		if ( entry.type == 'V' && entry.symbol == symbol ) {
			mem_address = entry.location;
		}
	}

	// Otherwise, create it
	if ( mem_address == -1 ) {
		// Check for memory overflow
		if ( this->next_const_or_var_addr >= MEMORY_SIZE ) {
			std::cout << "*** ERROR: ran out Simplesim memory ***" << std::endl;
			exit( -1 );
		}
		mem_address = this->next_const_or_var_addr;

		// Add the zeroing instruction
		this->memory[ mem_address ] = 0000;

		// Add the symbol entry
		this->symbol_table[ this->next_symbol_table_idx ] = table_entry {
			symbol,
			'V',
			this->next_const_or_var_addr
		};
		this->next_symbol_table_idx ++;
		this->next_const_or_var_addr --;
	}

	// Return what we found
	return mem_address;
};
/**
 * @brief Find or insert a constant into the symbol table
 *
 * @param symbol The symbol to find or insert
 *
 * @return The memory address of the constant
 *
 * @notes This function finds or inserts a constant into
 *        the symbol table. It accomplishes this by
 *        searching the symbol table for the constant,
 *        and returning the memory address if found. If
 *        the constant is not found, it is inserted into
 *        the symbol table, and the memory address is
 *        returned.
 */
int scc::find_or_insert_con ( int symbol ) {
	int mem_address = -1;

	// Check if it already exists
	for ( int i = 0; i < this->next_symbol_table_idx; i ++ ) {
		table_entry entry = this->symbol_table[i];

		if ( entry.type == 'C' && entry.symbol == symbol ) {
			mem_address = entry.location;
		}
	}

	// Otherwise, create it
	if ( mem_address == -1 ) {
		// Check for memory overflow
		if ( this->next_const_or_var_addr >= MEMORY_SIZE ) {
			std::cout << "*** ERROR: ran out Simplesim memory ***" << std::endl;
			exit( -1 );
		}
		mem_address = this->next_const_or_var_addr;

		// Add the zeroing instruction
		this->memory[ mem_address ] = symbol;

		// Add the symbol entry
		this->symbol_table[ this->next_symbol_table_idx ] = table_entry {
			symbol,
			'C',
			this->next_const_or_var_addr
		};
		this->next_symbol_table_idx ++;
		this->next_const_or_var_addr --;
	}

	// Return what we found
	return mem_address;
};

/**
 * @brief Process a data line
 *
 * @param line_ss The stringstream of the line
 *
 * @notes This function processes a data line. It
 *        accomplishes this by reading in the integer
 *        value, and adding it to the data array.
 */
void scc::process_data ( std::stringstream* line_ss ) {
	// Read the string value of the integer
	std::string new_data_str;
	*line_ss >> new_data_str;
	
	// We need that as an integer to work with it
	int new_data = std::stoi ( new_data_str );

	// Add it to our data, given we have room
	if ( this->ndata >= MEMORY_SIZE - 1 ) {
		std::cout << "*** ERROR: too many data lines ***" << std::endl;
		exit( -1 );
	}	
	this->data[ this->ndata ] = new_data;
	this->ndata ++;
}
/**
 * @brief Process a print or input line
 *
 * @param line_ss The stringstream of the line
 * @param command The command to process
 *
 * @notes This function processes a print or input line.
 *        It accomplishes this by reading in the variable
 *        character, and adding the appropriate instruction
 *        to the SimpleSim program.
 */
void scc::process_print_input ( std::stringstream* line_ss, std::string command ) {
	// Read in the variable character
	std::string var_str;
	*line_ss >> var_str;

	// Get the memory address of the variable
	int mem_address = ( std::isalpha( var_str[0] ) ?
			this->find_or_insert_var ( var_str[0]           ) :
			this->find_or_insert_con ( std::stoi( var_str ) ) );

	// Add the READ or PRINT instruction
	this->add_instruction ( ( command == "input" ? READ : WRITE ) * 100 + mem_address ); 
}
/**
 * @brief Process a goto line
 *
 * @param line_ss The stringstream of the line
 *
 * @notes This function processes a goto line. It
 *        accomplishes this by reading in the line
 *        number, and adding the appropriate instruction
 *        to the SimpleSim program.
 */
void scc::process_goto ( std::stringstream* line_ss ) {
	// Read in the line number as a string
	std::string line_number_str;
	*line_ss >> line_number_str;

	// Convert it to an integer value
	int line_number = std::stoi( line_number_str );
	
	// Check and see if the location exists yet
	int location = -1;
	for ( int i = 0; i < next_symbol_table_idx; i++ ) {
		table_entry entry = this->symbol_table[i];

		if ( entry.type == 'L' && entry.symbol == line_number ) {
			location = entry.location;
		}
	}

	// Add the BRANCH statement
	this->add_instruction(
		BRANCH * 100 + ( location == -1 ? 0 : location ),
		( location == -1 ? line_number : -1 )
	);
}
/**
 * @brief Process an if line
 *
 * @param line_ss The stringstream of the line
 *
 * @notes This function processes an if line. It
 *        accomplishes this by reading in the left
 *        and right hand side, the operator, and the
 *        line number, and adding the appropriate
 *        instructions to the SimpleSim program.
 */
void scc::process_if ( std::stringstream* line_ss ) {
	// Read in lhs, operator, rhs, pointless 'goto' and line number
	std::string lhs_str;         *line_ss >> lhs_str;
	std::string op_str;          *line_ss >> op_str;
	std::string rhs_str;         *line_ss >> rhs_str;
	std::string goto_str;        *line_ss >> goto_str;
	std::string line_number_str; *line_ss >> line_number_str;

	// Convert the line_number to a line number
	int line_number = std::stoi( line_number_str );

	// Check and see if the location exists yet
	int location = -1;
	for ( int i = 0; i < next_symbol_table_idx; i++ ) {
		table_entry entry = this->symbol_table[i];

		if ( entry.type == 'L' && entry.symbol == line_number ) {
			location = entry.location;
		}
	}
	
	// Get the left and right hand side addresses
	int lhs_address = ( std::isalpha( lhs_str[0] ) ?
			this->find_or_insert_var ( lhs_str[0]           ) :
			this->find_or_insert_con ( std::stoi( lhs_str ) ) );
	int rhs_address = ( std::isalpha( rhs_str[0] ) ?
			this->find_or_insert_var ( rhs_str[0]           ) :
			this->find_or_insert_con ( std::stoi( rhs_str ) ) );

	// Process the operator
	switch ( op_str[0] ) {
		case '<': case '>': {
			// Load from RHS
			this->add_instruction( 22 * 100 + ( op_str[0] == '<' ? lhs_address : rhs_address ) );

			// Subtract from RHS
			this->add_instruction( 32 * 100 + ( op_str[0] == '>' ? lhs_address : rhs_address ) );

			// BRANCHNEG to `line_number`
			this->add_instruction( 
				43 * 100 + ( location == -1 ? 0 : location ),
				(location == -1 ? line_number : -1 )
			);

			// If there is an equals sign, add a BRANCHZERO
			if ( op_str.size() > 1 ) {
				this->add_instruction( 
					42 * 100 + ( location == -1 ? 0 : location ),
					( location == -1 ? line_number : -1 )
				);
			}
		} break;
		case '=': {
			// Load from RHS
			this->add_instruction( 22 * 100 + lhs_address );

			// Subtract from RHS
			this->add_instruction( 32 * 100 + rhs_address );

			// BRANCHZERO to `line_number`
			this->add_instruction( 
				42 * 100 + ( location == -1 ? 0 : location ),
				( location == -1 ? line_number : -1 )
			);
		} break;
		case '!': {
			// Load from RHS
			this->add_instruction( 22 * 100 + lhs_address );

			// Subtract from RHS
			this->add_instruction( 32 * 100 + rhs_address );

			// BRANCHZERO to `next_instruction_addr` + 2
			this->add_instruction( 42 * 100 + ( this->next_instruction_addr + 2 ) );

			// BRANCH to `line_number`
			this->add_instruction( 
				41 * 100 + ( location == -1 ? 0 : location ),
				( location == -1 ? line_number : -1 )
			);
			
		} break;
	}
}
/**
 * @brief Process a let line
 *
 * @param line_ss The stringstream of the line
 *
 * @notes This function processes a let line. It
 *        accomplishes this by reading in the variable
 *        and prefix expression, and adding the appropriate
 *        instructions to the SimpleSim program.
 */
void scc::process_let ( std::stringstream* line_ss ) {
	// Define the buffers for the
	//  variable and prefix strings
	std::string var_str;
	std::string prefix_str;
	
	// Extract the variable, skip the equals
	//  sign, and get the prefix expression
	*line_ss >> var_str;
	(*line_ss).ignore(3);
	std::getline( *line_ss, prefix_str );

	// Convert the variable string to the  
	//  variable and its memory address
	int var_addr = this->find_or_insert_var( var_str[0] );

	// Convert the prefix expression to a postfix expression
	std::string postfix = convert( prefix_str );

	// Define the stack index and postfix stringstream
	int next_stack_idx = 0;
	std::stringstream postfix_ss(postfix);

	// Process the postfix expression
	std::string token;
	while ( postfix_ss >> token ) {
		// Check if the token is a variable or constant
		if ( std::isalpha(token[0]) || std::isdigit(token[0]) ) {
			// Get the address of the variable / constant
			int address = ( std::isalpha( token[0] ) ?
				this->find_or_insert_var ( token[0]           ) :
				this->find_or_insert_con ( std::stoi( token ) ) );

			// Add the LOAD instruction
			this->add_instruction( LOAD * 100 + address );

			// Add the STORE instruction
			this->add_instruction( STORE * 100, -3 - next_stack_idx );
			next_stack_idx ++;

			continue;
		}
		
		// Process the token
		switch ( token[0] ) {
			case '+': case '*': {
				this->process_token_plus_mult( token, &next_stack_idx );
			} break;
			case '-': case '/': {
				this->process_token_minus_div( token, &next_stack_idx );
			} break;
		}
	}

	// Add the final result to the specifed variable
	this->add_instruction( LOAD * 100, -3 );
	this->add_instruction( STORE * 100 + var_addr ); 
}
/**
 * @brief Process an end line
 *
 * @param line_ss The stringstream of the line
 *
 * @notes This function processes an end line. It
 *        accomplishes this by adding the HALT
 *        instruction to the SimpleSim program.
 */
void scc::process_end ( std::stringstream* line_ss ) {
	// End the program
	this->add_instruction( HALT * 100 );
}

/**
 * @brief Process a plus or multiply token
 *
 * @param token The token to process
 * @param next_stack_idx The next stack index
 *
 * @notes This function processes a plus or multiply
 *        token. It accomplishes this by adding the
 *        appropriate instructions to the SimpleSim
 *        program.
 */
void scc::process_token_plus_mult ( std::string token, int* next_stack_idx ) {
	// Add our LOAD instruction
	this->add_instruction( LOAD * 100, -3 - ( (*next_stack_idx) - 1 ) );
	(*next_stack_idx) --;

	// Add our ADD or MULTIPLY instruction
	this->add_instruction( 
		( token[0] == '+' ? ADD : MULTIPLY ) * 100,
		-3 - ( (*next_stack_idx) - 1 )
	);
	(*next_stack_idx) --;

	// Add our STORE instruction
	this->add_instruction( STORE * 100, -3 - *next_stack_idx );
	(*next_stack_idx) ++;
};
/**
 * @brief Process a minus or divide token
 *
 * @param token The token to process
 * @param next_stack_idx The next stack index
 *
 * @notes This function processes a minus or divide
 *        token. It accomplishes this by adding the
 *        appropriate instructions to the SimpleSim
 *        program.
 */
void scc::process_token_minus_div ( std::string token, int* next_stack_idx ) {
	// Add our LOAD instruction
	this->add_instruction( LOAD * 100, -3 - ( (*next_stack_idx) - 1 ) );
	(*next_stack_idx) --;

	// Add our STORE instruction
	this->add_instruction( STORE * 100, -2 );

	// Add our LOAD instruction
	this->add_instruction( LOAD * 100, -3 - ( (*next_stack_idx) - 1 ) );
	(*next_stack_idx) --;

	// Add our SUBTRACT or DIVIDE instruction
	this->add_instruction(
		( token[0] == '-' ? SUBTRACT : DIVIDE ) * 100,
		-2
	);

	// Add our STORE instruction
	this->add_instruction( STORE * 100, -3 - *next_stack_idx );
	(*next_stack_idx) ++;
};