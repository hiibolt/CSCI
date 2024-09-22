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


#ifndef SML_H
#define SML_H

#include <iostream>
#include <iomanip>

enum OPCode {
    READ       = 11,
    WRITE      = 12,
    STORE      = 21,
    LOAD       = 22,
    ADD        = 31,
    SUBTRACT   = 32,
    MULTIPLY   = 33,
    DIVIDE     = 34,
    BRANCH     = 41,
    BRANCHZERO = 42,
    BRANCHNEG  = 43,
    HALT       = 44,
    DEFAULT    = 77
};

#endif
