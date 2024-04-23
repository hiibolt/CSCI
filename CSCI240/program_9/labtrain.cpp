/***************************************************************
CSCI 240         Assignment 9    Spring 2024

Programmer: John W (z1994244)

Section: 240-0002

Date Due: April 27th

Purpose: To extend the previously defined PiggyBank class with 
 extra functionality
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
        PiggyBank ( int, int, int, int );
        PiggyBank ( const PiggyBank& );

        // View Operations
        void print_bank       ( );
        void print_bank_value ( );
        void print            ( string );

        // Money Operations
        void      empty_bank   ( );
        void      add_pennies  ( int );
        void      add_nickels  ( int );
        void      add_dimes    ( int );
        void      add_quarters ( int );
        void      add_coins    ( int, int, int, int );
        PiggyBank add_banks    ( int, int, int, int );
        PiggyBank add_banks    ( PiggyBank );

        // Inquiry Operations
        int    get_coin     ( int );
        bool   is_equal     ( PiggyBank );
        bool   is_equal     ( int, int, int, int );
        bool   is_less_than ( PiggyBank);
        bool   is_less_than ( int, int, int, int );
        double calc_value   ( );
};

/* Utility Functions */
void print_section_title ( string );

/* Tests */
void test_1  ( PiggyBank*, PiggyBank*, PiggyBank*, PiggyBank*, PiggyBank* );
void test_2  ( PiggyBank*, PiggyBank*, PiggyBank*, PiggyBank*, PiggyBank* );
void test_3  ( PiggyBank*, PiggyBank*, PiggyBank*, PiggyBank*, PiggyBank* );
void test_4  ( PiggyBank*, PiggyBank*, PiggyBank*, PiggyBank*, PiggyBank* );
void test_5  ( PiggyBank*, PiggyBank*, PiggyBank*, PiggyBank*, PiggyBank* );
void test_6  ( PiggyBank*, PiggyBank*, PiggyBank*, PiggyBank*, PiggyBank* );
void test_7  ( PiggyBank*, PiggyBank*, PiggyBank*, PiggyBank*, PiggyBank* );
void test_8  ( PiggyBank*, PiggyBank*, PiggyBank*, PiggyBank*, PiggyBank* );
void test_9  ( PiggyBank*, PiggyBank*, PiggyBank*, PiggyBank*, PiggyBank* );

int main () {
    PiggyBank bank1( 12, 34, 56,  78 );
    PiggyBank bank2( 23, -5, -10, 31 );
    PiggyBank bank3( bank1           );
    PiggyBank bank4;
    PiggyBank bank5;

    test_1  ( &bank1, &bank2, &bank3, &bank4, &bank5 );
    test_2  ( &bank1, &bank2, &bank3, &bank4, &bank5 );
    test_3  ( &bank1, &bank2, &bank3, &bank4, &bank5 );
    test_4  ( &bank1, &bank2, &bank3, &bank4, &bank5 );
    test_5  ( &bank1, &bank2, &bank3, &bank4, &bank5 );
    test_6  ( &bank1, &bank2, &bank3, &bank4, &bank5 );
    test_7  ( &bank1, &bank2, &bank3, &bank4, &bank5 );
    test_8  ( &bank1, &bank2, &bank3, &bank4, &bank5 );
    test_9  ( &bank1, &bank2, &bank3, &bank4, &bank5 );

    return 0;
}


/**
 * @brief A constructor which creates a PiggyBank.
 *
 * @param (No params)               - Creates an empty PiggyBank
 *  [ or ]
 * @param (4 ints)                  - Creates a PiggyBank based on the coins provided
 *  [ or ]
 * @param (Const ref to PiggyBank) - Clones another bank
 * 
 * @return A PiggyBank with no coins.
 */
PiggyBank::PiggyBank () {
    empty_bank();
}
PiggyBank::PiggyBank ( int pennies, int nickels, int dimes, int quarters ) {
    empty_bank();
    add_coins( pennies, nickels, dimes, quarters );
}
PiggyBank::PiggyBank ( const PiggyBank &target_bank ) {
    empty_bank();
    add_coins( 
        target_bank.num_pennies,
        target_bank.num_nickels,
        target_bank.num_dimes,
        target_bank.num_quarters
    );
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
 * @brief This method combines two PiggyBanks, leaving 'self' untouched.
 * 
 * @param (4 ints)           - A representation of another PiggyBank
 *  [ or ]
 * @param (Const& PiggyBank) - Another Piggybank
 * 
 * @returns A double representing the USD value of the PiggyBank.
 */
PiggyBank PiggyBank::add_banks( int pennies, int nickels, int dimes, int quarters ) {
    PiggyBank pb( num_pennies, num_nickels, num_dimes, num_quarters );

    pb.add_coins( pennies,     nickels,     dimes,     quarters     );

    return pb;
}
PiggyBank PiggyBank::add_banks( PiggyBank target_bank ) {
    return add_banks(
        target_bank.num_pennies,
        target_bank.num_nickels,
        target_bank.num_dimes,
        target_bank.num_quarters
    );
}

/**
 * @brief This method prints the contents and value of a PiggyBank object.
 * 
 * @param string The title to be printed.
 * 
 * @returns A double representing the USD value of the PiggyBank.
 */
void PiggyBank::print ( string label ) {
    cout << label << endl;

    print_bank();
    print_bank_value();
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
 * @brief Gets a coin balance.
 *
 * @param int Index of the coin
 * 
 * @returns The balance of the coin.
 *
 *
 * @note 
 *  0 - Pennies
 *  1 - Nickels
 *  2 - Dimes
 *  3 - Quarters
 */
int PiggyBank::get_coin ( int index ) {
    switch ( index ) {
        case 0:
            return num_pennies;
            break;
        case 1:
            return num_nickels;
            break;
        case 2: 
            return num_dimes;
            break;
        case 3:
            return num_quarters;
            break;
        default:
            return -1;
    }
};
/**
 * @brief Asserts the equality of two PiggyBanks
 *
 * @param (4 ints)    - Integer representation of a PiggyBank balance
 *  [ or ]
 * @param (PiggyBank) - Complete PiggyBank object
 * 
 * @returns The result of the assertation
 */
bool PiggyBank::is_equal ( int pennies, int nickels, int dimes, int quarters ){
    return 
        num_pennies  == pennies &&
        num_nickels  == nickels &&
        num_dimes    == dimes   &&
        num_quarters == quarters;
};
bool PiggyBank::is_equal ( PiggyBank target_bank ){
    return is_equal(
        target_bank.num_pennies,
        target_bank.num_nickels,
        target_bank.num_dimes,
        target_bank.num_quarters
    );
};
/**
 * @brief Asserts 'self' having a lower monetary value than the provided PiggyBank
 *
 * @param (4 ints)    - Integer representation of a PiggyBank balance
 *  [ or ]
 * @param (PiggyBank) - Complete PiggyBank object
 * 
 * @returns The result of the assertation
 */
bool PiggyBank::is_less_than ( PiggyBank target_bank ) {
    return calc_value() < target_bank.calc_value();
};
bool PiggyBank::is_less_than ( int pennies, int nickels, int dimes, int quarters ) {
    return is_less_than( PiggyBank(pennies, nickels, dimes, quarters) );
};

/**
 * @brief Convenience function to head tests
 *
 * @param string Title for the section header
 */
void print_section_title ( string title ) {
    cout << "\n[ ---- " << title << "  ---- ]" << endl;
}

/**
 * @brief Various tests run on the PiggyBank class
 *
 * @param PiggyBank* Reference to the first PiggyBank
 * @param PiggyBank* Reference to the second PiggyBank
 */
void test_1 ( PiggyBank* bank1, PiggyBank* bank2, PiggyBank* bank3, PiggyBank* bank4, PiggyBank* bank5 ) {
    print_section_title( "Initial values in the bank objects" );

    bank1 -> print( "Bank 1: " );
    cout << endl;

    bank2 -> print( "Bank 2: " );
    cout << endl;

    bank3 -> print( "Bank 3: " );
}
void test_2 ( PiggyBank* bank1, PiggyBank* bank2, PiggyBank* bank3, PiggyBank* bank4, PiggyBank* bank5 ) {
    print_section_title( "Using the add_banks method with 4 arguments" );

    bank4 -> print( "(Initial) Bank 4: " );
    cout << endl;
    *bank4 = (bank2 -> add_banks( 4, 27, 45, 7 ));

    bank2 -> print( "Bank 2: " );
    cout << endl;

    bank4 -> print( "(Post-Addition) Bank 4: " );
}
void test_3 ( PiggyBank* bank1, PiggyBank* bank2, PiggyBank* bank3, PiggyBank* bank4, PiggyBank* bank5 ) {
    print_section_title( "Using the add_banks method with PiggyBank object" );

    bank1 -> print( "(Initial) Bank 1: ");
    cout << endl;

    bank2 -> print( "(Initial) Bank 2: ");
    cout << endl;

    bank5 -> print( "(Initial) Bank 5: ");
    cout << endl;


    *bank5 = (bank1 -> add_banks( *bank2 ));
    cout << endl;


    bank1 -> print( "(Post-Addition) Bank 1: ");
    cout << endl;

    bank2 -> print( "(Post-Addition) Bank 2: ");
    cout << endl;

    bank5 -> print( "(Post-Addition) Bank 5: ");
}
void test_4 ( PiggyBank* bank1, PiggyBank* bank2, PiggyBank* bank3, PiggyBank* bank4, PiggyBank* bank5 ) {
    print_section_title( "Using the is_equal method with 4 arguments" );

    cout << "Bank 4 " << (bank4 -> is_equal( 27, 27, 45, 38 ) ? "was equal" : "wasn't equal" ) << " to other bank" << endl;

    cout << "Bank 5 " << (bank5 -> is_equal( 35, 34, 15, 7  ) ? "was equal" : "wasn't equal" ) << " to other bank" << endl;
}
void test_5 ( PiggyBank* bank1, PiggyBank* bank2, PiggyBank* bank3, PiggyBank* bank4, PiggyBank* bank5 ) {
    print_section_title( "Using the is_equal method with PiggyBank object" );

    cout << "Bank 2 " << (bank2 -> is_equal( *bank5 ) ? "was equal" : "wasn't equal" ) << " to bank 5" << endl;

    cout << "Bank 1 " << (bank1 -> is_equal( *bank3 ) ? "was equal" : "wasn't equal" ) << " to bank 3" << endl;
}
void test_6 ( PiggyBank* bank1, PiggyBank* bank2, PiggyBank* bank3, PiggyBank* bank4, PiggyBank* bank5 ) {
    print_section_title( "Current values in the bank objects ");

    bank1 -> print( "Bank 1: " );
    cout << endl;

    bank2 -> print( "Bank 2: " );
    cout << endl;
    
    bank3 -> print( "Bank 3: " );
    cout << endl;
    
    bank4 -> print( "Bank 4: " );
    cout << endl;
    
    bank5 -> print( "Bank 5: " );
}
void test_7 ( PiggyBank* bank1, PiggyBank* bank2, PiggyBank* bank3, PiggyBank* bank4, PiggyBank* bank5 ) {
    print_section_title( "Using the is_less_than method with 4 arguments" );

    cout << "Bank 1 " << (bank1 -> is_less_than( 12, 33, 42, 108 ) ? "was less than" : "wasn't less than" ) << " other bank" << endl;

    cout << "Bank 2 " << (bank2 -> is_less_than( 3,  4,  70, 3   ) ? "Was less than" : "wasn't less than" ) << " other bank" << endl;
}
void test_8 ( PiggyBank* bank1, PiggyBank* bank2, PiggyBank* bank3, PiggyBank* bank4, PiggyBank* bank5 ) {
    print_section_title( "Using the is_less_than method with PiggyBank object" );

    cout << "Bank 3 " << (bank3 -> is_less_than( *bank5 ) ? "was less than" : "wasn't less than" ) << " bank 5" << endl;

    cout << "Bank 4 " << (bank4 -> is_less_than( *bank2 ) ? "Was less than" : "wasn't less than" ) << " bank 2" << endl;
}
void test_9 ( PiggyBank* bank1, PiggyBank* bank2, PiggyBank* bank3, PiggyBank* bank4, PiggyBank* bank5 ) {
    print_section_title( "Using the get_coin method" );

    cout << "Bank 1 | Index 0 (pennies)  | "  << (bank1 -> get_coin(0)) << endl;
    cout << "Bank 2 | Index 1 (nickels)  | "  << (bank2 -> get_coin(1)) << endl;
    cout << "Bank 3 | Index 2 (dimes)    | "    << (bank3 -> get_coin(2)) << endl;
    cout << "Bank 4 | Index 3 (quarters) | " << (bank4 -> get_coin(3)) << endl;
    cout << "Bank 5 | Index 4 (invalid)  | "  << (bank5 -> get_coin(4)) << endl;
}