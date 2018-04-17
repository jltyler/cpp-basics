#include <iostream>
#include <iomanip>

int main()
{
    typedef double coordinate; // coordinate is a synonym for double now
    coordinate x = 100.34f;
    coordinate y = 33.34f;
    std::cout << "Coords: " << x << ", " << y << '\n';

    using dbl = double; // C++ 11 style
    dbl moneys = 400.13f;
    std::cout << "moneys: " << moneys << '\n';

    // New juicy auto type establishes type based off initializer
    auto ai = 92.3945739475623049587f; // float
    auto ai2 = 92.3945739475623049587l; // double
    std::cout << std::setprecision(30); // Allow many decimal places
    std::cout << ai << '\n';
    std::cout << ai2 << '\n';

    // auto failure_var; // error! auto REQUIRES an initializer

    const int ci = 300, &cr = ci;
    auto ai = ci; // creates int, drops const
    auto &ar = cr; // creates const int reference
    const auto cai = ci; // const must be explicitly defined on auto without a reference

    return 0;
}