/***************************************************************
CSCI 241         John White     Spring 2024

Programmer: z19942444

Section: 241-0002

Date Due: Friday, September 15th

Purpose: Find the number of moves to move n disks from one peg to another using a third peg.
***************************************************************/

/*

    /ᐠ - ˕ -マ

    @hiibolt on GitHub 

*/


#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::atoi;


/**
    * Move n disks from the source peg to the destination peg using the temp peg.
    * 
    * @param n Number of disks to move.
    * @param src_peg Source peg.
    * @param dest_peg Destination peg.
    * @param temp_peg Temporary peg.
    */
void move(
    int n,
    int src_peg,
    int dest_peg,
    int temp_peg
) {
    // Base case - no disks to move.
    if ( n == 0 ) {
        return;
    }

    // Move n - 1 disks from the source peg to the temp peg.
    move (
        n - 1,
        src_peg,
        temp_peg, // Use the temp peg as the destination peg,
        dest_peg  //  and the destination peg as the temp peg.
    );

    // Move the largest disk from the source peg to the destination peg.
    cout << n << " " << src_peg << "->" << dest_peg << endl;

    // Move the n - 1 disks from the temp peg to the destination peg.
    move (
        n - 1,
        temp_peg, // Move all the disks *back* from the temp peg,
        dest_peg, //  to the destination peg,
        src_peg   //  using the source peg as temp (it's now free)
    );
}

int main ( 
    int argc, 
    char * argv[]
) {
    // Check if an argument was provided.
    if ( argc < 2 ) {
        cout << "Must provide the number of disks to move." << endl;
        return 1;
    }

    // Read the number of disks to move.
    int n = atoi(argv[1]);

    // Move the disks.
    move( 
        n, // Number of disks to move
        1, // Source peg
        2, // Destination peg
        3 // Temporary peg
    );

    return 0;
}