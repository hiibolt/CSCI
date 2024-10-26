#include <iostream>


bool windback ( int a[], int b[], int len, int num_steps ) {
	if ( len < 1 || num_steps < 0 ) {
		return false;
	}

	for ( int i = 0; i < len; i++ ) {
		int new_i = ( i + num_steps ) % len;

		//std::cout << a[i] << " : " << new_i <<std::endl;

		b[new_i] = a[i];
	}

	return true;
};
