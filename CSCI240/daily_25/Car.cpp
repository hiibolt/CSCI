//CSCI 240 - Basic Car Class Daily

#include <iostream>
#include <iomanip>

using namespace std;

class Car
  {
  private:
  	int year;
    string make;
    int speed;

  public:
    Car(int, string);         // Alternative Constructor

    void print();             //Display the car information
    
    void setSpeed(int);      //Set the car's current speed

    int getYear();             //Return the car's year
    string getMake();          //Return the car's make
    int getSpeed();            //Return the car's speed

    void accelerate();         //Increase the car's speed by 5 mph
    void accelerate(int);      //Increase the car's speed by a passed in mph

    void brake();              //Reduce the car's speed by 5 mph
    void brake(int);           //Reduce the car's speed by a passed in mph
  };


int main()
  {
  int test_num;
    int num_mph, num_times;
  
  cout << "Test number? ";
  cin >> test_num;

  //create an object and test different methods based on test number
  if(test_num == 1)
    {
    Car car1(2020, "Encore");
    
    cout << endl << "Test 1: accelerate 5 times" << endl << endl;

    //display the initial values
    car1.print();
    
    //accelerate 5 times
    for( int cnt = 1; cnt <= 5; cnt++ )
      {
      car1.accelerate();
	  }
    
    //display the updated value
    car1.print();
    cout << endl;
    }
  else if(test_num == 2)
    {
    Car car2(2001, "Celica");
    
    cout << endl << "Test 2: set the speed and brake 5 times" << endl << endl;
    
    car2.setSpeed(70);
    car2.print();
    
    //brake 5 times
    for( int cnt = 1; cnt <= 5; cnt++ )
      {
      car2.brake();
	  }
    
    //display the updated value
    car2.print();
    cout << endl;
    }
  else if(test_num == 3)
    {
    Car car3(2023, "Prius");

    //get the number of times to speed up and how much to speed up each time    
    cout << "Number of times to accelerate? ";
    cin >> num_times;
    
    cout << "Number of mph to accelerate? ";
    cin >> num_mph;
    
    cout << endl << "Test 3: accelerate " << num_mph << " mph, " << num_times << " times" << endl << endl;

    car3.print();

    //accelerate a set number of times
    for( int cnt = 1; cnt <= num_times; cnt++ )
      {
      car3.accelerate(num_mph);
	  }
    
    //display the updated value
    car3.print();
    cout << endl;

    cout << endl << "Test 3: repeat the acceleration a second time" << endl << endl;

    //accelerate a set number of times
    for( int cnt = 1; cnt <= num_times; cnt++ )
      {
      car3.accelerate(num_mph);
	  }
    
    //display the updated value a second time
    car3.print();
    cout << endl;
    }
  else if(test_num == 4)
    {
    Car car4(2022, "Mustang");
    
    car4.setSpeed(42);
    
    //get the number of times to slow down and how much to slow down each time    
    cout << "Number of times to brake? ";
    cin >> num_times;
    
    cout << "Number of mph to brake? ";
    cin >> num_mph;
    
    cout << endl << "Test 4: brake " << num_mph << " mph, " << num_times << " times" << endl << endl;

    car4.print();

    //brake a set number of times
    for( int cnt = 1; cnt <= num_times; cnt++ )
      {
      car4.brake(num_mph);
	  }
    
    //display the updated value
    car4.print();
    cout << endl;
    }
  else
    {
    Car car5(1968, "Cougar");

    cout << endl << "Test 5: brake before setting a traveling speed" << endl << endl;

    //display the initial car value, try to brake, and display the updated value
    car5.print();
    
    car5.brake();
    
    car5.print();

    //set a traveling speed
    car5.setSpeed(31);
    
    cout << endl << "Test 5: negative mph acceleration" << endl << endl;

    //display the initial car value, try to accelerate, and display the updated value
    car5.print();
    
    car5.accelerate(-10);
    
    car5.print();

    cout << endl << "Test 5: accelerate" << endl << endl;

    //display the initial car value, accelerate, and display the updated value
    car5.print();
    
    car5.accelerate();
    
    car5.print();

    cout << endl << "Test 5: brake twice" << endl << endl;

    //display the initial car value, brake twice, and display the updated value
    car5.print();
    
    car5.brake();
    car5.brake();
    
    car5.print();

    //get how much to speed up each time    
    cout << endl << "Number of mph to accelerate? ";
    cin >> num_mph;
    
    cout << endl << "Test 5: accelerate " << num_mph << " mph, two times" << endl << endl;

    //display the initial car value, accelerate, and display the updated value
    car5.print();
    
    car5.accelerate(num_mph);
    car5.accelerate(num_mph);
    
    car5.print();

    //get how much to slow down each time    
    cout << endl << "Number of mph to brake? ";
    cin >> num_mph;
    
    cout << endl << "Test 5: brake " << num_mph << " mph, two times" << endl << endl;
    
    //display the initial car value, brake, and display the updated value
    car5.print();
    
    car5.brake(num_mph);
    car5.brake(num_mph);
    
    car5.print();
    cout << endl;
    }

  return 0;
  }


/* Constructor
 *
 * Argument: an integer that holds the year the car was manufactured
 *           a string that holds the make of the car
 *
 * Note: The initial speed is 0 mph
 ********************************************************************/
Car::Car(int year_made, string car_make)
  {
  year = year_made;
  make = car_make;
  speed = 0;
  }


/* Car Method:         print
 *
 * Argument: NONE
 *
 * Notes: The data members are displayed in a formatted manner
 ********************************************************************/
void Car::print()
  {
  cout << year << " " << make << "     Traveling: " << speed << " mph" << endl;
  }


/* Car Method:         setSpeed
 *
 * Argument: integer - the current speed for the car
 *
 * Notes: no error checking
 ********************************************************************/
void Car::setSpeed(int current_speed)
  {
  speed = current_speed;
  }


/* Car Method:         getYear
 *
 * Argument: NONE
 *
 * Returns: The year data member
 ********************************************************************/
int Car::getYear()
  {
  return year;
  }


/* Car Method:         getMake
 *
 * Argument: NONE
 *
 * Returns: The make data member
 ********************************************************************/
string Car::getMake()
  {
  return make;
  }


/* Car Method:         getSpeed
 *
 * Argument: NONE
 *
 * Returns: The speed data member
 ********************************************************************/
int Car::getSpeed()
  {
  return speed;
  }



//Code the 4 required methods below this line
void Car::accelerate() {
    speed += 5;
}
void Car::accelerate( int add_mph ) {
    if ( add_mph > 0 ) { 
        speed += add_mph;
    }
}
void Car::brake() {
  if ( speed - 5 < 0 ) {
    return;
  }
    speed -= 5;
}
void Car::brake( int brake_mph ) {
  if ( speed - brake_mph < 0 ) {
    return;
  }
  speed -= brake_mph;
}


