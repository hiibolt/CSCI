#include <iostream>
#include <string>
#include <unistd.h>

#include "lib.h"

std::string get_command ( std::string prompt ) {
	// Output our prompt
	std::cout << prompt;

	// Get our new line
	std::string ret;
	std::getline ( std::cin, ret );

	return ret;
};
Result<bool> repl ( ) {
	// Get our first command
	std::string cmd1 = get_command ( "Command 1: " );
	if ( cmd1 == "quit" ) return Ok(true);

	// Get our second command
	std::string cmd2 = get_command ( "Command 2: " );
	if ( cmd2 == "quit" ) return Ok(true);

	int pid;
	PROPAGATE_SYSCALL( &pid, fork(), bool );
	if ( pid == 0 ) {
		std::cout << "child process - becoming echo command!";
		int res = execlp( "echo", "echo", ":3" );
		std::cout << "very bad... '" << res << "'" << std::endl;
	} else {
		std::cout << "parent";
	}


	return Ok(true);
}

int main ( ) {
	std::cout << "good luck, do your best :3" << std::endl;

	while ( true ) {
		std::cout << "[ New Cycle ]" << std::endl;

		if ( repl()
			.context("Primary REPL failed!")
			.unwrap() == true 
		) {
			std::cout << std::endl << "Goodbye :)" << std::endl;

			return 0;
		}
	}

	return 0;
}

