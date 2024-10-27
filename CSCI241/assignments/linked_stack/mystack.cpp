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


#include <cstddef>
#include <iostream>

#include "mystack.h"


/**
 * @brief Default constructor
 */
mystack::mystack ( ) {
	this->data = nullptr;
	this->sz = 0;
};
/**
 * @brief Deep Copy connstructor
 *
 * @arg const mystack& The mystack to deep copy from
 */
mystack::mystack ( const mystack & value ) {
	this->sz = 0;
	this->data = nullptr;

	Node* cursor = value.data;
	while ( cursor != nullptr ) {
		// Create the first node if needed
		if ( this->data == nullptr ) {
			this->data = new Node {
				cursor->val,
				nullptr
			};
			this->sz++;

			cursor = cursor->next;

			continue;
		}

		// Find the last node
		Node* inner_cursor = this->data;
		while ( inner_cursor->next != nullptr ) {
			inner_cursor = inner_cursor->next;	
		}

		// Append the value
		inner_cursor->next = new Node {
			cursor->val,
			nullptr	
		};
		this->sz++;

		cursor = cursor->next;
	}
};
/**
 * @brief Destructor
 */
mystack::~mystack ( ) {
	while ( !this->empty() ) {
		this->pop();
	}
};


/**
 * @brief Deep copy assignment operator
 *
 * @arg const mystack& The rhs mystack to copy from
 */
mystack & mystack::operator=  ( const mystack & rhs ) {
	while ( !this->empty() ) {
		this->pop();
	}

	Node* cursor = rhs.data;
	while ( cursor != nullptr ) {
		// Create the first node if needed
		if ( this->data == nullptr ) {
			this->data = new Node {
				cursor->val,
				nullptr
			};
			this->sz++;

			cursor = cursor->next;
			
			continue;
		}

		// Find the last node
		Node* inner_cursor = this->data;
		while ( inner_cursor->next != nullptr ) {
			inner_cursor = inner_cursor->next;	
		}

		// Append the value
		inner_cursor->next = new Node {
			cursor->val,
			nullptr	
		};
		this->sz++;

		cursor = cursor->next;
	}
	return *this;
};
/**
 * @brief Conversion operator for output to `ostream`
 *
 * @arg ostream&       The `ostream` to output to
 * @arg const mystack& The object to output from
 */
std::ostream& operator<< ( std::ostream& os, const mystack& obj ) {
	Node* cursor = obj.data;

	while ( cursor != nullptr ) {
		os << cursor->val;

		if ( cursor->next != nullptr ) {
			os << ", ";
		}

		cursor = cursor->next;
	}

	return os;
};

/**
 * @brief Getter for the size of the stack
 *
 * @return size_t The internal size of the stack
 */
size_t mystack::size ( ) const {
	return this->sz;
};
/**
 * @brief Gets whether the stack is empty or not
 *
 * @return bool Boolean signaling true if the stack is empty, otherwise false
 */
bool mystack::empty ( ) const {
	return this->sz == 0;
};
/** 
 * @brief Gets a reference to the top item
 *
 * @return const int& The reference to the top item
 */
const int& mystack::top ( ) const {
	return this->data->val;
};

/**
 * @brief Clears the entire stack
 */
void mystack::clear ( ) {
	while ( !this->empty() ) {
		this->pop();
	}
};
/**
 * @brief Adds a new node to the stack
 *
 * @arg int The new value to add to the stack
 */
void mystack::push ( int c ) {
	Node* new_node = new Node { 
		c,        // val
		this->data // next
	};

	this->data = new_node;
	this->sz ++;
};
/**
 * @brief Removes the top node from the stack
 *
 * @notes Does not return anything. Use the `top` function to 
 *  get the top value before popping anything.
 */
void mystack::pop ( ) {
	Node* top_node = this->data;

	this->data = top_node->next;
	this->sz --;

	delete top_node;
};
