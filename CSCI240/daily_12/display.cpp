/***************************************************************
CSCI 240         DisplayValues V2     Spring 2024

Programmer: John W

Section: 240-0002

Date Due: March 8th

Purpose: <purpose>
***************************************************************/

/*

    /ᐠ - ˕ -マ

    @hiibolt on GitHub 

*/
#include <iostream>
#include <iomanip>

using namespace std;

//displayValues function prototype
void displayValues(int, int);


int main()
  {
  int numValues, startValue;
  
  //Get the number of values to display and the first value to display
  cout << "How many values should be displayed? ";
  cin >> numValues;

  cout << "What is the starting display value? ";
  cin >> startValue;


  //Call the function 4 times
  for( int testNum = 1; testNum <= 4; testNum++ )
    {
    cout << endl << "Test " << testNum << ": " << numValues << " values starting from " << startValue;
    displayValues(numValues, startValue);
    
    //alter the number of values to display and the starting display value
	numValues -= 3;
	startValue += 7;    
    }

  return 0;
  }

//Code the displayValues function below this line
void displayValues( int num_values, int starting_num ) {
    cout << endl;
    if ( num_values < 0 ) {
        cout << "*** Invalid Number of Values ***" << endl;
        return;
    }
    for ( int i = starting_num; i < starting_num + num_values; i++ ) {
        cout << i << " ";
    }
    cout << endl;
}