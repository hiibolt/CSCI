//***************************************************************************
//
//  PiggyBank.h
//  CSCI 241 Class and Header File Example
//
//  Created by Amy B
//
//***************************************************************************

#ifndef PIGGYBANK_H

#define PIGGYBANK_H

class PiggyBank {
    public:
        PiggyBank();
        PiggyBank( int, int );
        void print();
        void addCoins( int, int );
        bool operator==( const PiggyBank & ) const;

    private:
        int num_dimes, num_quarters;

        double piggyBankValue();
};

#endif