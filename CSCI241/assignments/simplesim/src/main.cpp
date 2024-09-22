/***************************************************************
CSCI 241         John White     Spring 2024

Programmer: z19942444

Section: 241-0002

Date Due: Wednesday, October 2nd

Purpose: To emulate a computer using the Simpletron Machine Language (SML).
***************************************************************/

/*

    /ᐠ - ˕ -マ

    @hiibolt on GitHub 

*/


#include "simplesim.h"


/**
 * Attempts to load and execute an SML program read from standard
 * input, and then dumps the contents of the simplesim's registers
 * and memory.
 *
 * @return Zero on successful completion; otherwise, a non-zero
 *         return code.
 */
int main()
{
    simplesim s;    // Define a simplesim object.

    // Try to load SML program into the simplesim's memory. If
    // successful, execute the program.
    if (s.load_program())
        s.execute_program();

    // Dump the contents of the simplesim's registers and memory.
    s.dump();

    return 0;
}