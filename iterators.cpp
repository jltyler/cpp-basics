#include <iostream>
#include <vector>
#include <string>

using std::cout; using std::cin; using std::endl; 
using std::string; using std::vector;

void printVector(const vector<string> &vec)
{
    cout << "Vector [" << &vec << "]\nLength: " << vec.size() << endl;
    if (vec.empty()) return;
    cout << "[ ";
    for (auto element = vec.begin(); element != vec.end(); ++element)
    {
        cout << *element << (element + 1 == vec.end() ? " ]\n" : ", ");
    }
}

void printVector(const vector<int> &vec)
{
    cout << "Vector [" << &vec << "]\nLength: " << vec.size() << endl;
    if (vec.empty()) return;
    cout << "[ ";
    for (auto element = vec.begin(); element != vec.end(); ++element)
    {
        cout << *element << (element + 1 == vec.end() ? " ]\n" : ", ");
    }
}

struct Vector2
{
    unsigned x = 0.0;
    unsigned y = 0.0;
};

Vector2 genCoords(unsigned x = 0.0, unsigned y = 0.0)
{
    Vector2 coords;
    coords.x = x;
    coords.y = y;
    return coords;
}

auto binarySearch(vector<string> &container, string sought)
{
    cout << "Searching for \"" << sought << "\"" << endl;
    // Assumes container is already sorted
    auto beg = container.begin();
    auto end = container.end();
    // Taking difference between end and beginning gives us total size
    // Dividing that size by two and adding it to the begin iterator
    // gives us a midpoint iterator
    auto mid = container.begin() + (end - beg) / 2; // Mid point
    while (mid != end && *mid != sought)
    {
        if (sought < *mid) // If element would come before middle
            end = mid; // Set endpoint to where middle is now
        else // If element would come after middle
            beg = mid + 1; // Set beginning to one place past where middle is now
        mid = beg + (end - beg) / 2; // Recalculate middle from new info
    }
    if (mid != end) return mid; // Middle will be equal to end if the sought element is not in the container
    else return container.end();
}

int main()
{
    srand(time(0)); // Random seed from current time
    // Basics
    string kash = "Kash money millionayre";
    auto iter = kash.begin(); // Iterator to first element of container
    auto iterEnd = kash.end(); // Iterator to element AFTER the last element in container
    cout << *iter << ' '; // Dereference iterator to get element
    iter++; // Increment iterator changes it's reference to next element
    while (iter != iterEnd) // Obviously an iterator is useful for iteration
    {
        *iter = 'X'; // We can modify the element through the iterator
        cout << *iter << ' ';
        ++iter;
    }
    cout << endl;

    vector<Vector2> coords(10, genCoords(rand() % 10000, rand() % 10000));
    // Using cbegin and cend we can get const iterators
    // Doing this we can ensure that nothing tries to modify the element
    // The compiler will catch this behavior
    for (auto i = coords.cbegin(); i != coords.cend(); ++i) // For loops work well with iterators
    {
        // Member operator has priority over dereference, so...
        cout << "X: " << (*i).x; // Dereference BEFORE using member operator by using parenthesis
        cout << ", Y: " << i->y << endl; // Or you can just use arrow operator to access members
        // i->x = 30; // Error because of const iterator
    }

    // Binary search prep
    vector<string> testVector{"Hey", "uhh", "yea", "we're", "lookin", "for", "Duncan?",
        "Uuh", "Mr.", "Duncan", "we", "were", "wondering", "if", "we", "could", "talk", "to", "you", "abou-",
        "I", "ain't", "no", "Duncan!",
        "That's", "this", "reallycoolguy", "right", "here", "bout", "to", "go", "level", "3", "n", "shit"};
    printVector(testVector);
    std::sort(testVector.begin(), testVector.end());
    printVector(testVector);

    auto position = binarySearch(testVector, "wondering");
    if (!(position == testVector.end()))
        cout << "Found at: " << position - testVector.begin() << endl;
    else
        cout << "Not found!" << endl;

    // Exercise 3.4.2
    vector<int> integers{22345,4,2354,2345,3,5,345,432,56,756,867,6,46,879,345,234,5234,5,2,5,90};
    printVector(integers);
    cout << "Pairs" << endl;
    for (auto i = integers.begin(); i + 1 < integers.end(); i += 2)
    {
        int v1 = *i, v2 = *(i + 1);
        cout << v1 << " + " << v2 << " = " << v1 + v2 << endl;
    }
    cout << "Ends" << endl;
    for (auto i = integers.begin(), j = integers.end() - 1; i < j; ++i, --j)
    {
        int v1 = *i, v2 = *j;
        cout << v1 << " + " << v2 << " = " << v1 + v2 << endl;
    }
    return 0;
}
