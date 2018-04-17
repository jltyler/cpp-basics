#include <iostream>
#include <vector>

using std::cout; using std::cin; using std::endl; 
using std::string; using std::vector;

void printVector(const vector<int> &vec)
{
    cout << "Vector [" << &vec << "]\nLength: " << vec.size() << endl;
    if (vec.size() > 0) cout << "[ ";
    for (size_t i = 0; i < vec.size(); i++)
    {
        if (i == vec.size() - 1)
        {
            cout << vec[i] << " ]\n";
            return;
        }
        else
        {
            cout << vec[i] << ", ";
        }
    }
}

void printVector(const vector<string> &vec)
{
    cout << "Vector [" << &vec << "]\nLength: " << vec.size() << endl;
    if (vec.size() > 0) cout << "[ ";
    for (size_t i = 0; i < vec.size(); i++)
    {
        if (i == vec.size() - 1)
        {
            cout << vec[i] << " ]\n";
            return;
        }
        else
        {
            cout << vec[i] << ", ";
        }
    }
}

vector<int> readIntoVector(vector<int> &outputVector)
{
    int inputInt;
    while (cin >> inputInt)
    {
        outputVector.push_back(inputInt);
    }
    return outputVector;
}

vector<string> readIntoVector(vector<string> &outputVector)
{
    string inputString;
    while (cin >> inputString)
    {
        outputVector.push_back(inputString);
    }
    return outputVector;
}

int main()
{
    // Initalizing vectors
    vector<int> ivec; // Empty vector
    vector<string> svec(6, "money"); // Vector with 6 "money" elements
    vector<string> svec1(svec); // Copy vector contents into new vector
    vector<string> svec2{"list", "initialization", "is awesome"}; // List initialization
    vector<int> sequence{0,1,2,3,4,5,6,7,8,9};

    // Tricksy codeses
    vector<int> ivec1(5, 10); // Vector with five ints with value 10
    vector<int> ivec2{5, 10}; // Vector with two ints with values 5 and 10
    printVector(ivec1);
    printVector(ivec2);
    // List initialization with curlies will only work if the values are the correct type
    // With svec4 5 is an int so list initialization fails and it falls back to the
    // constructor that can handle an int and a string as arguments
    vector<string> svec3(5, "omgosh"); // Vector with 5 strings with value "omgosh"
    vector<string> svec4{5, "omgosh"}; // Vector with 5 strings with value "omgosh"
    printVector(svec3);
    printVector(svec4);

    // Adding stuff to vectors
    printVector(ivec);
    ivec.push_back(10);
    printVector(ivec);

    // Exercise Section 3.3.2
    // vector<int> ivec3;
    // cout << "Enter numbers:" << endl;
    // printVector(readIntoVector(ivec3));
    // vector<string> svec5;
    // cout << "Enter strings:" << endl;
    // printVector(readIntoVector(svec5));

    // Iteration
    for(auto &value : sequence)
    {
        value *= value;
        cout << value << endl;
    }

    // Exercise Section 3.3.3
    // vector<string> words;
    // string tempString;
    // cout << "Enter words" << endl;
    // while (cin >> tempString)
    // {
    //     words.push_back(tempString);
    // }
    // for(auto s : words)
    // {
    //     for(auto &c : s)
    //     {
    //         c = toupper(c);
    //     }
    // }
    // for (size_t i = 0; i < words.size(); i++)
    // {
    //     if (i % 8 == 0)
    //     {
    //         cout << '\n';
    //     }
    //     cout << words[i] << " ";
    // }

    vector<int> integers;
    int tempInt;
    cout << "Enter numbers" << endl;
    while (cin >> tempInt) integers.push_back(tempInt);
    cout << "Pairs" << endl;
    for (size_t i = 1; i < integers.size(); i+=2)
    {
        int &v1 = integers[i-1], &v2 = integers[i];
        cout << v1 << " + " << v2 << " = " << v1 + v2 << endl;
    }
    cout << "Ends" << endl;
    unsigned j = 0;
    for (size_t i = integers.size() - 1; i > integers.size() / 2 - 1; i--)
    {
        if (i == j) break;
        int &v1 = integers[j], &v2 = integers[i];
        cout << v1 << " + " << v2 << " = " << v1 + v2 << endl;
        j++;
    }
    return 0;
}