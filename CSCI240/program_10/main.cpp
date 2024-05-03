/***************************************************************
CSCI 240         Assignment 10       Spring 2024

Programmer: John W

Section: 240-0002

Date Due: May 3rd, 2024

Purpose: <purpose>
***************************************************************/

/*

    /ᐠ - ˕ -マ

    @hiibolt on GitHub 

*/

#include <iostream>
#include <iomanip>
#include <array>
#include <algorithm>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

/**
 * @brief Class representing an employee.
 *
 * @param char*  - Name of employee
 * @param char*  - ID of employee
 * @param double - Salary of employee
 */
class Employee {
    private:
        char   name[30];
        char   id[8];
        double salary;
    public:
        Employee ( );
        Employee ( const char *, const char *, double );

        void display ( );

        void increase_salary  ( double       );
        void set_id_num       ( const char * );
        void set_salary       ( double       );

        const char * get_name   ( );
        const char * get_id_num ( );
        double       get_salary ( );
};

int main(){
    cout << "[[ TEST 1 - Employee 1 ]]" << endl;
    Employee obj1("John White", "NIU4244", 53948.61);
    obj1.display();
    obj1.increase_salary(125.15);
    obj1.display();
    cout << endl << endl;

    cout << "[[ TEST 2 - Employee 2 ]]" << endl;
    Employee obj2;
    obj2.display();
    obj2.increase_salary(-2200.00);
    obj2.display();
    cout << endl << endl;

    cout << "[[ TEST 3 - Employee 3 ]]" << endl;
    Employee obj3("Blanche Devereaux", "TGG1985", 820.12);
    obj3.display();
    obj3.set_salary(82.88);
    obj3.set_id_num("TGP1992");
    obj3.display();
    cout << endl << endl;

    cout << "[[ TEST 4 - Employee 4 ]]" << endl;
    Employee obj4("Grace Hopper", "UNI1950", 2468.00);
    obj4.display();
    obj4.set_id_num("Cobol1959");
    obj4.increase_salary(9517.53);
    cout << obj4.get_name() << " has a salary of " << obj4.get_salary() << endl << endl;
    obj4.display();

    cout << "[[ TEST 5 - Employee 5 ]]" << endl;
    Employee obj5("Charlie Hudson", "REX2332", 71940.76);
    obj5.display();
    obj5.set_salary(-10000.01);
    cout << "Employee 5 has an identification number of " << obj5.get_id_num() << endl << endl;
    obj5.display();
}

/**
 * @brief Constructors for the Employee class.
 *
 * @param (No params) - Initializes to name of 'None', ID of 'ABC1234', and a
 *  salary of 0.00.
 * (OR)
 * @param char*  Name to be set
 * @param char*  ID to be set
 * @param double Salary to be set
 *
 * @return Newly built Employee object.
 */
Employee::Employee() {
    strcpy(name, "None");
    strcpy(id, "ABC1234");

    salary = 0.00;
}
Employee::Employee( const char * _name, const char * _id, double _salary ) {
    strcpy(name, _name);

    set_id_num ( _id );
    set_salary ( _salary );
}

/**
 * @brief Prints the current values of self (Employee object).
 */
void Employee::display() {
    cout << left << setw(30) << name 
        << right << setw(10) << id 
        << endl
        << '$' << fixed << setprecision(2) << salary << endl << endl;
}

/**
 * @brief Raises the salary of an employee
 *
 * @param double Amount to raise by
 *
 * @note Debugs error and does nothing if passed a value <= 0.
 */
void Employee::increase_salary ( double raise ) {
    if ( raise <= 0 )
        cout << "[ ERR: Raise value must be greater than zero! Salary not changed. ]" << endl;

    salary += max( raise, 0.00 );
}
/**
 * @brief Sets the ID of an employee.
 *
 * @param char* New ID for employee
 *
 * @note Debugs error and does nothing if given an invalid ID.
 */
void Employee::set_id_num ( const char * updated_id ) {
    if ( strlen( updated_id ) != 7 ) {
        cout << "[ ERR: ID was not exactly 7 characters. ID not changed. ]" << endl;

        return;
    } 
    for ( int i = 0; i < 7; i ++ ) {
        if ( updated_id[i] == '\0' ) {
            cout << "[ ERR: New ID must be 7 characters! ]" << endl;

            return;
        }

        if ( i < 3 && !isalpha(updated_id[i]) ) {
            cout << "[ ERR: Invalid ID! First three characters must be letters. ID not changed. ]" << endl;
            return;
        } else if ( i >= 3 && !isdigit(updated_id[i]) ) {
            cout << "[ ERR: Invalid ID! Last four characters must be digits. ID not changed. ]" << endl;
            return;
        }

        strcpy( id, updated_id );
    }
}
/**
 * @brief Sets the salary of an employee.
 *
 * @param double Salary of employee
 * 
 * @note Debugs error and does nothing if not given a value above zero.
 */
void Employee::set_salary ( double updated_salary ) {
    if ( updated_salary <= 0 ) {

        cout << "[ ERR: New salary must be greater than zero! Salary not changed. ]" << endl;
        return;
    }

    salary = updated_salary;
}

/**
 * @brief Get function for the 'name' field.
 *
 * @returns const char* representing the name.
 */
const char * Employee::get_name ( ) {
    return name;
}
/**
 * @brief Get function for the 'ID' field.
 *
 * @returns const char* representing the ID.
 */
const char * Employee::get_id_num ( ) {
    return id;
}
/**
 * @brief Get function for the 'salary' field.
 *
 * @returns double representing the name.
 */
double Employee::get_salary ( ) {
    return salary;
}