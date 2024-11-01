/***************************************************************
                            lib.cc


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


#include <chrono>
#include <thread>
#include <iostream>

#include "lib.h"

/**
 * @brief A fun way to exit the program, which
 *         lerps out text slowly.
 */
void goodbye ( ) {
	std::string gb = "Goodbye...";

	std::cout << std::endl;

	// Loop through each character
	for ( long unsigned int i = 0; i < gb.size(); i++ ) {
		std::this_thread::sleep_for ( std::chrono::milliseconds( 15 ) );

		// Go a bit slower for period
		if ( gb[i] == '.' ) {
			std::this_thread::sleep_for( std::chrono::milliseconds ( 65 ) );
		}

		std::cout << gb[i] << std::flush;
	}

	std::this_thread::sleep_for ( std::chrono::milliseconds ( 200 ) );
	std::cout << std::endl << std::endl << "/ᐠ - ˕ -マ" << std::endl;
};
