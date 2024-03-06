/***************************************************************
CSCI 240         Compound Relational     Spring 2024

Programmer: John W

Section: 240-0002

Date Due: March 8th

Purpose: Better understand function headers.
***************************************************************/

/*

    /ᐠ - ˕ -マ

    @hiibolt on GitHub 

*/
//Compound Relational daily
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

//function prototype
void stats(int, int, int);

const int START_TEST = 5;
const int NUM_TESTS = 3;

int main()
{
  int num1, num2, num3;
  int rand_num1, rand_num2, rand_num3;
  int seed_value;

  //Get three numbers to test  
  cout << "What is the first number? ";
  cin >> num1;

  cout << "What is the second number? ";
  cin >> num2;

  cout << "What is the third number? ";
  cin >> num3;

  cout << endl << "What is the seed value for the random number generator? ";
  cin >> seed_value;

  //Test the function with user input
  cout << endl << "Test 1: check the \'stats\' on the numbers: " << num1 << ", " << num2 << ", and " << num3 << endl;

  stats(num1, num2, num3);


  //Test the function with known values
  cout << endl << "Test 2: check the \'stats\' on the numbers: 1, 5, and 9" << endl;

  stats(1, 5, 9);

  cout << endl << "Test 3: check the \'stats\' on the numbers: 6, 4, and 6" << endl;

  stats(6, 4, 6);

  cout << endl << "Test 4: check the \'stats\' on the numbers: 9, 5, and 1" << endl;

  stats(9, 5, 1);

  //test the function with random values
  
  //seed the random number generator with a value of 15
  srand(seed_value);

  //conduct the extra tests with the random numbers  
  for(int testNum = START_TEST; testNum < START_TEST + NUM_TESTS; testNum++)
    {
    //generate the three random numbers that will be used by the test
    rand_num1 = rand();
    rand_num2 = rand();
    rand_num3 = rand();
    
    //display the heading for the test, including the random numbers
    cout << endl << "Test " << testNum << ": check the \'stats\' on the numbers: "
         << rand_num1 << ", " << rand_num2 << ", and " << rand_num3 << endl;

    //determine the stats for the 3 random numbers
    stats(rand_num1, rand_num2, rand_num3);
	}

  return 0;
}

//Code the stats function below this line
void stats( int num_1, int num_2, int num_3 ) {
    cout << ((num_1 % 2 == 0 && num_2 % 2 == 0) ? "1 ": "") <<
            ((num_1 < num_2 && num_1 < num_3) ? "2 ": "") <<
            ((num_2 % 2 == 1 || num_3 % 2 == 1) ? "3 " : "") <<
            ((num_1 < num_3 || num_2 < num_3) ? "4 ": "");
}

