/***************************************************************
CSCI 241         John White     Spring 2024

Programmer: z19942444

Section: 241-0002

Date Due: ASAP

Purpose: Linked Stack implementation
***************************************************************/

/*

    /ᐠ - ˕ -マ

    @hiibolt on GitHub 

*/


#ifndef MYSTACK_H
#define MYSTACK_H

#include <cstddef>
#include <iostream>


struct Node {
	int   val;
	Node * next;
};

class mystack {
    public:
        // Constructors
        mystack  (                       );
        mystack  ( const mystack & value );
        ~mystack (                       );

        // Operators
        mystack & operator=  ( const mystack & rhs             );
        friend std::ostream&  operator<< ( std::ostream& os, const mystack& obj );

        // Accessors
        size_t      capacity ( ) const;
        size_t      size     ( ) const;
        bool        empty    ( ) const;
        const int& top      ( ) const;

        // Mutators
        void clear   (          );
        void reserve ( size_t n );
        void push    ( int c    );
        void pop     (          );
    private:
        Node * data;
        size_t sz;
};

#endif
