/***************************************************************
CSCI 241         John White     Spring 2024

Programmer: z19942444

Section: 241-0002

Date Due: ASAP

Purpose: Check if a string is a palindrome.
***************************************************************/

/*

    /ᐠ - ˕ -マ

    @hiibolt on GitHub 

*/


#include <string>
#include <iostream>

/**
 * @brief Check if a string is a palindrome
 * 
 * @param input The string to check
 * 
 * @return true if the string is a palindrome, false otherwise
 */
bool ispalindrome (const std::string& input ) {
    std::string filtered_input;

    for ( int i = 0; i < (int)input.size(); i++ ) {
        if ( isalpha(input[i]) ) {
            filtered_input += tolower(input[i]);
        }
    }


    for ( int i = 0; i < (int)(filtered_input.size() / 2); i++ ) {
        if ( filtered_input[i] != filtered_input[filtered_input.length() - i - 1] ) {
            return false;
        }
    }

    return true;
}
