#ifndef PERSON_H
#define PERSON_H

#include <iostream>

struct Person
{
    public:
    Person() = default;
    Person(std::string & n, std::string & a):
        _name(n), _address(a) {}
    Person(std::istream & is)
    {
        read(is, *this);
    }
    std::string name() const { return _name; }
    std::string address() const { return _address; }
    private:
    std::string _name;
    std::string _address;
    friend std::istream & read(std::istream &, Person &);
};

std::istream & read(std::istream & is, Person & p)
{
    getline(is, p._name, ',');
    getline(is, p._address);
    // is >> p._name >> p._address;
    return is;
}

std::ostream & print(std::ostream & os, const Person & p)
{
    os << "Name: " << p.name() <<
        "\nAddress: " << p.address();
    return os;
}

#endif //PERSON_H
