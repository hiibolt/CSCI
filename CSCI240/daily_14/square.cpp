//DrawSquare daily
#include <iostream>
#include <iomanip>

using namespace std;

//prototype for the draw_square function
void draw_square(int, char, bool);

int main()
  {
  int square_size;
  char square_color, fill_choice;
  bool fill_square;

  //get the size of the square to be drawn
  cout << "What is the size of the square? ";
  cin >> square_size;

  //get the "color" to draw the square
  cout << "What character should be used to draw the square? ";
  cin >> square_color;
  
  //should the square be filled in or empty?
  cout << "Should the square be filled (F) or empty (E)? ";
  cin >> fill_choice;
  
  //set the boolean variable 
  fill_square = ((fill_choice == 'F') ? true : false);

  cout << endl << "Original Square:" << endl;
  //Draw the square with user input values
  draw_square(square_size, square_color, fill_square);

  cout << endl << "Square with the Opposite Fill Choice:" << endl;
  //draw the square with the opposite fill choice
  draw_square(square_size, square_color, !fill_square);
  

  return 0;
  }



//Code your function below this line
void draw_square( int length, char color, bool fill ) {
    if ( length <= 0 ) {
        cout << endl << "Error: invalid size input. The square cannot be drawn." << endl;
        return;
    }

    cout << endl;

    for ( int i = 0; i < length; i ++ ) {
        for ( int g = 0; g < length; g ++ ) {
            if ( !fill && !(( i == 0 || i == length - 1 ) || (g == 0 || g == length - 1 )) ) {
                cout << " ";
                continue;
            }
            cout << color;
        }
        cout << endl;
    }

    cout << endl;
}