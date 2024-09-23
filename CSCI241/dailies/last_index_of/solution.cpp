/***************************************************************
CSCI 241         John White     Spring 2024

Programmer: z19942444

Section: 241-0002

Date Due: Friday, September 20th

Purpose: Perform a quick sort.
***************************************************************/

/*

    /ᐠ - ˕ -マ

    @hiibolt on GitHub 

*/


/**
 * @brief Find the last index of a character in a string
 *  
 * @param s The string to search
 * @param c The character to find
 *  
 * @return The last index of the character in the string
 */
int last_index_of ( const char* s, char c ) {
    int ret = -1;

    for ( int i = 0; s[i] != '\0'; i++ ) {
        if ( s[i] == c ) {
            ret = i;
        }
    }

    return ret;
};