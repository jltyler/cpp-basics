#include <iostream>

int main() {
    int sum = 0, i = 100;
    for (int i = 0; i < 10; i++)
        sum += i;
        std::cout << "Out of loop?" << std::endl;
    std::cout << sum << " " << i << std::endl;
    
    return 0;
}