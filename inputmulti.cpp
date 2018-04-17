#include <iostream>
// #include <string>

int main()
{
    std::cout << "Input some stuff with spaces maybe if u wan?" << std::endl;
    std::string var1, var2, var3;
    // std::cin >> var1 >> var2 >> var3; // Stops reading at whitespace character
    getline(std::cin, var1); // Gets whole line instead of stopping at whitespace
    std::cout << "var1: " << var1 << std::endl;
    std::cout << "var2: " << var2 << std::endl;
    std::cout << "var3: " << var3 << std::endl;
    return 0;
}