#include <iostream>
int var1, var2, var3, sum3;
int main() {
    std::cout << "Input a number." << std::endl;
    std::cin >> var1;
    std::cout << "Input another number." << std::endl;
    std::cin >> var2;

    std::cout << "Input a set of numbers." << std::endl;
    while (std::cin >> var3) {
        sum3 += var3;
    }
    std::cout << "Sum of sequence: " << sum3 << std::endl;


    std::cout << "Sum: " << (var1 + var2) << std::endl;
    std::cout << "Difference: " << (var1 - var2) << std::endl;
    std::cout << "Product: " << (var1 * var2) << std::endl;
    std::cout << "Quotient: " << ((float)var1 / var2) << std::endl;
    return 0;
}