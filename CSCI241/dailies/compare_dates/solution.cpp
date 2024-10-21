#include "date.h"
#include <iostream>

bool operator< ( const date& d1, const date& d2 ) {
	if ( d1.year < d2.year ) {
		return true;
	}
	if ( d1.month < d2.month ) {
		return true;
	}
	if ( d1.day < d2.day ) {
		return true;
	}
	return false;
};
