/***************************************************************
CSCI 240         Assignment 8    Spring 2024

Programmer: John W (z1994244)

Section: 240-0002

Date Due: April 20th?

Purpose: To create a class which represents a physical piggy bank.
***************************************************************/

/*

    /ᐠ - ˕ -マ

    @hiibolt on GitHub 

*/

#include <iostream>
#include <iomanip>
#include <array>
#include <algorithm>
#include <string>

using namespace std;

#define ENTRY_WIDTH 10


/**
 * @brief A class which keeps track of the number of pennies, nickels,
 *  dimes, and quarters.
 *
 * This class provides methods for adding, emptying, and counting the 
 *  available funds.
 */
class PiggyBank {
    private:
        int num_pennies;
        int num_nickels;
        int num_dimes;
        int num_quarters;
    public:
        // Default Constructor
        PiggyBank ();

        // View Operations
        void print_bank       ( );
        void print_bank_value ( );

        // Money Operations
        void empty_bank   ( );
        void add_pennies  ( int );
        void add_nickels  ( int );
        void add_dimes    ( int );
        void add_quarters ( int );
        void add_coins    ( int, int, int, int );

        // Summation Operation
        double calc_value ( );
};

/* Tests */
void test_1( PiggyBank*, PiggyBank* );
void test_2( PiggyBank*, PiggyBank* );
void test_3( PiggyBank*, PiggyBank* );
void test_4( PiggyBank*, PiggyBank* );
void test_5( PiggyBank*, PiggyBank* );
void test_6( PiggyBank*, PiggyBank* );
void test_7( PiggyBank*, PiggyBank* );
void test_8( PiggyBank*, PiggyBank* );

int main () {
    PiggyBank bank1;
    PiggyBank bank2;

    test_1 ( &bank1, &bank2 );
    test_2 ( &bank1, &bank2 );
    test_3 ( &bank1, &bank2 );
    test_4 ( &bank1, &bank2 );
    test_5 ( &bank1, &bank2 );
    test_6 ( &bank1, &bank2 );
    test_7 ( &bank1, &bank2 );
    test_8 ( &bank1, &bank2 );

    return 0;
}


/**
 * @brief A default constructor which creates a PiggyBank with no coins.
 *
 * @return A PiggyBank with no coins.
 */
PiggyBank::PiggyBank () {
    empty_bank();
}
/**
 * @brief Resets all coins in a PiggyBank to zero.
 */
void PiggyBank::empty_bank () {
    num_pennies  = 0;
    num_nickels  = 0;
    num_dimes    = 0;
    num_quarters = 0;
}
/**
 * @brief Outputs all coin balances to stdout.
 */
void PiggyBank::print_bank () {
    cout << setw(ENTRY_WIDTH) << left << "Pennies: "  << right << num_pennies  << " | "
         << setw(ENTRY_WIDTH) << left << "Nickels: "  << right << num_nickels  << " | "
         << setw(ENTRY_WIDTH) << left << "Dimes: "    << right << num_dimes    << " | "
         << setw(ENTRY_WIDTH) << left << "Quarters: " << right << num_quarters << endl;
}
/**
 * @brief Outputs the total value in USD to stdout via the 
 *  calc_value function.
 */
void PiggyBank::print_bank_value () {
    cout << "$" << fixed << setprecision(2) << calc_value() << endl;
}
/**
 * @brief Adds all four types of coins to the current balances.
 * 
 * @param int # of pennies to add
 * @param int # of nickels to add
 * @param int # of dimes to add
 * @param int # of quarters to add
 *
 * @note All four inputs are checked to be positive, a negative
 *  value will have no effect.
 */
void PiggyBank::add_coins ( int pennies, int nickels, int dimes, int quarters ) {
    if ( pennies < 0 ) {
        cout << "[ ERR: Can't add negative 'pennies'! ]"  << endl;
    }
    if ( nickels  < 0 ) {
        cout << "[ ERR: Can't add negative 'nickels'! "  << endl;
    }
    if ( dimes    < 0 ) {
        cout << "[ ERR: Can't add negative 'dimes'! ]"    << endl;
    }
    if ( quarters < 0 ) {
        cout << "[ ERR: Can't add negative 'quarters'! ]" << endl;
    }

    num_pennies  += max( pennies,  0 );
    num_nickels  += max( nickels,  0 );
    num_dimes    += max( dimes,    0 );
    num_quarters += max( quarters, 0 );
}
/**
 * @brief Adds a specific type of coin.
 * 
 * @param int # of that coin to add.
 *
 * @note Inputs is checked to be positive, a negative
 *  value will have no effect.
 */
void PiggyBank::add_pennies ( int pennies ) {
    if ( pennies < 0 ) {
        cout << "[ ERR: Can't add negative 'pennies'! ]"  << endl;
    }
    num_pennies += max( pennies, 0 );
}
void PiggyBank::add_nickels ( int nickels ) {
    if ( nickels < 0 ) {
        cout << "[ ERR: Can't add negative 'nickels'! ]"  << endl;
    }
    num_nickels += max( nickels, 0 );
}
void PiggyBank::add_dimes ( int dimes ) {
    if ( dimes < 0 ) {
        cout << "[ ERR: Can't add negative 'dimes'! ]"    << endl;
    }
    num_dimes += max( dimes, 0 );
}
void PiggyBank::add_quarters ( int quarters ) {
    if ( quarters < 0 ) {
        cout << "[ ERR: Can't add negative 'quarters'! ]" << endl;
    }
    num_quarters += max( quarters, 0 );
}
/**
 * @brief Calculates the total value of the PiggyBank.
 * 
 * @returns A double representing the USD value of the PiggyBank.
 */
double PiggyBank::calc_value () {
    return (num_pennies * 0.01) + (num_nickels * 0.05) + (num_dimes * 0.1) + (num_quarters * 0.25);
}


/**
 * @brief Various tests run on the PiggyBank class
 *
 * @param PiggyBank* Reference to the first PiggyBank
 * @param PiggyBank* Reference to the second PiggyBank
 */
void test_1 ( PiggyBank* bank1, PiggyBank* bank2 ) {
    cout << "***** Test 1: Default Constructor and printPiggyBank *****" << endl << endl;
    cout << fixed << setprecision(2);

    cout << "bank1:" << endl;
    bank1->print_bank();

    cout << endl << endl << "bank2:" << endl;
    bank2->print_bank();
}
void test_2 ( PiggyBank* bank1, PiggyBank* bank2 ) {
    cout << endl << endl << endl << "***** Test 2: print_bank_value *****" << endl << endl
        << "bank1:" << endl;
    bank1->print_bank();

    cout << endl << "Total: ";
    bank1->print_bank_value();
}
void test_3 ( PiggyBank* bank1, PiggyBank* bank2 ) {
    cout << endl << endl << endl << "***** Test 3: add_coins Method *****" << endl << endl
        << "3a: Adding 2 pennies, 47 nickels, 20 dimes, and 5 quarters to bank1 produces:"
        << endl << endl;

    bank1->add_coins( 2, 47, 20, 5 );
    bank1->print_bank();

    cout << endl << "Total: ";
    bank1->print_bank_value();

    cout << endl << endl << "3b: Adding 143 pennies, 9 nickels, 0 dimes, and 44 quarters to bank2 produces:"
        << endl << endl;
    bank2->add_coins( 143, 9, 0, 44 );
    bank2->print_bank();

    cout << endl << "Total: ";
    bank2->print_bank_value();
}
void test_4 ( PiggyBank* bank1, PiggyBank* bank2 ) {
    cout << endl << endl << endl << "***** Test 4: add_pennies Method *****" << endl << endl
        << "4a: Adding 95 pennies to bank1:" << endl << endl;
    bank1->add_pennies( 95 );
    bank1->print_bank();

    cout << endl << "Total: ";
    bank1->print_bank_value();

    cout << endl << endl << "4b: Adding -54 pennies to bank1:" << endl << endl;
    bank1->add_pennies( -54 );
    bank1->print_bank();

    cout << endl << "Total: ";
    bank1->print_bank_value();
}
void test_5 ( PiggyBank* bank1, PiggyBank* bank2 ) {
    cout << endl << endl << endl << "***** Test 5: add_nickels Method *****" << endl << endl
        << "5a: Adding -12 nickels to bank2:" << endl << endl;
    bank2->add_nickels( -12 );
    bank2->print_bank();

    cout << endl << "Total: ";
    bank2->print_bank_value();

    cout << endl << endl << "5b: Adding 17 nickels to bank2:" << endl << endl;
    bank2->add_nickels(17);
    bank2->print_bank();

    cout << endl << "Total: ";
    bank2->print_bank_value();
}
void test_6 ( PiggyBank* bank1, PiggyBank* bank2 ) {
    cout << endl << endl << endl << "***** Test 6: add_dimes Method *****" << endl << endl
        << "6a: Adding 157 dimes to bank2:" << endl << endl;
    bank2->add_dimes( 157 );
    bank2->print_bank();

    cout << endl << "Total: ";
    bank2->print_bank_value();

    cout << endl << endl << "6b: Adding -37 dimes to bank2:" << endl << endl;
    bank2->add_dimes( -37 );
    bank2->print_bank();

    cout << endl << "Total: ";
    bank2->print_bank_value();
}
void test_7 ( PiggyBank* bank1, PiggyBank* bank2 ) {
    cout << endl << endl << endl << "***** Test 7: add_quarters Method *****" << endl << endl
        << "7a: Adding 14 quarters to bank1: " << endl << endl;
    bank1->add_quarters( 14 );
    bank1->print_bank();

    cout << endl << "Total: ";
    bank1->print_bank_value();

    cout << endl << endl << "7b: Adding -45 quarters to bank1:" << endl << endl;
    bank1->add_quarters( -45 );
    bank1->print_bank();

    cout << endl << "Total: ";
    bank1->print_bank_value();
}
void test_8 ( PiggyBank* bank1, PiggyBank* bank2 ) {
    cout << endl << endl << endl << "***** Test 8: Calculating the Bank Values *****" << endl << endl;
    
    double bank1value = bank1->calc_value(), bank2value = bank2->calc_value();
    double total = bank1value + bank2value;

    cout << "$" << bank1value << " + $" << bank2value << " = $" << total << endl << endl;
}
void test_9 ( PiggyBank* bank1, PiggyBank* bank2 ) {
    cout << endl << endl << endl << "***** Test 9: Emptying the PiggyBanks *****" << endl << endl
        << "It\'s time to empty the banks!" << endl << endl;
    cout << endl << "9a: bank1 initially contains: " << endl << endl;
    bank1->print_bank();

    cout << endl << "Total: ";
    bank1->print_bank_value();

    bank1->empty_bank();
    cout << endl << endl << "bank1 now contains: " << endl << endl;
    bank1->print_bank();

    cout << endl << "Total: ";
    bank1->print_bank_value();

    cout << endl << endl << endl << "9b: bank2 initially contains: " << endl << endl;
    bank2->print_bank();

    cout << endl << "Total: ";
    bank2->print_bank_value();

    bank2->empty_bank();
    cout << endl << endl << "bank2 now contains: " << endl << endl;
    bank2->print_bank();

    cout << endl << "Total: ";
    bank2->print_bank_value();

    cout << endl << endl;
}