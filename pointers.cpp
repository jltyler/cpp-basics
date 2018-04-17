#include <iostream>

int main()
{
    // points to an object
    // pointers CAN be blank aka nullptr or 0
    // always initialize to a valid address or nullptr
    // put * for EACH declare in multi-declare ie:
    // int *p1, *p2, *p3, *pointertenbillion;
    
    int i = 0xff, i2 = 1272;
    int *p = &i; // & is 'address-of' operator on right side of assignment, 'reference' on left
    std::cout << "int " << i << " pointer " << p << '\n';
    p = &i2;
    std::cout << "int2 " << i2 << " pointer " << p << '\n';
    *p = 300; //  *p dereferences p and assigns 300 to the object it is pointing to
    std::cout << "int " << i << " int2 " << i2 << " pointer " << p << '\n';
    int money = 1000;
    int *p1 = &money;
    int **p2 = &p1;
    int ***p3 = &p2;
    std::cout << "money: " << money << '\n';
    std::cout << "p2: " << p2 << '\n';
    std::cout << "deref1: " << *p2 << '\n';
    std::cout << "deref2: " << **p2 << '\n';
    int *np = nullptr;
    std::cout << "null: " << np << '\n';
    // std::cout << "null deref: " << *np << '\n'; // segmentation fault
    return 0;
}