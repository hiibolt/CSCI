/***************************************************************
CSCI 240         Program 1     Fall 2019

Programmer:

Section:

Date Due:

Purpose: The purpose of this program is to calculate and display
         the gravitational force between two objects.

         The user provides the mass of the two objects and the
         distance between the objects.
***************************************************************/

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main () {
    float mass_1;
    float mass_2;
    double distance = 0;
    const double gravity = 6.67 * pow(10, -11);

    cout << "Mass (kg) of object 1: ";
    cin >> mass_1;

    cout << "Mass (kg) of object 2: ";
    cin >> mass_2;

    cout << "Distance (m) between object 1 and 2 (must be non-zero): ";
    cin >> distance;

    cout << "Gravitational Force: " << gravity * mass_1 * mass_2 / pow(distance, 2);

    return 0;
}