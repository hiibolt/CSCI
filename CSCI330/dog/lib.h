/***************************************************************
                            lib.h


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



#ifndef SHIFT_H
#define SHIFT_H

#include <stdlib.h>



/**
 * @brief The program state
 */
struct State {
    // Buffer-Related
    int buffer_size;
    int max_bytes;
    int remaining_bytes;

    // Shift-Related
    bool caeser_shift;
    bool normal_shift;
    int  shift;

    // Representation-Related
    bool binary;
    bool hexa;
};

/* Shifts */
void caeser_shift ( unsigned char *, ssize_t, int );
void normal_shift ( unsigned char *, ssize_t, int );

/* Representation Conversions */
unsigned char* bytesToBinary ( const unsigned char*, size_t );
unsigned char* bytesToHex    ( const unsigned char*, size_t );

/* Print */
void print         ( unsigned char[], ssize_t len, State *state );
void print_from_fd ( int,             State *state              );

#endif