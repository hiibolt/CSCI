#include <iomanip>
#include <iostream>
#include <string>
#include "hash_table.h"

using std::endl;
using std::left;
using std::ostream;
using std::right;
using std::setfill;
using std::setw;
using std::string;

/**
 Hashes an integer key to produce a hash value.
 
 @param key - The integer key to hash.
 
 @return - Returns the integer hash value, an array subscript between 0 and
           TABLE_SIZE - 1.
 */
int hash_table::hash(int key) const
{
    return key % TABLE_SIZE;
}

/**
 Attempts to insert a key and value into the hash table.

 @param key - The integer key to insert.

 @param value - The string value to insert.

 @return - Returns true if successful; otherwise, false.
*/
bool hash_table::insert(int key, const string& value)
{
    int index = hash(key);
    for ( int i = 0; i < TABLE_SIZE - 1; i++ ) {
        int actual_i = (index + i) % TABLE_SIZE;

        table_element& element = table[actual_i];

        if (element.state == EMPTY || element.state == DELETED)
        {
            element.key = key;
            element.value = value;
            element.state = FILLED;
            return true;
        }
    }

    return false;
}

/**
 Attempts to find a key in the hash table.

 @param key - The integer key to find.

 @return - Returns the index of the table element that contains
           the key if successful; otherwise, returns -1.
*/
int hash_table::find(int key) const
{
    int index = hash(key);

    for ( int i = 0; i < TABLE_SIZE - 1; i++ ) {
        int actual_i = (index + i) % TABLE_SIZE;

        const table_element& element = table[actual_i];

        // Check that it's not empty
        if ( element.state == EMPTY ) {
            return -1;
        }

        // Check if it's what we're looking for
        if ( element.key == key ) {
            return actual_i;
        }
    }

    return -1;
}

/**
 Attempts to update the value of the record with the specified
 key.

 @param key - The integer key of the record to update.

 @param value - The new value to be used to update the record.

 @return - Returns true if successful; otherwise, false.
*/
bool hash_table::update(int key, const string& value)
{
    int index = hash(key);

    for ( int i = 0; i < TABLE_SIZE - 1; i++ ) {
        int actual_i = (index + i) % TABLE_SIZE;

        table_element& element = table[actual_i];

        if (element.state == EMPTY) {
            return false;
        } else if (element.key == key) {
            element.value = value;
            return true;
        }
    }

    return false;
}

/**
 Attempts to delete the record with the specified key from the 
 hash table.

 @param key - The integer key for the record to delete.

 @return - Returns true if successful; otherwise, false.
*/
bool hash_table::erase(int key)
{
    int index = hash(key);

    for ( int i = 0; i < TABLE_SIZE - 1; i++ ) {
        int actual_i = (index + i) % TABLE_SIZE;

        table_element& element = table[actual_i];

        if (element.state == EMPTY) {
            return false;
        } else if (element.key == key) {
            element.state = DELETED;
            return true;
        }
    }

    return false;
}

/**
 Prints the hash table in a formatted fashion on the specified
 output stream.

 @param os - The output stream on which to print the table.

 @param obj - The hash_table object to print.

 @return - The updated output stream.
*/
ostream& operator<<(ostream& os, const hash_table& obj)
{
    os << "Index  Key    Value\n";
    os << "===========================================================\n";

    for (int i = 0; i < obj.TABLE_SIZE; i++)
    {
        os << setfill(' ') << '[' << setw(2) << right << i << "]   ";
        
        if (obj.table[i].state == EMPTY)
            os << "EMPTY";
        else if (obj.table[i].state == DELETED)
            os << "DELETED";
        else
            os << setfill('0') << right << setw(4) << obj.table[i].key
               << "   " << setfill(' ') << left << obj.table[i].value;
        
        os << endl;
    }
    
    return os;
}

