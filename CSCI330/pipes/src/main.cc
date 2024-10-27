/***************************************************************
                            main.cc


CSCI 330         John White     Fall 2024

Programmer: z19942444

Section: 330-0001

Date Due: ASAP

Purpose: Create a TUI REPL to emulate the `|` operator in shell scripting
***************************************************************/

/*

    /ᐠ - ˕ -マ

    @hiibolt on GitHub 

*/


#include <iostream>
#include <string>
#include <sstream>
#include <unistd.h>
#include <sys/wait.h>

#include "lib.h"

// Helper Functions
/**
 * @brief Ask the user for a command
 *
 * @arg string The prompt to display
 *
 * @return string The command
 */
std::string get_command ( std::string prompt ) {
	// Output our prompt
	std::cout << prompt;

	// Get our new line
	std::string ret;
	std::getline ( std::cin, ret );

	return ret;
};
/**
 * @brief Count the spaces in a string
 *
 * @arg string The string to count from
 *
 * @return int The number of spaces
 */
int num_spaces ( std::string input ) {
	int ret = 0;

	for ( long unsigned int i = 0; i < input.size(); i++ ) {
		if ( input[i] == ' ' ) {
			ret ++;
		}
	}

	return ret;
}
/**
 * @brief Converts a string to an array of C-style strings
 *
 * @arg string The string to conver
 *
 * @return Result<char **> A result containing the strings or any errors
 *
 * @fails If the function is given an empty input
 */
Result<char **> string_to_argv ( std::string input ) {
	char** ret = new char* [ num_spaces(input) + 2 ]; // 1 for command name, 1 for null-terminator
	
	// Define our stringstream and buffer for processing
	std::stringstream input_ss ( input );
	std::string buffer;

	// Read all arguments
	int i = 0;
	while ( input_ss >> buffer ) {
		// Allocate for the argument
		ret[i] = new char [ buffer.size() + 1 ];

		// Copy the argument into the array
		std::strcpy( ret[i], buffer.c_str() ); 
		
		i++;
	}

	// Verify we got a command
	if ( i == 0 ) {
		return Err<char **>("Got an empty command!");
	}

	return Ok(ret);
}
/**
 * @brief The primary logic of the REPL
 *
 * @return Result<bool> A boolean representing whether one of the commands was `quit`.
 */
Result<bool> repl ( ) {
	// Get our first command
	std::string cmd1 = get_command ( "Command 1: " );
	if ( cmd1 == "quit" ) return Ok(true);

	// Get our second command
	std::string cmd2 = get_command ( "Command 2: " );
	if ( cmd2 == "quit" ) return Ok(true);


	// Convert both commands into argument arrays
	Result<char **> cmd1_args_result = string_to_argv ( cmd1 )
		.context("Recieved invalid command!");
	Result<char **> cmd2_args_result = string_to_argv ( cmd2 )
		.context("Recieved invalid command!");
	PROPAGATE ( cmd1_args_result, bool );
	PROPAGATE ( cmd2_args_result, bool );
	char ** cmd1_args = cmd1_args_result.unwrap();
	char ** cmd2_args = cmd2_args_result.unwrap();

	// Create our pipe and command PIDs
	int pipefd[2];
	int cmd1_pid, cmd2_pid;
	PROPAGATE_SYSCALL_NO_RET ( pipe(pipefd), bool );

	// Fork the second child first
	PROPAGATE_SYSCALL ( &cmd2_pid, fork(), bool );
	if ( cmd2_pid == 0 ) {
		// Close the write end
		close ( pipefd[1] );

		// Re-route pipe's write end into ours
		close ( 0 );
		PROPAGATE_SYSCALL_NO_RET ( dup(pipefd[0]), bool );
		close ( pipefd[0] );

		// Run our output command
		PROPAGATE_SYSCALL_NO_RET (execvp( cmd2_args[0], cmd2_args ), bool);
	}

	// Now fork the first child
	PROPAGATE_SYSCALL ( &cmd1_pid, fork(), bool );
	if ( cmd1_pid == 0 ) {
		// Close the read end
		close ( pipefd[0] );

		// Re-route pipe's read end into ours
		close ( 1 );
		PROPAGATE_SYSCALL_NO_RET( dup(pipefd[1]), bool );
		close( pipefd[1] );

		// Run our input command
		PROPAGATE_SYSCALL_NO_RET(execvp( cmd1_args[0], cmd1_args ), bool);
	}

	// Close pipe ends in parent process
	close(pipefd[0]);
	close(pipefd[1]);

	// Wait for both child processes
	int status_1, status_2;
	waitpid(cmd1_pid, &status_1, 0);
	waitpid(cmd2_pid, &status_2, 0);

	// Verify that both command's outputs were successfull
	if ( WIFEXITED(status_1) && WEXITSTATUS(status_1) != 0 ) {
		return Err<bool>( "Command 1 failed!" );
	}
	if ( WIFEXITED(status_2) && WEXITSTATUS(status_2) != 0 ) {
		return Err<bool>( "Command 2 failed!" );
	}
	
	return Ok(false);
}

/**
 * @brief A TUI REPL to emulate the `|` operator in shell scripting
 *
 * @output `stdout` from the second command.
 */
int main ( ) {
	while ( repl().unwrap() != true ) { }
	
	goodbye();

	return 0;
}

