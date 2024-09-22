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
#include "sml.h"

#include <memory>
#include <iostream>
#include <iomanip>
#include <cstdlib>

/**
 * @brief Check if the address is out of bounds.
 * 
 * @param address The address to check.
 * 
 * @return true if the address is out of bounds; otherwise, false.
 */
bool addr_oob ( int address ) {
    if ( address < 0 || address >= 100 ) {
        std::cout << "*** ABEND: addressability error ***" << std::endl;

        return true;
    }

    return false;
}

/**
 * @brief Perform a protected operation on the accumulator.
 * 
 * @param accumulator The accumulator to modify.
 * @param result The result of the operation.
 * 
 * @return true if the operation was safe; otherwise, false.
 */
bool protected_operation ( int* accumulator, int result ) {
    if ( result > 9999 ) {
        std::cout << "*** ABEND: overflow ***" << std::endl;

        return true;
    } else if ( result < -9999 ) {
        std::cout << "*** ABEND: underflow ***" << std::endl;

        return true;
    }

    *accumulator = result;

    return false;
}

/**
 * @brief Print a signed long word
 * 
 * @note The word is printed in the format: [+/-]####.
 * 
 * @param word The word to print.
 */
void print_word ( signed long word, bool with_space = false ) {
    std::cout << (word < 0 ? '-' : '+') << std::setw(4) << std::right << std::setfill('0') << std::abs(word) << ( with_space ? " " : "" );
}

/**
 * @brief Print a register.
 * 
 * @param header The header to print.
 * @param value The value to print.
 * @param is_word Whether the value is a word.
 */
void print_register ( const char* header, signed long value, bool is_word ) {
    std::cout << std::setw(24) << std::setfill(' ') << std::left << header;

    if ( is_word ) {
        print_word(value, true);

        std::cout << std::endl;

        return;
    }

    std::cout << std::setw(2)  << std::setfill('0') << std::right << value  << std::endl;
}

/**
 * @brief Read an instruction from standard input.
 * 
 * @return The instruction read from standard input.
 */
signed long read_instruction ( ) {
    signed long instruction;

    std::cin >> instruction;

    return instruction;
}

/**
 * @brief Construct a new simplesim object.
 */
simplesim::simplesim ( ) {
    for ( int i = 0; i < 100; i++ ) {
        memory[i] = 7777;
    }
}

/**
 * @brief Load an SML program from standard input into the simplesim's memory.
 * 
 * @return true if the program was successfully loaded; otherwise, false.
 */
bool simplesim::load_program ( ) {
    short address = 0;

    while ( true ) {
        signed long instruction = read_instruction();

        // Check if the instruction is the sentinel value
        if ( instruction == -99999 ) {
            break;
        }

        if ( instruction > 9999 || instruction < -9999 ) {
            std::cout << "*** ABEND: pgm load: invalid word ***" << std::endl;

            return false;
        }

        // Check if the address is out of bounds
        if ( address >= 100 ) {
            std::cout << "*** ABEND: pgm load: pgm too large ***" << std::endl;

            return false;
        }

        memory[address] = instruction;

        // Increment the address
        address ++;
    }

    return true;
}

/**
 * @brief Execute the program loaded into the simplesim's memory.
 */
void simplesim::execute_program ( ) {
    while ( true ) {
        // Load the instruction from memory
        instruction_register = memory[instruction_counter];

        // Unpack the instruction
        operation_code = instruction_register / 100;
        operand = instruction_register % 100;
        
        // Complete the operation
        switch ( operation_code ) {
            // [ IO ] - Input/Output operations
            // * [ READ ] - Read a word from standard input and store it in memory.
            case OPCode::READ: {
                signed long instruction = read_instruction();

                // Check if the instruction is valid
                if ( instruction > 9999 || instruction < -9999 ) {
                    std::cout << "*** ABEND: illegal input ***" << std::endl;

                    return;
                } else {
                    std::cout << "READ: "; print_word(instruction); std::cout << std::endl;
                    memory[operand] = instruction;
                }
                } break;
            // * [ WRITE ] - Print the word in memory to standard output.
            case OPCode::WRITE: 
                // Print the memory contents
                print_word(memory[operand]); std::cout << std::endl;
                break;

            // [ MEMORY ] - Memory operations
            // * [ STORE ] - Store the accumulator in memory.
            case OPCode::STORE:
                memory[operand] = accumulator;
                break;
            // * [ LOAD ] - Load a word from memory into the accumulator.
            case OPCode::LOAD:
                accumulator = memory[operand];
                break;

            // [ ARITHMETIC ] - Arithmetic operations            
            // * [ ADD ] - Add a word from memory to the accumulator.
            case OPCode::ADD:
                if ( protected_operation(&accumulator, accumulator + memory[operand]) ) { return; }
                break;
            // * [ SUBTRACT ] - Subtract a word from memory from the accumulator.
            case OPCode::SUBTRACT:
                if ( protected_operation(&accumulator, accumulator - memory[operand]) ) { return; }
                break;
            // * [ MULTIPLY ] - Multiply the accumulator by a word from memory.
            case OPCode::MULTIPLY:
                if ( protected_operation(&accumulator, accumulator * memory[operand]) ) { return; }
                break;
            // * [ DIVIDE ] - Divide the accumulator by a word from memory.
            case OPCode::DIVIDE:
                if ( memory[operand] == 0 ) {
                    std::cout << "*** ABEND: attempted division by 0 ***" << std::endl;
                    return;
                }

                if ( protected_operation(&accumulator, accumulator / memory[operand]) ) { return; }
                break;

            // [ CONTROL ] - Control operations
            // * [ BRANCH ] - Branch to a specific address in memory.
            case OPCode::BRANCH:
                instruction_counter = operand;

                continue;
                break;
            // * [ BRANCHZERO ] - Branch to a specific address in memory if the accumulator is zero.
            case OPCode::BRANCHZERO:
                if ( accumulator == 0 ) {
                    instruction_counter = operand;

                    continue;
                }
                break;
            // * [ BRANCHNEG ] - Branch to a specific address in memory if the accumulator is negative.
            case OPCode::BRANCHNEG:
                if ( accumulator < 0 ) {
                    instruction_counter = operand;

                    continue;
                }
                break;
            // * [ HALT ] - Terminate the simplesim execution.
            case OPCode::HALT:
                std::cout << "*** Simplesim execution terminated ***" << std::endl;

                return;
                break;

            // [ DEFAULT ] - Invalid opcode.
            default:
                std::cout << "*** ABEND: invalid opcode ***" << std::endl;
                return;
                break;
        }

        // Increment the instruction counter
        instruction_counter ++;

        // Check if the address is out of bounds
        if ( addr_oob(instruction_counter) ) { return; }
    }
}

/**
 * @brief Dump the contents of the simplesim's registers and memory.
 */
void simplesim::dump ( ) const {
    // Print the registers
    std::cout << std::endl << "REGISTERS:" << std::endl;
    print_register( "accumulator: ",          accumulator,          true  );
    print_register( "instruction_counter: ",  instruction_counter,  false );
    print_register( "instruction_register: ", instruction_register, true  );
    print_register( "operation_code: ",       operation_code,       false );
    print_register( "operand: ",              operand,              false );

    // Print the column numbers
    std::cout << std::endl << "MEMORY:" << std::endl << "  ";
    for ( int i = 0; i < 10; i++ ) {
        std::cout << "     " << i;
    }
    std::cout << std::endl;

    // Print the memory
    for ( int i = 0; i < 100; i++ ) {
        // Print the row number
        if ( i % 10 == 0 ) { std::cout << std::setw(2) << std::setfill(' ') << std::right << ( i  - i % 10 ) << " "; }

        // Print the memory contents
        print_word(memory[i], true);

        // Print a newline every 10 memory locations
        if ( i % 10 == 9 ) { std::cout << std::endl; }
    }
}