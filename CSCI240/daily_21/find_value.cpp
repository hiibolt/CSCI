//CSCI 240 daily - Find Value

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int ARRAY_1_SIZE = 5,
          ARRAY_2_SIZE = 9,
          ARRAY_3_SIZE = 10,
          ARRAY_4_SIZE = 6,
          ARRAY_5_SIZE = 8,
          ARRAY_6_SIZE = 10;

void print_array( double [], int );
int find_value( double [], int, double );


int main()
  {
  double array1[ARRAY_1_SIZE]= {0.1, 2.3, 4.5, 6.7, 8.9};
  double array2[ARRAY_2_SIZE]= {5.2, 0.7, 1.1, 8.7, 2.3, 3.7, 6.6, 9.0, 4.4};
  double array3[ARRAY_3_SIZE]= {6.1, 1.2, 2.3, 7.4, 8.5, 3.6, 0.7, 5.8, 9.9, 4.0};
  double array4[ARRAY_4_SIZE]= {5.5, 1.1, 3.3, 2.2, 6.6, 4.4};
  double array5[ARRAY_5_SIZE]= {0.2, 2.4, 3.6, 4.8, 5.0, 6.2, 7.4, 8.6};
  double array6[ARRAY_6_SIZE]= {10.3, 8.5, 4.7, 9.9, 1.1, 5.3, 0.5, 7.7, 6.9, 3.6};

  //Get the test number to run
  int test_num, found_sub;
  
  cout << setprecision(1) << fixed;
  
  cout << "Test number? ";
  cin >> test_num;

  //execute test number 1 with array1
  if( test_num == 1 )
    {
    //Display the values in the array
	cout << endl << "Array values = ";
    print_array(array1, ARRAY_1_SIZE);

    //Find the location of a number in the array
    found_sub = find_value(array1, ARRAY_1_SIZE, array1[ARRAY_1_SIZE - test_num]);

    //Display the search number and whether the function succeeded or failed
    cout << endl << "The value " << array1[ARRAY_1_SIZE - test_num] << " is ";

	if(found_sub == -1)
	  cout << "not found in the array" << endl;
	else
	  cout << "found at [" << found_sub << "]" << endl;

    cout << ((found_sub == ARRAY_1_SIZE - test_num)? "SUCCESS" : "FAIL") << endl;
	}
  //execute test number 2 with array2
  else if( test_num == 2 )
    {
    //Display the values in the array
	cout << endl << "Array values = ";
    print_array(array2, ARRAY_2_SIZE);

    //Find the location of a number in the array
    found_sub = find_value(array2, ARRAY_2_SIZE, 5.2);

    //Display the search number and whether the function succeeded or failed
    cout << endl << "The value 5.2 is ";
	if(found_sub == -1)
	  cout << "not found in the array" << endl;
	else
	  cout << "found at [" << found_sub << "]" << endl;

    cout << ((found_sub == 0)? "SUCCESS" : "FAIL") << endl;
	}
  //execute test number 3 with array3
  else if( test_num == 3 )
    {
    int random_sub, seed_value;

    cout << endl << "Seed value? ";
    cin >> seed_value;

    srand(seed_value);

    //Display the values in the array
	cout << endl << "Array values = ";
    print_array(array3, ARRAY_3_SIZE);

    //calculate a random subscript for the 3rd array
    random_sub = rand() % ARRAY_3_SIZE;
    
    //Find the location of a number in the array
    found_sub = find_value(array3, ARRAY_3_SIZE, array3[random_sub]);

    //Display the search number and whether the function succeeded or failed
    cout << endl << "The value " << array3[random_sub] << " is ";
	if(found_sub == -1)
	  cout << "not found in the array" << endl;
	else
	  cout << "found at [" << found_sub << "]" << endl;

    cout << ((found_sub == random_sub)? "SUCCESS" : "FAIL") << endl;
	}
  //execute test number 4 with array4
  else if( test_num == 4 )
    {
    //Display the values in the array
	cout << endl << "Array values = ";
    print_array(array4, ARRAY_4_SIZE);

    //Find the location of a number in the array
    found_sub = find_value(array4, ARRAY_4_SIZE, 1.1);

    //Display the search number and whether the function succeeded or failed
    cout << endl << "The value 1.1 is ";
	if(found_sub == -1)
	  cout << "not found in the array" << endl;
	else
	  cout << "found at [" << found_sub << "]" << endl;

    cout << ((found_sub == 1)? "SUCCESS" : "FAIL") << endl;
	}
  //execute test number 5 with array5 and array6
  else
    {
    //Display the values in the array
	cout << endl << "Array values = ";
    print_array(array4, ARRAY_4_SIZE);

    //Find the location of a number in the array
    found_sub = find_value(array4, ARRAY_4_SIZE, 3.6);

    //Display the search number and whether the function succeeded or failed
    cout << endl << "The value 3.6 is ";
	if(found_sub == -1)
	  cout << "not found in the array" << endl;
	else
	  cout << "found at [" << found_sub << "]" << endl;

    cout << ((found_sub == -1)? "SUCCESS" : "FAIL") << endl;

    //Display the values in the array
	cout << endl << "Array values = ";
    print_array(array5, ARRAY_5_SIZE);

    //Find the location of a number in the array
    found_sub = find_value(array5, ARRAY_5_SIZE, 3.6);

    //Display the search number and whether the function succeeded or failed
    cout << endl << "The value 3.6 is ";
	if(found_sub == -1)
	  cout << "not found in the array" << endl;
	else
	  cout << "found at [" << found_sub << "]" << endl;

    cout << ((found_sub == 2)? "SUCCESS" : "FAIL") << endl;


    //Display the values in the array
	cout << endl << "Array values = ";
    print_array(array6, ARRAY_6_SIZE);

    //Find the location of a number in the array
    found_sub = find_value(array6, ARRAY_6_SIZE, 3.6);

    //Display the search number and whether the function succeeded or failed
    cout << endl << "The value 3.6 is ";
	if(found_sub == -1)
	  cout << "not found in the array" << endl;
	else
	  cout << "found at [" << found_sub << "]" << endl;

    cout << ((found_sub == 9)? "SUCCESS" : "FAIL") << endl;
	}


  return 0;
  } // end main()


//This function displays the values in an array
void print_array(double a[], int l)
  {
  int i;

  //Display a leading [ and all but the last value
  cout << "[";
  for (i = 0; i < l-1; i ++)
	  cout << a[i] << ", ";

  //Display the last value in the array and the ending ]
  cout << a[l-1] << "]" << endl;
  } // print_array()


int find_value( double* target, int len, double input ) {
    for ( int i = 0; i < len; i++ ) {
        if ( target[i] == input ) {
            return i;
        }
    }
    return -1;
}