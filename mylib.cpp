#include <string>
#include "mylib.h"

using kkd::Money;

std::string Money::DoStuff()
{
    std::string StrArr[4] = 
    {
        "Yawn. Boring Option 1...",
        "Exciting Option 2!",
        "Yawn. Boring Option 3...",
        "Confusing Option 4...?"
    };
    return StrArr[(MyMoney < 0 ? -MyMoney : MyMoney ) % 4];
}