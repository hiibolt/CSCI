
void binary_increment ( int a[], int len ) {
	for ( int i = len - 1; i > 0; i-- ) {
		if ( a[i] == 0 ) {
			a[i] = 1;
 			return;
		}
		a[i] = 0;
	}		
};
