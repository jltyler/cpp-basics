#include <iostream>
#include <string>
#include "sales_data.h"

int main()
{
    SalesData data1, data2;
    double price;
    std::cout << "Enter data del uno!\n";
    std::cin >> data1.isbn >> data1.numSold >> price;
    data1.totalPrice = price * data1.numSold;
    std::cout << "Enter data del dos!\n";
    std::cin >> data2.isbn >> data2.numSold >> price;
    data2.totalPrice = price * data2.numSold;

    if (data1.isbn == data2.isbn)
    {
        unsigned int totalCount = data1.numSold + data2.numSold;
        double totalRevenue = data1.totalPrice + data2.totalPrice;
        std::cout << "ISBN: " << data1.isbn << '\n';
        std::cout << "Sold: " << totalCount << ", Revenue: " << totalRevenue << '\n';
        if (totalCount > 0)
        {
            std::cout << "Average sale: " << totalRevenue / totalCount << '\n';
        }
        else
        {
            std::cout << "No sales yet!\n";
        }
    }
    else
    {
        std::cout << "Mismatched ISBN! Aborting...\n";
        return -1;
    }
    return 0;
}