#include <string>
#include <iostream>
#include <cmath>

int value ( int i ) {
	return pow ( 10, i / 2 ) * ( i % 2 == 0 ? 1 : 5 );
}
std::string decimal_to_roman ( int num ) {
	std::string ret = "";
	
	while ( num > 0 ) {
            if ( num >= 1000 ) {
                num -= 1000;
                ret += 'M';
            } else if ( num >= 900 ) {
                num -= 900;
                ret += "CM";
            } else if ( num >= 500 ) {
                num -= 500;
                ret += 'D';
            } else if ( num >= 400 ) {
                num -= 400;
                ret += "CD";
            } else if ( num >= 100 ) {
                num -= 100;
                ret += 'C';
            } else if ( num >= 90 ) {
                num -= 90;
                ret += "XC";
            } else if ( num >= 50 ) {
                num -= 50;
                ret += 'L';
            } else if ( num >= 40 ) {
                num -= 40;
                ret += "XL";
            } else if ( num >= 10 ) {
                num -= 10;
                ret += 'X';
            } else if ( num >= 9 ) {
                num -= 9;
                ret += "IX";
            } else if ( num >= 5 ) {
                num -= 5;
                ret += 'V';
            } else if ( num >= 4 ) {
                num -= 4;
                ret += "IV";
            } else {
                num -= 1;
                ret += 'I';
            }
        }

	return ret;
};
