#include <iostream>
#include <unistd.h>

int main(){
    int test = 0;
    std::cout << "Hello, World!" << std::endl;
    while (true) {
        test ++;
        std::cout << test << std::endl;
        usleep(1000000);
    }
    return 0;
}
