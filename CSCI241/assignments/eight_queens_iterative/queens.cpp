/***************************************************************
CSCI 241         John White     Spring 2024

Programmer: z19942444

Section: 241-0002

Date Due: Friday, August 31rst

Purpose: To solve the eight queens problem using iteration.
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


/* Generators and modifiers */
void generate_board ( bool board[8][8]                     );

/* Board Assesors */
bool is_safe        ( bool board[8][8], int i, int g       );
int  where_to_place ( bool board[8][8], int i, int start_g );
int  find_queen     ( bool board[8][8], int i              );

/* Debug */
void print_board    ( bool board[8][8]                     );


int main ( ) {
    bool board[8][8];

    // Build the board
    generate_board( board );

    // Place the queens.
    int i = 0;
    int min_g = 0;
    while ( i < 8 ) {
        int g = where_to_place( board, i, min_g );

        if ( g == -1 ) {
            if ( DEBUG ) { cout << "No safe place in row, moving up!" << endl; }

            // Find the queen in the row above
            int queen_g = find_queen( board, i - 1 );

            // Remove the queen from the row above
            board[i - 1][queen_g] = false;

            // Set the minimum g to the queen's g
            min_g = queen_g + 1;

            i --;

            continue;
        } else {
            board[i][g] = true;

            min_g = 0;
        }
        
        // [DEBUG] Output the board
        if ( DEBUG ) {
            cout << "State: " << endl;
            print_board( board );
        }

        i ++;
    }

    // Output the board
    print_board( board );

    return 0;
}


/**
    * @brief Check where to place the next queen.
    *
    * @param board The board.
    * @param i The row.
    *
    * @return The column to place the queen.
    */
int where_to_place ( bool board[8][8], int i, int start_g ) {
    for ( int g = start_g; g < 8; g++ ) {
        // Check if it is safe to place the queen
        bool safe = is_safe( board, i, g );

        if ( !safe ) { // If it's not safe, keep moving
            continue;
        } else { // If it is safe, place the queen
            return g;
        }
    }

    // If we reach this point, we couldn't find 
    //  a safe place to place the queen
    return -1;
}

/**
    * Check if it is safe to place a queen at the given position.
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

    // Check for queens in left column one levels above or below
    if ( g > 0 ) {
        if ( DEBUG ) { cout << " - Must check left" << endl; }
        // Check one up
        if ( i > 0 && board[i - 1][g - 1] ) {
            if ( DEBUG ) { cout << "Offending queen (left) at (" << (g - 1) << ", " << (i - 1) << ")!" << endl; }

            return false;
        }

        // Check one down
        if ( i < 7 && board[i + 1][g - 1] ) {
            if ( DEBUG ) { cout << "Offending queen (left) at (" << (g - 1) << ", " << (i + 1) << ")!" << endl; }

            return false;
        }
    }

    // Check for queens in right column one levels above or below
    if ( g < 7 ) {
        if ( DEBUG ) { cout << " - Must check right" << endl; }
        // Check one up
        if ( i > 0 && board[i - 1][g + 1] ) {
            if ( DEBUG ) { cout << "Offending queen (right) at (" << (g + 1) << ", " << (i - 1) << ")!" << endl; }

            return false;
        }

        // Check one down
        if ( i < 7 && board[i + 1][g + 1] ) {
            if ( DEBUG ) { cout << "Offending queen (right) at (" << (g + 1) << ", " << (i + 1) << ")!" << endl; }

            return false;
        }
    }

    if ( DEBUG ) { cout << "Safe to place." << endl; }
    return true;
}

/**
    * Print the board.
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
    * Generate the board.
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

/**
    * Find the queen in the row.
    * 
    * @param board The board.
    * @param i The row.
    * 
    * @return The column where the queen is.
    */
int find_queen ( bool board[8][8], int i ) {
    for ( int g = 0; g < 8; g++ ) {
        if ( board[i][g] ) {
            return g;
        }
    }

    return -1;
}