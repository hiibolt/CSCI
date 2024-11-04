// add sig :3

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

scc::scc ( ) {
	for ( int i = 0; i < MEMORY_SIZE; i++ ) {
		memory[i] = 7777;
		flags[i] = -1;
	}

	ndata = 0;

	next_instruction_addr = 0;
	next_const_or_var_addr = MEMORY_SIZE - 1;
	next_symbol_table_idx = 0;
};
void scc::first_pass ( ) {
	std::string line;
	std::string buffer2;
	while ( getline( std::cin, line ) ) {
		std::string line_number_str;
		std::string command;
		std::stringstream line_ss(line);
		buffer2 = line; // buffer2 used for 'let'
		
		// First, extract the line number and command
		line_ss >> line_number_str;
		line_ss >> command;

		int line_number = std::stoi ( line_number_str );

		//std::cout << "Line " << line_number_str << " (" << command << "): " << std::endl;

		// First, process the line number into a 
		//  new symbol table entry
		this->symbol_table[ this->next_symbol_table_idx ] = table_entry {
			line_number,
			'L',
			this->next_instruction_addr
		};
		next_symbol_table_idx ++;
		
		// Next, process the command
		if ( command == "data" ) {
			// Read the string value of the integer
			std::string new_data_str;
			line_ss >> new_data_str;
			
			// We need that as an integer to work with it
			int new_data = std::stoi ( new_data_str );

			// Check if there's room in the array
			if ( this->ndata == 100 ) {
				//std::cout << "*** ERROR: too many data lines ***" << std::endl;
				exit ( -1 );
			}

			// Add it to our data, given we have room
			if ( this->ndata >= 99 ) {
				std::cout << "*** ERROR: too many data lines ***" << std::endl;
				exit( -1 );
			}	
			this->data[ this->ndata ] = new_data;
			this->ndata ++;
		} else if ( command == "input" || command == "print" ) {
			// Read in the variable character
			std::string var_str;
			line_ss >> var_str;

			//std::cout << "Got variable '" << symbol << "'" << std::endl;

			// Get the memory address of the variable
			int mem_address = ( std::isalpha( var_str[0] ) ?
					this->find_or_insert_var ( var_str[0]           ) :
					this->find_or_insert_con ( std::stoi( var_str ) ) );

			// Add the READ or PRINT instruction
			this->add_instruction ( ( command == "input" ? READ : WRITE ) * 100 + mem_address ); 
		} else if ( command == "goto" ) {
			// Read in the line number as a string
			std::string line_number_str;
			line_ss >> line_number_str;

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

			// Add the branch statement
			this->add_instruction(
				41 * 100 + ( location == -1 ? 0 : location ),
				( location == -1 ? line_number : -1 )
			);
		} else if ( command == "if" ) {
			// Read in lhs, operator, rhs, pointless 'goto' and line number
			std::string lhs_str;         line_ss >> lhs_str;
			std::string op_str;          line_ss >> op_str;
			std::string rhs_str;         line_ss >> rhs_str;
			std::string goto_str;        line_ss >> goto_str;
			std::string line_number_str; line_ss >> line_number_str;

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

			//std::cout << "Checking if '" << lhs_str << " " 
			//	                     << op_str << " " 
			//			     << rhs_str << "' to `goto` " 
			//			     << line_number << std::endl;
			
			int lhs_address = ( std::isalpha( lhs_str[0] ) ?
					this->find_or_insert_var ( lhs_str[0]           ) :
					this->find_or_insert_con ( std::stoi( lhs_str ) ) );
			int rhs_address = ( std::isalpha( rhs_str[0] ) ?
					this->find_or_insert_var ( rhs_str[0]           ) :
					this->find_or_insert_con ( std::stoi( rhs_str ) ) );

			//std::cout << "LHS: " << lhs_address << " | RHS: " << rhs_address << std::endl;

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
		} else if ( command == "let" ) {
			// Define the buffers for the
			//  variable and prefix strings
			std::string var_str;
			std::string prefix_str;
			
			// Extract the variable, skip the equals
			//  sign, and get the prefix expression
			line_ss >> var_str;
			line_ss.ignore(3);
			std::getline( line_ss, prefix_str );

			// Convert the variable string to the  
			//  variable and its memory address
			int var_addr = this->find_or_insert_var( var_str[0] );

			std::string postfix = convert( prefix_str );

			// Begin processing our postfix
			int next_stack_idx = 0;
			std::stringstream postfix_ss(postfix);

			std::string token;
			while ( postfix_ss >> token ) {
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
				} else {
					switch ( token[0] ) {
						case '+': {
							this->add_instruction( LOAD * 100, -3 - ( next_stack_idx - 1 ) );
							next_stack_idx --;

							this->add_instruction( ADD * 100, -3 - ( next_stack_idx - 1 ) );
							next_stack_idx --;

							this->add_instruction( STORE * 100, -3 - next_stack_idx );
							next_stack_idx ++;
						} break;
						case '-': {
							this->add_instruction( LOAD * 100, -3 - ( next_stack_idx - 1 ) );
							next_stack_idx --;

							this->add_instruction( STORE * 100, -2 );

							this->add_instruction( LOAD * 100, -3 - ( next_stack_idx - 1 ) );
							next_stack_idx --;

							this->add_instruction( SUBTRACT * 100, -2 );

							this->add_instruction( STORE * 100, -3 - next_stack_idx );
							next_stack_idx ++;
						} break;
						case '*': {
							this->add_instruction( LOAD * 100, -3 - ( next_stack_idx - 1 ) );
							next_stack_idx --;

							this->add_instruction( MULTIPLY * 100, -3 - ( next_stack_idx - 1 ) );
							next_stack_idx --;

							this->add_instruction( STORE * 100, -3 - next_stack_idx );
							next_stack_idx ++;
						} break;
						case '/': {
							this->add_instruction( LOAD * 100, -3 - ( next_stack_idx - 1 ) );
							next_stack_idx --;

							this->add_instruction( STORE * 100, -2 );

							this->add_instruction( LOAD * 100, -3 - ( next_stack_idx - 1 ) );
							next_stack_idx --;

							this->add_instruction( DIVIDE * 100, -2 );

							this->add_instruction( STORE * 100, -3 - next_stack_idx );
							next_stack_idx ++;
						} break;
					}
				}
			}

			// Add the final result to the specifed variable
			this->add_instruction( LOAD * 100, -3 );
			this->add_instruction( STORE * 100 + var_addr ); 
		} else if ( command == "end" ) {
			// End the program
			this->add_instruction( HALT * 100 );
		}
	}
};
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
					//std::cout << "gotcha!" << std::endl;
					address = entry.location;
				}
			}

			memory[i] += address;
		}

		if ( this->flags[i] < -1 ) {
			int stack_top = this->next_const_or_var_addr - (-3 - this->flags[i] + 1); 
			
			if ( stack_top == next_instruction_addr - 1 ) {
				std::cout << "*** ERROR: insufficient stack space ***" << std::endl;
				exit( -1 );
			}

			memory[i] += stack_top;
		}
	}
};
void scc::print_program ( ) const {
	/*
	std::cout << "[ Symbols ]" << std::endl;
	for ( int i = 0; i < this->next_symbol_table_idx; i++ ) {
		table_entry entry = this->symbol_table[i];
		std::cout << "Symbol: " << entry.symbol 
			  << " | Type: " << entry.type 
			  << " | Address: " << entry.location << std::endl;
	}

	std::cout << std::endl << std::endl << "[ Memory ]" << std::endl;
	*/
	for ( int i = 0; i < MEMORY_SIZE; i++ ) {
		std::cout << ( this->memory[i] < 0 ? "-" : "+" )  << std::setw(4) << std::setfill('0') 
			  << std::abs( this->memory[ i ] ) << std::endl;
	}

	std::cout << "-99999" << std::endl;

	// Next, print all of the data
	for ( int i = 0; i < this->ndata; i++ ) {
		std::cout << this->data[ i ] << std::endl;
	}
};

void scc::add_instruction ( int instruction, int flag ) {
	if ( next_instruction_addr >= MEMORY_SIZE - 1 ) {	
		std::cout << "*** ERROR: ran out of Simplesim memory ***" << std::endl;
		exit( -1 );
	}

	this->memory[ this->next_instruction_addr ] = instruction;
	this->flags[ this->next_instruction_addr ] = flag;
	this->next_instruction_addr ++;
}
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
