//***************************************************************************
//
//  main.cpp
//  CSCI 241 Class and Header File example
//
//  Created by Amy B
//
//***************************************************************************


#include <iostream>
#include <iomanip>

#include "PiggyBank.h"

using std::cout;
using std::endl;
using std::cin;
using std::setprecision;


int main( ) {
    //Create two PiggyBank objects. The first one should be created using the
    //default constructor and the second should use the alternate constructor
    //to create an object with 17 dimes and 12 quarters
    PiggyBank bank1;
    PiggyBank bank2( 17, 12 );


    // First Bank Display
    cout << "First bank object" << endl;

    bank1.print();

    // Second Bank Display
    cout << endl << endl << "Second bank object" << endl;

    bank2.print();

    cout << endl << endl;


    //Add 15 dimes and 3 quarters to the first PiggyBank object and display
    //the updated value
    bank1.addCoins( 18, 14 );

    cout << "Updated first bank object" << endl;

    bank1.print();

    // Add 5 dimes and 7 quarters to the second PiggyBank object and display
    // the updated value
    bank2.addCoins( 1, 2 );

    cout << endl << endl << "Updated second bank object" << endl;

    bank2.print();

    cout << endl << endl;


    // Check if the two PiggyBank objects have the same value and display a
    // message indicating whether they do or not
    if ( bank1 == bank2 ) {
        cout << "The two PiggyBank objects have the same value." << endl;
    } else {
        cout << "The two PiggyBank objects do not have the same value." << endl;
    }


    return 0;
}







