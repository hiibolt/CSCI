int count_hex_a ( int n ) {
	if ( n < 0 ) {
		return -1;
	}

	int num_a = 0;
	while ( n > 0 ) {
		int remainder = n % 16;
	
		if ( remainder == 10 ) {
			num_a += 1;
		}

		n = (n - remainder) / 16;
	}

	return num_a;
};


