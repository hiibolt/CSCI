#include <iostream>

char* replace_copy ( char* destination, const char* source, char old_char, char new_char ) {
	int i = 0;

	while ( source[i] != '\0' ) {
		if ( source[i] == old_char ) {
			destination[i] = new_char;
		} else {
			destination[i] = source[i];
		}

		i++;
	}

	destination[i] = '\0';

	return destination;
};


