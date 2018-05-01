#include <iostream>
#include <vector>
#include <string>

using std::cout; using std::cin; using std::endl; 
using std::string;
using std::vector;


// string randomString(int length = 0)
// {
//     string str = "";
//     length = length <= 0 || length > 24 ? rand() % 23 + 1 : length;
//     for (size_t i = 0; i < length; i++)
//     {
//         char c = 
//         str.append()
//     }
//     return str;
// }

int main()
{
    srand(time(0));
    // Precedence vs Associativity
    int p = 8 + 5 * 4 / 2 - 5; // Yields 13 because of operator precedence
    cout << p << endl;
    int a = 45 - 15 - 10; // Yields 20 because of left-to-right operator associativity
    cout << a << endl;
    int u = 20 + -45 * 3; // (20 + ((-45) * 3))

    // Order of evaluation is left up to the compiler
    int myInt = 10;
    // Modifying myInt and calling it in the same expression
    // This is undefined behavior and should be avoided
    // It may not produce an error but the compiler will decide when to evaluate each part
    cout << myInt << " " << ++myInt << endl;

    // Modulo
    // m % (-n) => m % n => positive number
    // (-m) % n => -(m % n) => negative
    cout << "(5 % -3): " << (5 % -3) << endl; // 2
    cout << "(-5 % 3): " << (-5 % 3) << endl; // -2
    // Exercise 4.2
    cout << "(12 / 3 * 4 + 5 * 15 + 24 % 4 / 2): " << (12 / 3 * 4 + 5 * 15 + 24 % 4 / 2) << endl; // 91
    cout << "(-30 * 3 + 21 / 5): " << (-30 * 3 + 21 / 5) << endl; // -86
    cout << "(-30 + 3 * 21 / 5): " << (-30 + 3 * 21 / 5) << endl; // -18
    cout << "(30 / 3 * 21 % 5): " << (30 / 3 * 21 % 5) << endl; // 0
    cout << "(-30 / 3 * 21 % 4): " << (-30 / 3 * 21 % 4) << endl; // -2
    int testEven = 35;
    cout << std::to_string(testEven) + ((testEven % 2 == 0) ? " is even" : " is odd") << endl;

    // Short circuit condition (no disassemble)
    int op1 = 10, op2 = 0;
    // If op2 is 0 the second expression will not be evaluated
    // Without this it would attempt to divide by 0 and CRASH OUT
    cout << ((op2 != 0) && (op1 / op2 != 0) ? "true" : "false" ) << endl;

    int x = 10, y = 9, z = 8;
    // Left-association + a gotcha
    // (x > y > z)
    // x > y is evaluated first which returns true
    // true is then converted to 1 and compared to z
    cout << (x > y > z ? "truedat" : "naw") << endl; // prints negative
    // you must compare both seperately
    cout << ((x > y) && (y > z) ? "truedat" : "naw") << endl; // prints truedat

    // Bool literal condition gotcha
    int bVal = 10, bVal2 = 1;
    // (bVal == true) will only evaluate to true if bVal is 1
    cout << (bVal == true ? "affirmative" : "negative") << endl; // nope
    cout << (bVal2 == true ? "affirmative" : "negative") << endl; // yezzir

    // Assignment is right associative
    int iVal = bVal = 255; // Assigns 255 to bVal and then bVal to iVal
    cout << "iVal: " << iVal << endl;
    cout << "bVal: " << bVal << endl;

    // Fun with precedence
    {
        vector<int> vecInts = {4,12,62,33,42,54,61,77,78,89,710,11,12,13,14,15,16};
        auto iter = vecInts.begin();
        // Print all elements until one is greater than 100
        while (iter != vecInts.end() && *iter <= 100)
            // iter++ increments the iter BUT it returns the original value
            // * deref has lower precedence so it evaluates after ++
            cout << *iter++ << endl;
    }
    // Member access
    {
        vector<string> vecStr = {"money", "kash", "stax", "dough", "skrilla", "paper"};
        // . operator has second highest precedence and is left associative
        // () function call has same precedence and is left associative
        auto size = vecStr.size(); // Get vecStr.size member and then initiate fuction call ()
        auto iter = vecStr.begin() + 2;
        // -> arrow member operator for iterators or pointers
        cout << "iter->empty(): " << iter->empty() << endl;
        // worse way of doing it:
        // (*iter).empty();
    }

    // Conditional Ternary
    // (condition ? expr when true : expr when false)
    // Low precedence so use parenthesis
    cout << (30 < 50 ? "yezzir" : "nuh uh") << endl;

    // Exercise 4.7
    {
        vector<int> vecInts = {4,12,62,33,42,54,61,77,78,89,710,11,12,13,14,15,16};
        for (auto iter = vecInts.begin(); iter != vecInts.end(); ++iter)
        {
            *iter = (*iter % 2 == 0 ? *iter : *iter * 2 );
            cout << "*iter: " << *iter << endl;
        }
    }
    {
        vector<int> grades = {100,0,45,75,83,53,72,74,92,99,64,61,60,55,82,87};
        for (auto iter = grades.begin(); iter != grades.end(); ++iter)
        {
            auto &val = *iter;
            string status = std::to_string(val) + ": ";
            status += (val == 100 ? "Perfect!" :
                (val >= 90 ? "Excellent" : 
                (val >= 80 ? "Nice" : 
                (val >= 70 ? "Average" :
                (val >= 60 ? "Well you passed..." :
                (val == 0 ? "DEHUMANIZE YOURSELF AND FACE TO BLOODSHED." : "Terrible! Take a lap!"))))));
            cout << status << endl;
        }
    }

    // Bitwise aka time for the real fun
    {
        // Bit shifting left << and right >>
        auto flags = 255ul; // unsigned long (32 bits)
        // flags in binary:          00000000000000000000000011111111 (255)
        flags = flags << 4; // left shift operator shifts all bits left
        // flags is now:             00000000000000000000111111110000 (4080)
        cout << "flags: " << flags << endl;
        flags = flags >> 10; //      00000000000000000000000000000011 (3)
        cout << "flags: " << flags << endl;
        // bits that are shifted "off the end" are discarded
        flags = flags << 10; //      00000000000000000000110000000000 (3072)
        cout << "flags: " << flags << endl;
    }
    {
        // Bitwise NOT operator ~
        // flips all bits
        unsigned char flags = 55; //    00110111
        flags = ~flags; //              11001000
        cout << int(flags) << endl;

        // Bitwise AND &, OR |, and XOR ^
        // Compares each set of bits of two vars
        // Leading 0 makes an octal literal
        // 0145 octal == 101 decimal
        unsigned char char1 = 0145; //              01100101: 101
        unsigned char char2 = 175; //               10101111: 175

        unsigned char bitAnd = char1 & char2; //    00100101: 37
        unsigned char bitOr = char1 | char2; //     11101111: 239
        unsigned char bitXor = char1 ^ char2; //    11001010: 202
    }
    // sizeof
    {
        int x[10]; int *p = x;
        cout << "sizeof(x): " << sizeof(x) << endl;
        cout << "sizeof(p): " << sizeof(p) << endl;
    }
    // Exercise 4.9
    {
        cout << "sizeof(char): " << sizeof(char) << endl;
        cout << "sizeof(int): " << sizeof(int) << endl;
        cout << "sizeof(float): " << sizeof(float) << endl;
        cout << "sizeof(double): " << sizeof(double) << endl;
        cout << "sizeof(long): " << sizeof(long) << endl;
        cout << "sizeof(long long): " << sizeof(long long) << endl;
        cout << "sizeof(long double): " << sizeof(long double) << endl;
    }
    // , comma operator
    // evaulates and discards left hand side then returns right hand value
    // will return lvalue if the right side is an lvalue
    // Lowest precedence of all operators
    {
        int i = 10, j = 10;
        int k;
        k = (++i, --j, 303); // Executes all expressions but only returns 303
        cout << "i: " << i << endl;
        cout << "j: " << j << endl;
        cout << "k: " << k << endl;
        (i++, k) = (--j, 88), ++k; // returning lvalue otherwise assignment would fail
        cout << "i: " << i << endl;
        cout << "j: " << j << endl;
        cout << "k: " << k << endl;
    }
    return 0;
}