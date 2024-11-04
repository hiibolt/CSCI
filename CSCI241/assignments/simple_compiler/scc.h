/***************************************************************
*                            scc.h
*
*
* CSCI 241         John White     Fall 2024
*
* Programmer: z19942444
*
* Section: 241-0002
*
* Date Due: ASAP
*
* Purpose: Implement a Simple Compiler which converts Simple
*          programs into SimpleSim programs.
***************************************************************/

/*

    /ᐠ - ˕ -マ

    @hiibolt on GitHub 

*/



#ifndef SCC_H
#define SCC_H

#include <sstream>

/**
 * @brief Symbol table entry.
 *
 * @notes 'C' = constant, 'L' = Simple line number, 'V' = variable
 */
struct table_entry {
    int symbol = -1;
    char type = 'X';
    int location = -1;
};

/**
 * Simple compiler.
 */
class scc {
    public:
        // Exported constants
        static const int MEMORY_SIZE = 100;
        static const int SYMBOL_TABLE_SIZE = 1000;
        
        // Constructors
        scc();

        // Public methods
        void first_pass();
        void second_pass();
        void print_program() const;
    private:
        // Data members
        int memory[MEMORY_SIZE];
        int data[MEMORY_SIZE];
        int ndata = 0;
        
        // Symbol table
        table_entry symbol_table[SYMBOL_TABLE_SIZE];
        int flags[MEMORY_SIZE];
        
        // State trackers
        int next_instruction_addr = 0;
        int next_const_or_var_addr = MEMORY_SIZE - 1;
        int next_symbol_table_idx = 0;
        
        // Search and insertion modifiers
        int  find_or_insert_var ( int           );
        int  find_or_insert_con ( int           );
        void add_instruction    ( int, int = -1 );

        // Helper command methods
        void process_data        ( std::stringstream*              );
        void process_print_input ( std::stringstream*, std::string );
        void process_goto        ( std::stringstream*              );
        void process_if          ( std::stringstream*              );
        void process_let         ( std::stringstream*              );
        void process_end         ( std::stringstream*              );

        // Helper token methods
        void process_token_plus_mult ( std::string, int* );
        void process_token_minus_div ( std::string, int* );
};

#endif