/***************************************************************
                            main.cc


CSCI 330         John White     Fall 2024

Programmer: z19942444

Section: 330-0001

Date Due: Saturday, September 28rst

Purpose: Emulate the UNIX `dog` command at a rudimentary level
***************************************************************/

/*

    /ᐠ - ˕ -マ

    @hiibolt on GitHub 

*/

#include <string>
#include <iostream>
#include <fcntl.h>
#include <cstring>
#include <bits/getopt_core.h>

#include "lib.h"


/**
 * @brief Parses the command line arguments
 * 
 * @param argc The number of arguments
 * @param argv The arguments
 * 
 * @return The state of the program
 */
Result<State> clap ( int argc, char *argv[] ){
    State state = { 1024, -1, -1, false, false, -1 };

    // Check for optional arguments
    int opt = getopt(argc, argv, "a:n:c:s:hb");
    while ( opt != -1 ) {
        switch(opt)  
        {  
            case 'a': {
                // Parse the argument
                Result<int> desired_buffer_size_result = checked_stoi(optarg)
                    .context("Could not parse 'a' argument!");
                PROPAGATE(desired_buffer_size_result, State);
                int desired_buffer_size = desired_buffer_size_result.unwrap();

                // Check for errors
                if ( desired_buffer_size <= 0 ) {
                    return Err<State>("Buffer size must be an integer greater than zero!");
                }

                state.buffer_size = desired_buffer_size;
            }   break;
            case 'n': {
                // Parse the argument
                Result<int> desired_max_bytes_result = checked_stoi(optarg)
                    .context("Could not parse 'n' argument!");
                PROPAGATE(desired_max_bytes_result, State);
                int desired_max_bytes = desired_max_bytes_result.unwrap();

                // Check for errors
                if ( desired_max_bytes <= 0 ) {
                    return Err<State>("Max bytes must be an integer greater than zero!");
                }

                state.max_bytes       = desired_max_bytes;
                state.remaining_bytes = desired_max_bytes;
            }   break;
            case 'c': {
                if ( state.normal_shift ) {
                    return Err<State>("Cannot use both -c and -s!");
                }

                // Parse the argument
                Result<int> desired_shift_result = checked_stoi(optarg)
                    .context("Could not parse 'c' argument!");
                PROPAGATE(desired_shift_result, State);
                int desired_shift = desired_shift_result.unwrap();

                // Check for errors
                if ( desired_shift <= 0 ) {
                    return Err<State>("Shift must be an integer greater than zero!");
                }

                state.caeser_shift = true;
                state.shift = desired_shift;
            }   break;
            case 's': {
                if ( state.caeser_shift ) {
                    return Err<State>("Cannot use both -c and -s!");
                }

                // Parse the argument
                Result<int> desired_shift_result = checked_stoi(optarg)
                    .context("Could not parse 's' argument!");
                PROPAGATE(desired_shift_result, State);
                int desired_shift = desired_shift_result.unwrap();

                // Check for errors
                if ( desired_shift <= 0 ) {
                    return Err<State>("Shift must be an integer greater than zero!");
                }
                
                state.normal_shift = true;
                state.shift = desired_shift;
            }   break;
            case 'h':
                if ( state.binary ) {
                    return Err<State>("Cannot use both -h and -b!");
                }

                state.hexa = true;
                break;
            case 'b':
                if ( state.hexa ) {
                    return Err<State>("Cannot use both -h and -b!");
                }

                state.binary = true;
                break;
            case '?':  
                return Err<State>("Invalid argument: " + std::string(1, optopt));
        }  

        opt = getopt(argc, argv, "a:n:c:s:hb");
    }

    return Ok<State>(state);
}

/**
 * @brief The main function of the program
 * 
 * @param argc The number of arguments
 * @param argv The arguments
 * 
 * @return A Result type with an empty successful value
 */
Result<Nothing> dog ( int argc, char *argv[], State *state)  {
    // If there are no arguments remaining, print from stdin
    if ( optind == argc ) {
        print_from_fd ( 0, state );

        return Ok<Nothing>(Nothing());
    }

    // Extract any remaining arguments
    for ( int i = optind; i < argc; i++ ) {
        state->remaining_bytes = state->max_bytes;

        if ( strlen(argv[i]) == 1 && argv[i][0] == '-' ) {
            print_from_fd ( 0, state );

            continue;
        }

        // Attempt to open the file
        int fd;
        PROPAGATE_SYSCALL(&fd, open(argv[i], O_RDONLY), Nothing);

        // Print the file
        print_from_fd ( fd, state );
    }

    return Ok<Nothing>(Nothing());
}

/**
 * @brief Dog function that reads from a file and writes to stdout
 * 
 * @param argc The number of arguments
 * @param argv The arguments
 * 
 * @return int The exit status, 0 if successful, 1 if not
 */
int main ( int argc, char *argv[] ) {
    State state = clap(argc, argv)
        .context("Failed to parse arguments!")
        .unwrap();

    dog( argc, argv, &state )
        .unwrap();

    return 0;
}