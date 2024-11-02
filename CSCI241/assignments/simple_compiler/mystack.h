#ifndef MYSTACK_H
#define MYSTACK_H

#include <cstddef>
#include <iostream>

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
        const char& top      ( ) const;

        // Mutators
        void clear   (          );
        void reserve ( size_t n );
        void push    ( char c   );
        void pop     (          );
    private:
        char * data;
        size_t cap;
        size_t sz;
};

#endif