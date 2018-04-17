#include <iostream>

int main() {
    // references are not an object
    // references cannot be blank (must be initalized)
    // references cannot be reassigned
    int int1 = 10, &ref1 = int1, &ref2 = ref1;
    std::cout << "int1: " << int1 << "\nref1: " << ref1 << "\nref2: " << ref2 << '\n';
    int int2 = 300;
    ref1 = int2;
    // &ref1 = int2; // error when attempting to 'reassign' reference
    ref2 = int1;
    // int1 = 20;
    std::cout << "int2: " << int2 << "\nref1: " << ref1 << "\nref2: " << ref2 << '\n';
    return 0;
}