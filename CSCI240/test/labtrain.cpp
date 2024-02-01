/*
 CSCI 240   Program 0   Spring 2023
 Alex Reynoso
 z2008951
 Rogness- 2
 Janurary 26th
 The purpose of this program is to calculate and display the gravitational force between two objects.
 The user provides the mass of the two objects and the distance between the objects.
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //declaring the variables were using
    const double gravatational_constant= 0.667 * pow(10,-11);
    double mass_obj_1;
    double mass_obj_2;
    double distance_between_objs = 0;
    
    cout << "Enter the mass of object 1 (in kilograms): \n";
    cin >> mass_obj_1;
    
    cout << "Enter the mass of object 2 (in kilograms): \n";
    cin >> mass_obj_2;
    
    cout << "Enter the distance between the two objects (in meters): \n";
    cin >> distance_between_objs;
    
    cout << "The force of gravatiational attraction is: " << gravatational_constant * mass_obj_1 * mass_obj_2 <<
        pow(distance_between_objs,2) << " newtons." << "\n";
    
    return 0;
}