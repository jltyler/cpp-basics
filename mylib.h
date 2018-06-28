#ifndef MYLIB_H
#define MYLIB_H

#pragma once

namespace kkd
{
    int MegaMoney = 1000;
    const double HyperMoney = 69753.32;

    std::string MoneyMoney = "Hmm...";

    
    class Money
    {
    private:
        int MyMoney = 0;
    public:
        Money(const int _MyMoney = 100) : MyMoney(_MyMoney) {}
        int Get() const { return MyMoney; }
        void Set(const int _MyMoney) { MyMoney = _MyMoney; }
        std::string DoStuff();
    };
       
}

#endif //MYLIB_H