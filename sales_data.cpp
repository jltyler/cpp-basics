#include <iostream>
#include "sales_data.h"

std::istream & read(std::istream & is, SalesData & sdata)
{
    double ppu = 0;
    is >> sdata.bookNo >> sdata.numSold >> ppu;
    sdata.revenue = sdata.numSold * ppu;
    return is;
}

std::ostream & print(std::ostream & os, const SalesData & sdata)
{
    os << "ISBN: " << sdata.isbn() <<
        "\nSold: " << sdata.numSold <<
        "\nRevenue: $" << sdata.revenue <<
        "\nAverage Sale: $" << sdata.avg_price() << std::endl;
    return os;
}

SalesData add(const SalesData & lhs, const SalesData & rhs)
{
    SalesData sum = lhs;
    sum.combine(rhs);
    return sum;

}