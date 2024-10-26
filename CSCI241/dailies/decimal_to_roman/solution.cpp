#include <string>
#include <iostream>
#include <cmath>

int value ( int i ) {
	return pow ( 10, i / 2 ) * ( i % 2 == 0 ? 1 : 5 );
}
std::string decimal_to_roman ( int dec ) {
	std::string ret = "";
	
	char letters[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };

	for ( int i = 0; i < 7; i++ ) {
		//std::cout << letters[i] << ": " << value(i) << std::endl;
	}

	while ( dec > 0 ) {
		std::cout << dec << std::endl;

		for ( int i = 6; i > 0; i-- ) {
			std::cout << "Checking " << letters[i] << "(" << value(i) << ")" << std::endl;
			if ( dec >= value(i) ) {
				ret += letters[i];
				dec -= value(i);
				break;
			} else if ( dec >= value(i) - value(i - 1) ) {
				ret += letters[i];
				ret += letters[i - 1];
				dec -= value(i) - value(i - 1);
				break;
			}
		}
		
		while ( dec < 4 && dec > 0 ) {
			ret += 'I';
			dec -= 1;
		}
	}
	return ret;
};
