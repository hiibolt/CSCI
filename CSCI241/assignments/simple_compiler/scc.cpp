// add sig :3

#include <iostream>
#include <string>
#include <sstream>

#include "scc.h"
#include "mystack.h"
#include "sml.h"

scc::scc ( ) {
	for ( int i = 0; i < MEMORY_SIZE; i++ ) {
		memory[i] = 7777;
		data[i] = 7777;
		flags[i] = -1;
	}

	ndata = 0;

	next_instruction_addr = 0;
	next_const_or_var_addr = MEMORY_SIZE - 1;
	next_symbol_table_idx = 0;
};
void scc::first_pass ( ) {
	std::string buffer1, buffer2, line_number, command;
	while (getline(std::cin, buffer1)) {
		buffer2 = buffer1; // buffer2 used for 'let'
		std::stringstream ss(buffer1);
		ss >> line_number;
		// ... code to add line_number to symbol table, type 'L' ...
		ss >> command;
		if ( command == "input" ) {
		// ... code to process 'input' command ...
		}
		else if ( command == "data" ) {
		// ... code to process 'data' command ...
		}
		else if ( command == "let" ) {
		// ... code to process 'let' command ...
		}
		else if ( command == "todo" ) {
		//.
		//.
		//.
		}
		else if ( command == "rem" ) {
		// ... code to process 'rem' command ...
		}
	}

};
void scc::second_pass ( ) {

};
void scc::print_program ( ) const {

};
