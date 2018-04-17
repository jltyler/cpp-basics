#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::cin; using std::endl; 
using std::string; using std::vector;

unsigned arrSize2 = 32;
// int badArray[arrSize2]; // error: variable length array declaration not allowed at file scope

int main()
{
    // Basic
    string arr[10]; // Array of ten strings
    int *parr[20]; // Array of 20 int pointers
    int arr2[3] = {1, 2, 3}; // Array of 3 ints with list initialization
    int arr3[] = {1, 2, 3}; // Array of 3 ints
    int arr4[5] = {1, 2, 3}; // Array of 5 ints {1, 2, 3, 0, 0}
    int arr5[] = {0,1,2,3,4,5,6,7,8,9};
    // int badArray2[3] = {1, 2, 3, 4}; // Too many initializers

    // Char arrays have special initializers
    char carr[] = {'W', 'o', 'r', 'd'}; // carr is {'W', 'o', 'r', 'd'}
    // Can use string initialization but be wary of the automatic null character added on
    char carr2[] = "Word"; // carr2 is {'W', 'o', 'r', 'd', '\0'}
    // char carr3[4] = "Word"; // Error! Not enough room for null character

    // Copy assignment is NOT allowed
    // int copyArr = arr2; // ERROR
    // Assignment in general is NOT ALLOWED SO JUST DON'T DO IT
    // arr3 = {3, 2, 1}; // ERROR

    // Arrays of references is NOT ALLOWED
    // int &refs[4] = {1, 3, 2, 4};
    // Reference to an array
    // Read right to left normally but in this case inside out
    // refArray which is a reference to a size 3 array of ints
    int (&refArray)[3] = arr2; // fun syntax
    // Same deal with a pointer to an array
    int (*pointerArray)[3] = &arr2; // WIthout parenthesis this would be an array of pointers
    // Reference to an array of pointers
    int *(&refPointArray)[20] = parr; // I'm becoming insaane insaane insane

    // Exercise 3.5.2
    // int intArray[10];
    // for (size_t i = 0; i < 10; i++)
    // {
    //     intArray[i] = i;
    // }
    // for(auto val : intArray)
    // {
    //     cout << val << endl;
    // }

    // POinter black magic funnery
    // An array 'object' is a pointer to the first index in the array
    int *p = arr2; // gud2go
    auto p2(arr2); // p2 is a pointer to the first int in arr2

    // Pointers to arrays can be used like iterators
    p++; // Now points to second element in arr2

    // Traversal with a pointer
    int *pEnd = &arr5[10]; // Pointer to address immediately after last element
    for (int *pi = arr5; pi != pEnd; ++pi)
        *pi *= *pi;

    // Use begin and end library functions instead of computing the end like some fool
    for (int *pi = std::begin(arr5); pi != std::end(arr5); ++pi)
        cout << *pi << ", ";
    cout << endl;

    // Pointer arithmetic
    p = arr5;
    cout << *(p + 4) << endl; // derefs index 4 in arr5
    int *p3 = &arr5[3]; // Subscript reference into pointer can be used like an array
    cout << "p3[0]: " << p3[0] << endl; // First index points to third of arr5
    cout << "p3[3]: " << p3[3] << endl;
    cout << "p3[-2]: " << p3[-2] << endl; // Horror terror

    // Exercise 3.5.3
    int zeroArray[] = {345,3,45,345,345,3,45,34,53,453,45,34,53,45,345,3,4,675,547,46,74,3,534,634,674536,5235,346};
    int *zeroP = std::begin(zeroArray);
    int *endP = std::end(zeroArray);
    while (zeroP != endP)
    {
        *zeroP = 0;
        ++zeroP;
    }
    for (int *ip = std::begin(zeroArray); ip != std::end(zeroArray); ++ip)
        cout << ip << ": " << *ip << endl;

    // Array equality test
    int eqTest[] = {0,1,2,3,4,5,6,7,8};
    int eqTest2[] = {0,1,2,3,4,5,6,7,8};
    int eqSize = *(&eqTest + 1) - eqTest;
    int eqSize2 = *(&eqTest2 + 1) - eqTest2;
    cout << "eqSize: " << eqSize << endl;
    cout << "*std::end(eqTest): " << *(std::end(eqTest) - 1) << endl;
    bool eq = (eqSize == eqSize2);
    for (int *ip = std::begin(eqTest), *ip2 = std::begin(eqTest2);
    eq && (ip != std::end(eqTest)) && (ip2 != std::end(eqTest2));
    ++ip, ++ip2)
    {
        if (*ip == *ip2) continue;
        else
        {
            eq = false;
            break;
        }
    }
    cout << (eq ? "Arrays are indeed equal" : "Arrays are not equal AT ALL") << endl;

    // vs
    // Vector equality test
    // aka never use arrays
    vector<int> eqVecTest = {0,1,2,3,4,5,6,7,8,9};
    vector<int> eqVecTest2 = {0,1,2,3,4,5,6,7,8,9};
    cout << (eqVecTest == eqVecTest2 ? "Vectors are indeed equal" : "Vectors are not equal AT ALL") << endl;

    // Multiple dimensions
    int multiArray[3][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
    };
    // Equivalent to the above initialization
    // Though it is considerably less clear
    // Also throws warnings
    int multiArray2[3][3] = {0,1,2,3,4,5,6,7,8};

    // Exercise 3.6
    int magicFunnery[4][4] = {
        {1,2,3,5},
        {2,4,6,10},
        {3,6,9,15},
        {5,10,15,25}
    };
    using quadInt = int[4]; // typedef
    std::cout << "Printing with ranged for" << '\n';
    for (quadInt &var : magicFunnery)
    {
    for (int &var2 : var)
        {
            cout << &var2 << ": " << var2 << endl;
        }
    }
    std::cout << "Printing with traditional for with subscripts" << '\n';
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t ii = 0; ii < 4; ii++)
        {
            cout << "[" << i << "][" << ii << "]: " << magicFunnery[i][ii] << endl;
        }
    }
    std::cout << "Printing with traditional for with pointers" << '\n';
    for (quadInt *ip = std::begin(magicFunnery); ip != std::end(magicFunnery); ++ip)
    {
        for (int *ip2 = std::begin(*ip); ip2 != std::end(*ip); ++ip2) {
            cout << ip2 << ": " << *ip2 << endl;
        }
    }
    return 0;
}