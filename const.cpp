#include <iostream>
int main()
{
    const int i = 100;
    // i = 90; // error: cannot assign to variable 'i' with const-qualified type 'const int'

    // const references
    std::cout << "const int i: " << i << '\n';
    const int &ref1 = i;
    std::cout << "ref1: " << ref1 << '\n';
    const int &ref2 = 45; // const reference to magic number
    std::cout << "ref2: " << ref2 << '\n';
    // int &ref3 = i; // error: cannot refer to const with nonconst

    // You cannot refer to const with nonconst
    // You CAN do the reverse however
    int i2 = 555;
    int &ri = i2;
    const int &cri = i2; // const int reference to nonconst int
    std::cout << "i2: " << i2 << " cri: " << cri << '\n';
    i2 = 333;
    std::cout << "i2: " << i2 << " cri: " << cri << '\n';
    ri = 200; // ok
    std::cout << "i2: " << i2 << " cri: " << cri << '\n';
    // The reference is treated like a const int even though i2 is a nonconst
    // cri = 400; // error: cannot assign to const

    // You can const refer to a different type but it copies it
    double dval = 3.14159265;
    const int &pi = dval; // copies it and references a different var
    const double &dref = dval; // actual reference since it is same type
    std::cout << "pi: " << pi << " dref: " << dref << '\n';
    // dref is an actual reference and will reflect this update
    // pi will still be 3
    dval = 55.32394827843;
    std::cout << "pi: " << pi << " dref: " << dref << '\n';

    // to make const pointer put const on left of *
    int skree = 1337;
    int * const cp = &skree; // const pointer to int: 'top-level const'
    const int * pc = &skree; // pointer to const int: 'low-level const'
    // top-level const refers to the 'top-level' name, cp, being const
    // cp = nullptr; // error: cannot assign to const pointer
    *cp = 12345; // ok
    const int * const ccp = &skree; // const pointer to const int
    // *ccp = 1337; // error: cannot assign to const int
    std::cout << "skree: " << skree  << '\n';
    return 0;
}