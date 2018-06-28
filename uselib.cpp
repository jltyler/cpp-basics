#include <iostream>
#include "mylib.h"

using std::cout; using std::endl;
kkd::Money supermonies;

int main(int argc, char const *argv[])
{
    cout << "supermonies.Get(): " << supermonies.Get() << endl;
    cout << "kkd::MegaMoney: " << kkd::MegaMoney << endl;
    return 0;
}
