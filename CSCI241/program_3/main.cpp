#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int build_array(string[]);
void print_array(string[], int);
void bubble_sort(string[], int);

int main()
{
    string array[100];
    int n;
 
    n = build_array(array);

    cout << n << " elements unsorted\n\n";

    print_array(array, n);
    
    cout << endl << n << " elements in ascending order\n\n";
    
    bubble_sort(array, n);
    
    print_array(array, n);

    return 0;
}
