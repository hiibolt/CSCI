#include <iostream>

using std::cout;
using std::endl;

int build_array(int[]);
void print_array(int[], int);
void selection_sort(int[], int);

int main()
{
    int array[1000];
    int n;
 
    n = build_array(array);

    cout << n << " elements unsorted\n\n";

    print_array(array, n);
    
    cout << endl << n << " elements in ascending order\n\n";
    
    selection_sort(array, n);
    
    print_array(array, n);

    return 0;
}
