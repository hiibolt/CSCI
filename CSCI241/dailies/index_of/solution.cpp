/**
    * @brief  Returns the index of the first occurrence of a character in a string.
    *
    * @param s The string.
    * @param c The character to find.
    *
    * @return The index of the first occurrence of c in s, or -1 if c is not found.
    */
int index_of ( const char* s, char c ) {
    for ( int i = 0; s[i] != '\0'; i++ ) {
        if ( s[i] == c ) {
            return i;
        }
    }

    return -1;
}