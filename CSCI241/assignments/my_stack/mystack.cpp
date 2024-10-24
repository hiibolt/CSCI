
#include <cstddef>
#include <iostream>
#include "mystack.h"

// Constructors
/**
    * @brief Default constructor
    */
mystack::mystack ( ) {
    cap = 0;
    sz = 0;
    data = nullptr;
};
/**
    * @brief Copy constructor
    *
    * @param value The stack to copy
    */
mystack::mystack ( const mystack & value ) {
    cap = value.cap;
    sz = value.sz;
    data = new char[cap];
    for ( size_t i = 0; i < sz; i++ ) {
        data[i] = value.data[i];
    }
};
/**
    * @brief Destructor
    */
mystack::~mystack ( ) {
    delete[] data;
};

// Operators
/**
    * @brief Assignment operator
    *
    * @param rhs The stack to assign
    *
    * @return The assigned stack
    */
mystack & mystack::operator=  ( const mystack & rhs ) {
    if ( this != &rhs ) {
        delete[] data;
        cap = rhs.cap;
        sz = rhs.sz;
        data = new char[cap];
        for ( size_t i = 0; i < sz; i++ ) {
            data[i] = rhs.data[i];
        }
    }
    return *this;
};
/**
    * @brief Output operator
    *
    * @param os The output stream
    * @param obj The stack to output
    *
    * @return The output stream
    */
std::ostream& operator<< ( std::ostream& os, const mystack& obj ){
    for ( size_t i = 0; i < obj.sz; i++ ) {
        os << obj.data[i];
        
        if ( i < obj.sz - 1 ) {
            os << ", ";
        }
    }
    return os;
};

// Accessors
/**
    * @brief Get the capacity of the stack
    *
    * @return The capacity of the stack
    */
size_t mystack::capacity ( ) const {
    return cap;
};
/**
    * @brief Get the size of the stack
    *
    * @return The size of the stack
    */
size_t mystack::size ( ) const {
    return sz;
};
/**
    * @brief Check if the stack is empty
    *
    * @return True if the stack is empty, false otherwise
    */
bool mystack::empty ( ) const {
    return sz == 0;
};
/**
    * @brief Get the top element of the stack
    *
    * @return The top element of the stack
    */
const char& mystack::top ( ) const {
    return data[sz - 1];
};

// Mutators
/**
    * @brief Clear the stack
    *
    * @return Nothing
    */
void mystack::clear ( ) {
    sz = 0;
};
/**
    * @brief Reserve space for the stack
    *
    * @param n The number of elements to reserve space for
    *
    * @return Nothing
    */
void mystack::reserve ( size_t n ) {
    if (n > cap) {
        cap = n;

        char * temp = new char[n];
        for ( size_t i = 0; i < sz; i++ ) {
            temp[i] = data[i];
        }

        delete[] data;
        data = temp;
    }
};
/**
    * @brief Push an element onto the stack
    *
    * @param c The element to push
    *
    * @return Nothing
    */
void mystack::push ( char c ) {
    if ( sz == cap ) {
        if ( cap == 0 ) {
            reserve( 1 );
        } else {
            reserve( cap * 2 );
        }
    }

    data[sz] = c;
    sz++;
};
/**
    * @brief Pop an element from the stack
    *
    * @return Nothing
    */
void mystack::pop ( ) {
    sz--;
};