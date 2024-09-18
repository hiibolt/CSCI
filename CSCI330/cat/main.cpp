/***************************************************************
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


#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>


/**
 * @brief Writes a buffer to stdout
 * 
 * @param buffer The buffer to write
 * @param len The length of the buffer
 * 
 * @return void
 * 
 * @note Exits the program if the write fails
 */
void print ( const int *buffer, ssize_t len ) {
    ssize_t result = write ( 1, buffer, len );

    if ( result == -1 ) {
        perror ( "Failed to write to stdout!" );

        exit( 1 );
    }
}

/**
 * @brief Reads from a file descriptor and writes to stdout
 * 
 * @param fd The file descriptor to read from
 * 
 * @return void
 * 
 * @note Exits the program if the read fails
 */
void print_from_fd ( int fd ) {
    int buffer[1024];
    ssize_t result;

    while ( ( result = read ( fd, buffer, 1024 ) ) > 0 ) {
        print ( buffer, result );
    }

    if ( result == -1 ) {
        perror ( "Failed to read from file!" );

        exit( 1 );
    }
}


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
    if ( argc == 1 ) {
        print_from_fd ( 0 );

        return 0;
    }

    // For each argument, open the file and print it
    for ( int i = 1; i < argc; i ++ ) {
        // If the argument is a single dash, read from stdin
        if ( strlen(argv[i]) == 1 && argv[i][0] == '-' ) {
            print_from_fd ( 0 );

            continue;
        }

        // Attempt to open the file
        int fd = open ( argv[i], O_RDONLY );

        // Check for errors
        if ( fd == -1 ) {
            perror ( "Failed to open" );
            perror ( argv[i] );

            exit ( 1 );
        }

        // Print the file
        print_from_fd ( fd );
    }

    return 0;
}