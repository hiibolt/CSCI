#include <cstddef>
#include <iostream>
#include <vector>

int last_int_standing ( size_t n, size_t step ) {
	std::vector<int> arr;

	for ( size_t i = 0; i < n; i ++ ) {
		arr.push_back(i + 1);
	}

	int i = 0;
	while ( arr.size() != 1 ) {
		i = ( i + step ) % arr.size();

		arr.erase( arr.begin() + i );

		i --;

		//std::cout << std::endl;
		//for ( int element : arr ) {
		//	std::cout << element;
		//} 
		//std::cout << std::endl;
	};

	return arr[0]; 
};
