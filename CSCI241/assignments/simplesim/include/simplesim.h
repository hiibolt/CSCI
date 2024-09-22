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


#ifndef SIMPLESIM_H
#define SIMPLESIM_H

#include "sml.h"
#include <memory>

using std::unique_ptr;

class simplesim
{
    // Simplesim memory.
    signed long memory[100];

    // Simplesim registers.
    int accumulator = 0;
    int instruction_counter = 0;
    int instruction_register = 0;
    int operation_code = 0;
    int operand = 0;

public:

    simplesim();
    bool load_program();
    void execute_program();
    void dump() const;
};

#endif
