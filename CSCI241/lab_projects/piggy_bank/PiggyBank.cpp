//***************************************************************************
//
//  PiggyBank.cpp
//  CSCI 241 PiggyBank class implementation file
//
//  Created by Amy B
//
//***************************************************************************

#include "PiggyBank.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::cin;
using std::setprecision;
using std::fixed;

/********************************************************************************
 * PiggyBank constructor
 *
 * This default constructor creates an empty object.
 *
 * @return nothing
 ********************************************************************************/
PiggyBank::PiggyBank() {
    num_dimes = 0;

    num_quarters = 0;
}


/********************************************************************************
 * PiggyBank constructor
 *
 * This constructor creates an object using 2 passed in values.
 *
 * @param initDimes     the number of dimes the new PiggyBank object should hold
 * @param initQuarters  the number of quarters the new PiggyBank object should hold
 *
 * @return nothing
 *
 * @note There is no error-checking of the passed in values
 *
 ********************************************************************************/
PiggyBank::PiggyBank( int initDimes, int initQuarters ) {
    num_dimes = initDimes;

    num_quarters = initQuarters;
}


/********************************************************************************
 * print method
 *
 * This method displays the contents of a PiggyBank object and its monetary value
 *
 * @param none
 *
 * @return  none
 *
 * @note This method uses the private piggyBankValue method
 *
 ********************************************************************************/
void PiggyBank::print() {
    cout << "The piggy bank contains " << num_dimes << " dimes and " << num_quarters << " quarters." << endl;

    cout << "The piggy bank holds $" << fixed << setprecision(2) << piggyBankValue() << " in coins." << endl;
}



/********************************************************************************
 * addCoins method
 *
 * This method adds coins to a PiggyBank object using the 2 passed in values.
 *
 * @param moreDimes     the number of dimes to add to the PiggyBank object
 * @param moreQuarters  the number of quarters to add to the PiggyBank object
 *
 * @return nothing
 *
 * @note There is no error-checking of the passed in values
 *
 ********************************************************************************/
void PiggyBank::addCoins( int moreDimes, int moreQuarters ) {
    num_dimes += moreDimes;

    num_quarters += moreQuarters;
}


/********************************************************************************
 * piggyBankValue method
 *
 * This method calculates the monetary value of a PiggyBank object
 *
 * @param none
 *
 * @return  the monetary value of the piggybank
 *
 * @note This is a private helper method
 *
 ********************************************************************************/
double PiggyBank::piggyBankValue() {
    return ( num_dimes * 0.10 ) + ( num_quarters * 0.25 );
}

/********************************************************************************
 * operator== method
 *
 * This method compares two PiggyBank objects to see if they have the same value
 *
 * @param rhs  the PiggyBank object to compare to
 *
 * @return  true if the two objects have the same value, false otherwise
 *
 ********************************************************************************/
bool PiggyBank::operator==( const PiggyBank &rhs ) const {
    return ( num_dimes == rhs.num_dimes ) && ( num_quarters == rhs.num_quarters );
}