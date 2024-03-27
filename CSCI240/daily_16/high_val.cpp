//240 Highest Value daily

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define ARRAY_SIZE 20

void highestValue(float [], float [], float [], int);

int main() {
  float one[ARRAY_SIZE] = {36.2, 54.4, 41.0, 86.97, 40.99, 7.7, 77.77, 21.43, 20.2, 99.9, 73.37, 75.5, 16.6, 78.2, 40.4, 23.32, 76.1, 50.11, 10.10, 22.222};
  float two[ARRAY_SIZE] = {66.77, 17.43, 16.7, 41.88, 63.36, 53.53, 33.3, 95.26, 16.6, 38.81, 11.11, 68.5, 0.0, 31.5, 15.7, 29.2, 80.8, 56.0, 95.4, 82.2};
  float three[ARRAY_SIZE] = {60.0, 10.2, 52.4, 88.88, 78.87, 83.3, 46.8, 89.0, 68.7, 49.77, 52.25, 49.3, 25.4, 78.6, 74.1, 42.0, 52.6, 12.12, 41.14, 23.3};
  float four[ARRAY_SIZE] = {3.3, 67.4, 10.3, 99.4, 96.3, 63.0, 40.1, 2.2, 11.12, 28.4, 30.9, 22.5, 87.65, 72.27, 60.05, 30.3, 38.8, 64.4, 72.2, 32.1};
  float five[ARRAY_SIZE] = {45.4, 24.2, 68.6, 42.4, 13.1, 74.7, 65.6, 83.8, 86.8, 39.3, 7.7, 94.9, 80.8, 98.8, 46.4, 49.4, 24.2, 16.1, 72.7, 73.7};
  float six[ARRAY_SIZE] = {-45.4, -24.2, -68.6, -42.4, -13.1, -74.7, -65.6, -83.8, -86.8, -39.3, -7.7, -94.9, -80.8, -98.9, -46.4, -49.4, -24.2, -16.1, -72.7, -73.7};
  
  int numVals;

  //Display the largest values in the one, two, and three arrays
  cout << "Test 1: display the largest values from arrays one, two, and three" << endl;
  highestValue(one, two, three, ARRAY_SIZE);

  //Display the largest values in the four, five, and six arrays
  cout << endl << "Test 2: display the largest values from arrays four, five, and six" << endl;
  highestValue(four, five, six, ARRAY_SIZE);

  cout << endl << endl << "How many values should be searched? ";
  cin >> numVals;
  
  //Display the largest values in the two, four, and six arrays
  cout << endl << "Test 3: display the largest values from arrays two, four, and six"
       << endl << "        -- using first " << numVals << " values only" << endl;
  highestValue(two, four, six, numVals);

  //Display the largest values in the one, three, and five arrays
  cout << endl << "Test 4: display the largest values from arrays one, three, and five"
       << endl << "        -- using first " << numVals/2 << " values only" << endl;
  highestValue(one, three, five, numVals/2);
  
  return 0;
}


void highestValue(float arr_1[], float arr_2[], float arr_3[], int size) {
    float largest = arr_1[0];
    for ( int i = 0; i < size; i++ ) {
        largest = max(largest, arr_1[i]);
    }
    cout << "high in 1st array == " << fixed << setprecision(1) << largest << endl;


    largest = arr_2[0];
    for ( int i = 0; i < size; i++ ) {
        largest = max(largest, arr_2[i]);
    }
    cout << "high in 2nd array == " << fixed << setprecision(1)<< largest << endl;

    largest = arr_3[0];
    for ( int i = 0; i < size; i++ ) {
        largest = max(largest, arr_3[i]);
    }
    cout << "high in 3rd array == " << fixed << setprecision(1)<< largest << endl;
}


