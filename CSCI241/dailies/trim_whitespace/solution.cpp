#include <iostream>
#include <string>
#include <cstring>

bool is_whitespace ( char c ) {
	return ( c == ' ' || c == '\n' || c == '\t' );
};
char* trim ( char *destination, const char *source ) {
	int first = -1;
	int last = -1;
	int len = std::strlen(source);

	for ( int i = 0; i < len; i++ ) {
		if ( first == -1 && !is_whitespace(source[i] ) ) {
			first = i;
			break;
		}
	}

	for ( int i = len - 1; i > 0; i-- ) {
		if ( last == -1 && !is_whitespace( source[i] ) ) {
			last = i + 1;
			break;
		}
	}

	int i = 0;
	for ( int ind = first; ind < last; ind++ ) {
		destination[i] = source[ind];
		i++;
	}
	destination[i] = '\0';	

	return destination;	
};

