/***************************************************************
CSCI 241         John White     Spring 2024

Programmer: z19942444

Section: 241-0002

Date Due: Friday, August 31rst

Purpose: To solve the eight queens problem using recursion.
***************************************************************/

/*

    /ᐠ - ˕ -マ

    @hiibolt on GitHub 

*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;


/* Constants */
#define DEBUG false

/* Functions */
void generate_board ( bool board[8][8]               );
bool is_safe        ( bool board[8][8], int i, int g );
void print_board    ( bool board[8][8]               );
bool place_queens   ( bool board[8][8], int i        );


int main ( ) {
    bool board[8][8];

    // Build the board
    generate_board( board );

    // Place the queens.
    place_queens( board, 0 );

    // Output the board
    print_board( board );

    return 0;
}


/**
    * @brief Place the queens on the board.
    * 
    * @param board The board.
    * @param i The row.
    * 
    * @return True if the queens were placed, false otherwise.
    */
bool place_queens ( bool board[8][8], int i ) {
    if ( i > 7 ) {
        return true;
    }

    for ( int g = 0; g < 8; g++ ) {
        if ( is_safe( board, i, g ) ) {
            board[i][g] = true;

            if ( place_queens( board, i + 1 ) ) {
                return true;
            }
            
            board[i][g] = false;
        }
    }

    return false;
}

/**
    * @brief Check if it is safe to place a queen at the given position.
    * 
    * @param board The board.
    * @param i The row.
    * @param g The column.
    * 
    * @return True if it is safe to place a queen at the given position, false otherwise.
    */
bool is_safe ( bool board[8][8], int i, int g ) {
    if ( DEBUG ) { cout << "[ Checking (" << g << ", " << i << ") ]" << endl; }

    // Check for queens in column
    for ( int inner_i = i; inner_i >= 0; inner_i-- ) {
        if ( board[inner_i][g] ) {
            if ( DEBUG ) { cout << "Offending queen (center) at (" << g << ", " << inner_i << ")!" << endl; }

            return false;
        }
    }

    // Check for queens in the left diagonal
    for ( int inner_i = i, inner_g = g; inner_i >= 0 && inner_g >= 0; inner_i--, inner_g-- ) {
        if ( board[inner_i][inner_g] ) {
            if ( DEBUG ) { cout << "Offending queen (left) at (" << inner_g << ", " << inner_i << ")!" << endl; }

            return false;
        }
    }

    // Check for queens in right column one level above or below
    for ( int inner_i = i, inner_g = g; inner_i >= 0 && inner_g < 8; inner_i--, inner_g++ ) {
        if ( board[inner_i][inner_g] ) {
            if ( DEBUG ) { cout << "Offending queen (right) at (" << inner_g << ", " << inner_i << ")!" << endl; }

            return false;
        }
    }

    if ( DEBUG ) { cout << "Safe to place." << endl; }
    return true;
}

/**
    * @brief Print the board.
    * 
    * @param board The board.
    */
void print_board ( bool board[8][8] ) {
    for ( int i = 0; i < 8; i++ ) {
        for ( int g = 0; g < 8; g++ ) {
            cout << board[i][g] << " ";
        }
        cout << endl;
    }
}

/**
    * @brief Generate the board.
    * 
    * @param board The board.
    */
void generate_board ( bool board[8][8] ) {
    for ( int i = 0; i < 8; i++ ) {
        for ( int g = 0; g < 8; g++ ) {
            board[i][g] = false;
        }
    }
};
