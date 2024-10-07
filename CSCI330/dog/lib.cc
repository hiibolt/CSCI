/***************************************************************
                            lib.cc


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
#include <string>

#include "lib.h"



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
void print ( unsigned char buffer[], ssize_t len, State *state ) {
    if ( state->caeser_shift ) {
        caeser_shift ( buffer, len, state->shift );
    } else if ( state->normal_shift ) {
        normal_shift ( buffer, len, state->shift );
    }

    if ( state->binary ) {
        unsigned char * binary = bytesToBinary(buffer, len);
        ssize_t result = write ( 1, binary, len * 8 );

        if ( result == -1 ) {
            perror ( "Failed to write to stdout!" );

            exit( 1 );
        }

        return;
    } else if ( state->hexa ) {
        unsigned char * hex = bytesToHex(buffer, len);
        ssize_t result = write ( 1, hex, len * 2 );

        if ( result == -1 ) {
            perror ( "Failed to write to stdout!" );

            exit( 1 );
        }

        return;
    }

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
void print_from_fd ( int fd, State *state ) {
    unsigned char * buffer = new unsigned char[state->buffer_size];
    ssize_t result;

    if ( state->max_bytes == -1 ) {
        while ( ( result = read ( fd, buffer, state->buffer_size ) ) > 0 ) {
            print ( buffer, result, state );
        }

        if ( result == -1 ) {
            perror ( "Failed to read from file!" );

            exit( 1 );
        }

        return;
    }

    while ( ( result = read ( fd, buffer, std::min(state->buffer_size, state->remaining_bytes) ) ) > 0 ) {
        state->remaining_bytes -= result;
        print ( buffer, result, state );
    }

    if ( result == -1 ) {
        perror ( "Failed to read from file!" );

        exit( 1 );
    }
}

/**
 * @brief Converts a byte array to a binary string
 * 
 * @param input The input byte array
 * @param length The length of the input array
 * 
 * @return The byte string
 */
unsigned char* bytesToBinary(const unsigned char* input, size_t length) {
    // Since each byte is 8 bits, the output will
    //  be 8 times the length
    size_t outputLength = length * 8;

    // Allocate memory for the output array
    unsigned char* output = new unsigned char[outputLength + 1];

    // Null-terminate the output
    output[outputLength] = '\0';

    for (size_t i = 0; i < length; ++i) {
        unsigned char byte = input[i];

        for (int j = 7; j >= 0; --j) {
            output[i * 8 + (7 - j)] = (byte & (1 << j)) ? '1' : '0';
        }
    }

    return output;
}

/**
 * @brief Converts a byte array to a hex string
 * 
 * @param input The input byte array
 * @param length The length of the input array
 * 
 * @return The hex string
 */
unsigned char* bytesToHex(const unsigned char* input, size_t length) {
    // Each hex character represents 4 bits, so the 
    //  output will be twice the length of the input
    size_t outputLength = length * 2;

    // Allocate memory for the output array
    unsigned char* output = new unsigned char[outputLength + 1];

    // Null-terminate the output
    output[outputLength] = '\0';

    // Convert each byte to hex
    for (size_t i = 0; i < length; ++i) {
        unsigned char byte = input[i];
        output[i * 2] = (byte >> 4) + (byte >> 4 < 10 ? '0' : 'a' - 10);
        output[i * 2 + 1] = (byte & 0x0F) + ((byte & 0x0F) < 10 ? '0' : 'a' - 10);
    }

    return output;
}

/**
 * @brief Shifts a buffer by a given amount
 * 
 * @param buffer The buffer to shift
 * @param len The length of the buffer
 * @param shift The amount to shift by
 * 
 * @return void
 */
void normal_shift ( unsigned char *buffer, ssize_t len, int shift ) {
    for ( ssize_t i = 0; i < len; i++ ) {
        buffer[i] = ( buffer[i] + shift ) % 256;
    }
}

/**
 * @brief Shifts a buffer by a caeser shift, only works on alphabetic characters
 * 
 * @param buffer The buffer to shift
 * @param len The length of the buffer
 * @param shift The amount to shift by
 * 
 * @return void
 */
void caeser_shift ( unsigned char *buffer, ssize_t len, int shift ) {
    for ( ssize_t i = 0; i < len; i++ ) {
        if ( buffer[i] >= 'A' && buffer[i] <= 'Z' ) {
            buffer[i] = ( buffer[i] - 'A' + shift ) % 26 + 'A';
        } else if ( buffer[i] >= 'a' && buffer[i] <= 'z' ) {
            buffer[i] = ( buffer[i] - 'a' + shift ) % 26 + 'a';
        }
    }
}