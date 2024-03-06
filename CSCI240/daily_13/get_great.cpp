/***************************************************************
CSCI 240         <name>     Spring 2024

Programmer: <me>

Section: 240-0002

Date Due: <date>

Purpose: <purpose>
***************************************************************/

/*

    /ᐠ - ˕ -マ

    @hiibolt on GitHub 

*/

#include <iostream>
#include <iomanip>

using namespace std;

const double LOWER1 = 0.0;
const double LOWER2 = -240.99;

double getGreaterValue(string, double);

int main()
  {
  double num1, num2, num3, num4;

  cout << "The program will use the getGreaterValue function to get two values." << endl << endl;


  //value must be greater than LOWER1

  num1 = getGreaterValue("Enter a number", LOWER1);

  if( num1 <= LOWER1 )
    {
    cout << endl << "Test 1: FAIL -- the function did not return a value greater than " << LOWER1 << endl << endl;
    }
  else
    {
    cout << endl << "Test 1: SUCCESS" << endl << endl;
    }


  //value must be greater than LOWER2

  num2 = getGreaterValue("Enter a second number", LOWER2);

  if( num2 <= LOWER2 )
    {
    cout << endl << "Test 2: FAIL -- the function did not return a value greater than " << LOWER2 << endl << endl;
    }
  else
    {
    cout << endl << "Test 2: SUCCESS" << endl << endl;
    }


  //value must be greater than num2

  num3 = getGreaterValue("Enter a third number", num2);

  if( num3 <= num2 )
    {
    cout << endl << "Test 3: FAIL -- the function did not return a value greater than " << num2 << endl << endl;
    }
  else
    {
    cout << endl << "Test 3: SUCCESS" << endl << endl;
    }


  //value must be greater than num3

  num4 = getGreaterValue("Enter a fourth number", num3);

  if( num4 <= num3 )
    {
    cout << endl << "Test 4: FAIL -- the function did not return a value greater than " << num3 << endl;
    }
  else
    {
    cout << endl << "Test 4: SUCCESS" << endl;
    }

  return 0;
  }

double getGreaterValue( string msg, double min ) {
    double input;

    cout << msg << " (must be greater than " << min << "): ";

    cin >> input;

    while ( input <= min ) {
        cout << "Error: the value must be greater than " << min << ". Try again: ";

        cin >> input;
    } 

    return input;
}