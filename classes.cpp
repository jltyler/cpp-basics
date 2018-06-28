#include "screen.h"
#include "sales_data.h"
#include "person.h"
#include <iostream>

using std::cin; using std::cout; using std::endl;
using std::string; using std::vector;

// ==================== BREEEE! BREEEE! BREEEE! ====================
// MANY COMMENTS WITH INFO IN sales_data.h AND screen.h SO CHECK THAT OUT
// =================================================================

bool process_transactions()
{
    SalesData total(cin);
    // if (read(cin, total))
    if (cin)
    {
        SalesData trans;
        while (read(cin, trans))
        {
            if (total.isbn() == trans.isbn())
            {
                // total.combine(trans);
                total = add(total, trans);
            }
            else
            {
                print(cout, total);
                total = trans;
            }
        }
        print(cout, total);
    }
    else
    {
        cout << "Invalid or missing data!" << endl;
        return false;
    }
    return true;
}

bool process_people()
{
    Person current(cin);
    // while(read(cin, current))
    while(cin)
    {
        print(cout, current);
        cout << endl;
        read(cin, current);
    }
    return true;
}

void screen_test()
{
    Screen scr(80, 24, '.');
    scr.move(0, 0).set('X').move(1, 1).set('x');
    scr.print(cout).set(3, 3, '%');
    scr.print(cout);
    return;
}

Debug grumble(true);
constexpr Debug grumbul(true, false, true);
// grumble.set_io(false);
// grumbul.set_io(false);

int main(int argc, char const *argv[])
{
    // process_transactions();
    // process_people();
    // screen_test();
    // grumble.set_hw(!grumbul.any());
    if(grumbul.any())
        cout << "ANY" << endl;
    return 0;
}
