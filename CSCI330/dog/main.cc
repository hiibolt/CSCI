/***************************************************************
                            main.cc


CSCI 330         John White     Fall 2024

Programmer: z19942444

Section: 330-0001

Date Due: Saturday, September 28rst

Purpose: Emulate the UNIX `cat` command at a rudimentary level
***************************************************************/

/*

    /ᐠ - ˕ -マ

    @hiibolt on GitHub 

*/



#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>

#include "lib.h"



/**
 * @brief Cat function that reads from a file and writes to stdout
 * 
 * @param argc The number of arguments
 * @param argv The arguments
 * 
 * @return int The exit status, 0 if successful, 1 if not
 * 
 * @note Exits the program if the file cannot be opened
 * @note If no arguments are passed, reads from stdin
 * @note If a single dash is passed, reads from stdin
 */
int main ( int argc, char *argv[]) {
    // If no arguments are passed, read from stdin
    State state = { 1024, -1, -1, false, false, -1 };

    // Check for optional arguments
    int opt = getopt(argc, argv, "a:n:c:s:hb");
    while ( opt != -1 ) {
        switch(opt)  
        {  
            case 'a': {
                int desired_buffer_size = std::stoi(optarg);
                if ( desired_buffer_size <= 0 ) {
                    std::cerr << "Buffer size must be an integer greater than zero!" << std::endl;
                    exit(1);
                }

                state.buffer_size = desired_buffer_size;
            }   break;
            case 'n': {
                int desired_max_bytes = std::stoi(optarg);
                if ( desired_max_bytes <= 0 ) {
                    std::cerr << "Max bytes must be an integer greater than zero!" << std::endl;
                    exit(1);
                }

                state.max_bytes       = desired_max_bytes;
                state.remaining_bytes = desired_max_bytes;
            }   break;
            case 'c': {
                if ( state.normal_shift ) {
                    std::cerr << "Cannot use both -c and -s!" << std::endl;
                    exit(1);
                }

                int desired_shift = std::stoi(optarg);
                if ( desired_shift <= 0 ) {
                    std::cerr << "Shift must be an integer greater than zero!" << std::endl;
                    exit(1);
                }

                state.caeser_shift = true;
                state.shift = desired_shift;
            }   break;
            case 's': {
                if ( state.caeser_shift ) {
                    std::cerr << "Cannot use both -c and -s!" << std::endl;
                    exit(1);
                }

                int desired_shift = std::stoi(optarg);
                if ( desired_shift <= 0 ) {
                    std::cerr << "Shift must be an integer greater than zero!" << std::endl;
                    exit(1);
                }
                
                state.normal_shift = true;
                state.shift = desired_shift;
            }   break;
            case 'h':
                if ( state.binary ) {
                    std::cerr << "Cannot use both -h and -b!" << std::endl;
                    exit(1);
                }
                state.hexa = true;
                break;
            case 'b':
                if ( state.hexa ) {
                    std::cerr << "Cannot use both -h and -b!" << std::endl;
                    exit(1);
                }
                state.binary = true;
                break;
            case '?':  
                std::cerr << "Recieved unknown option " << optopt << std::endl; 
                exit(1);
        }  

        opt = getopt(argc, argv, "a:n:c:s:hb");
    }

    // Extract any remaining arguments
    for ( int i = optind; i < argc; i++ ) {
        state.remaining_bytes = state.max_bytes;

        if ( strlen(argv[i]) == 1 && argv[i][0] == '-' ) {
            print_from_fd ( 0, &state );

            continue;
        }

        // Attempt to open the file
        int fd = open ( argv[i], O_RDONLY );

        // Check for errors
        if ( fd == -1 ) {
            perror("Failed to open file");
            exit(1);
        }

        // Print the file
        print_from_fd ( fd, &state );
    }

    return 0;
}