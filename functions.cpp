#include <iostream>
#include <vector>
#include <string>
#include <cassert>

// A good practice is too declare functions in the headers
// and then define the actual function body in the source file
#include "functions.h"

using std::cout; using std::cin; using std::endl; 
using std::string; using std::vector;

// return_type function_name(argument_list)
// { function body }

int factorial(int val)
{
    int ret = 1;
    while (val > 1)
        ret *= val--;
    return ret;
}

// No arguments can just be empty parenthesis
// Or you can explicitly define a lack of arguments with void
// Not really necessary unless you want compatibility with C
void hello(void)
{
    cout << "Hello World.\n";
}

// MUST have function body even when it's a single statement
// double square(double d) return d * d; // error!
double square(double d) {return d * d;} // ok

// Each argument must be supplied with a type
// int addition(int v1, v2) // error!
int addition(int v1, int v2) // ok
{
    return v1 + v2;
}

// static keyword can be used to make a variable persist between calls
// id will be 0 on the first time the function is run and will
// increase with each subsequent call
int get_id()
{
    static int id = 0;
    return id++;
}

// functions can be declared without defining the body
// See functions.h for more declarations and info
int gimme_kash(int kash);

// functions can have reference parameters
void add_three(int &val)
{
    val += 3;
}

// functions can also use pointers as parameters
// Note that this function is overloaded (one name referring to two functions)
// The compiler will figure out which function is meant by checking the
// parameter count and the types of parameters
void add_three(int *val)
{
    *val += 3;
}

// Exercise 6.2.1
void swap(int *v1, int *v2)
{
    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}

// Const reference parameters
// References should always be const unless you plan on modifying
// the value of the reference
// The intentions of the function will be a little more clear to the reader
// not to mention normal references can be converted to const refs but
// not vice versa. (example in main)

void print_string(const string &s) // const parameter
{
    cout << s << endl;
}

void print_string_nc(string &s) // non const parameter
{
    cout << s << endl;
}

// Exercise 6.2.3
bool has_capital(const string &s)
{
    for(const char &c : s)
    {
        if (isupper(c))
            return true;
    }
    return false;
}

void lowercase(string &s)
{
    for(char &c : s)
    {
        c = tolower(c);
    }
}

// bool compare(const matrix &m1, const matrix &m2);
vector<int>::iterator change_val(int val, vector<int>::iterator iter);

// Array parameters
// arrays cannot be copied and thus cannot be passed by value
// void print_arr(const int *arr);
// void print_arr(const int arr[]); // These two are equivalent
// It is still the job of the programmer to make sure they stay within the
// bounds of the array since you cannot inherently deduce the size of the array
void print_arr(const int arr[])
{
    cout << "Printing array\n";
    // Not sure if this pointer hack will work inside so lets try it out
    int size = *(&arr + 1) - arr; // It does not...
    cout << "size (inside func): " << size << endl; // WRONG VALUE!
}
// There is no agreed upon way of remaning in bounds but here are some options

// With chars you could use a null character to signal the end of the array
// Note that this only really works with char arrays unless you designate
// a specific value to act as a terminator in other types
void print_arr_char(const char arr[])
{
    if (arr) // If arr is a valid pointer
        while (*arr) // While dereffed arr is not a null character
            cout << *arr++ << endl; // deref print and increment
}

// Use the standard library technique of providing the beginning of a
// sequence as well as the end of it
// Personally, I think this is the best method
void print_arr_std(const int *curr, const int *last)
{
    while (curr != last)
        cout << *curr++ << endl;
}

// Send the size in as a seperate parameter
void print_arr_size(const int *arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}

// Array references as parameters
// Note the parentheses around &arr and also the size is required for the
// ranged loop
void print_arr_ref(const int (&arr)[10])
{
    for(auto val : arr)
    {
        cout << val << endl;
    }
}

// Initializer list functions
// Used if we want to accept an arbitrary number of arguments
void print_list(std::initializer_list<string> lst)
{
    // initializer_list includes begin and end functions for iteration
    for (auto iter = lst.begin(); iter != lst.end(); ++iter)
    {
        cout << *iter << endl;
    }
}

int sum_total(std::initializer_list<int> lst)
{
    int sum = 0;
    for(auto &val : lst)
    {
        sum += val;
    }
    return sum;
}

// Returning an initialized list
vector<int> get_numbers()
{
    if (rand() % 100 >= 50)
    {
        // converts to vector when returning
        return {0,1,2,3,4,5,6,7,8,9};
    }
    else
    {
        return {99,98,97,96,95};
    }
}

// Recursion (function calling itself)
// MAKE SURE THERE IS A PATH OUT OF THE RECURSION
int factorial_r(int val)
{
    if (val > 1)
        return factorial_r(val - 1) * val;
    return 1;
}

// Exercise 6.3.3
string money[10] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
// "Normal" return definition
string (&get_strings(const string &str))[10]
{
    return money;
}
// Using a typedef
typedef string strTen[10];
strTen &get_strings_td(const string &str)
{
    return money;
}
// Using trailing return
auto get_strings_tr(const string &str) -> string (&)[10]
{
    return money;
}
// Using decltype
decltype(money) &get_strings_d(const string &str)
{
    return money;
}

// Overloading functions
// Most compilers are smart enough to tell functions apart by what parameters
// they take. You can define multiple functions with the same name as long
// as the parameters differ

// The parameter TYPE is what matters
// sub(int &) is equivalent to sub(int &value)

// You cannot overload based on return type
// int sub(int);
// float sub(int); <- CAnnot overload based only on return
// What if you just called without storing the result?
// sub(5); // The compiler would have no idea which function to use here

int subtraction(const int &val1, const int &val2)
{
    return val1 - val2;
}

float subtraction(const float &val1, const float &val2)
{
    return val1 - val2;
}

// Overloading and scope
// Declaring a name in a local scope will HIDE that name in the outer scope
// Name lookup occurs BEFORE checking for overloads
void some_function()
{
    int subtraction = 10;
    // This will produce an error since subtraction now refers to the int
    // above and not the function
    // int money = subtraction(3, 4);
}

// Default arguments
// You can define a value to be used as the default for a parameter
// You can omit that argument in order to use the default value
// You can only have 'trailing' default args (on the right)
string dat_string(int val, string str = "money", float val2 = 3.345f)
{
    string ret = std::to_string(val);
    return ret + str;
}

// You can use variables as default arguments but not local vars
string kashmoney = "#"; // Defined outside function
// the kashmoney value is evaluated at call time
string dat_string(const string, string str = kashmoney)
{
    // Changes will persist when function is called next time with default arg
    kashmoney += "#";
    return kashmoney;
}

// Inline functions
// Function calls carry runtime overhead that can be prohibitive
// Inline functions will attempt to replace the function call with the
// expression instead of calling the function and then returning
// Note that inlines are a REQUEST to the compiler that can be ignored if
// the compiler chooses to do so
// Inlines are meant for small functions that are called many times

// The following function is so small that the overhead for calling it
// would be significant in comparison to the work it does
// Using inline removes the overhead by simply replacing the call with the
// contents of the function
inline int addition_inline(const int &val1, const int &val2)
{
    return val1 + val2;
}

// Constant expression functions
// use constexpr to define one but these come with some restrictions
// All parameter types and the return type MUST be literal types
// constexpr functions are implicitly inline functions
// Define constexpr and inlines in headers for consistency
constexpr int get_size(int mul)
{
    // will return constexpr as long as mul is a constexpr
    return 64 * mul;
}
int int_arr[get_size(2)]; // Okay because 2 is constexpr
// int i = 2;
// int int_arr2[get_size(i)]; // No good! i is not a constexpr

// Assertions
// assert is a preprocessor macro defined in cassert header
// assert(true); // You cannot use assert on the global scope
// Look at assertion section in main

// Function matching
// With overloaded functions the compiler will attempt to determine
// the most viable function to use based on
// The number of arguments
// The types of arguments
// Note these functions do nothing, they are just used to demonstrate
// how function matching works
void myfunc() {cout << "myfunc()\n";}
void myfunc(int i1) {cout << "myfunc(int)\n";}
void myfunc(int i1, int i2) {cout << "myfunc(int, int)\n";}
void myfunc(double d1, double d2 = 2.33) {cout << "myfunc(double, double)\n";}

// Function pointers
// Functions can be pointed to by a variable but it is somewhat restrictive
bool is_greater(const int &i1, const int &i2)
{
    return i1 > i2;
}
bool is_less(const int &a, const int &b)
{
    return a < b;
}
// See section in main for actual pointers

// You can use function pointers as parameters if you're absolutely bonkers
bool compare(int i1, int i2, bool pf(const int &, const int &))
{
    return pf(i1, i2);
}

// And you can return function pointers
// In this case you must explicitly define it as a pointer to a function
decltype(is_less) *getf()
{
    return is_less;
}

bool (*getf2())(const int &, const int &)
{
    return is_greater;
}

// Command line arguments are passed into main
// Note that the first argument is the command used to execute the program
// argc is number of arguments (whitespace seperated)
// argv is the array that holds the strings
int main(int argc, char *argv[])
{
    srand(time(0));
    {
        cout << "factorial(5): " << factorial(5) << endl;
        cout << "square(5): " << square(5) << endl;
        cout << "get_id(): " << get_id() << endl;
        cout << "get_id(): " << get_id() << endl;
        cout << "get_id(): " << get_id() << endl;
        int i = 3;
        cout << "i: " << i << endl;
        add_three(i); // Passed by reference so i is affected
        cout << "i: " << i << endl;
        add_three(&i); // Passed a pointer by using 'address-of' operator
        cout << "i: " << i << endl;
    }
    // Exercise 6.2.1
    {
        int ten = 10, eleven = 11;
        swap(&ten, &eleven);
        cout << "ten: " << ten << endl;
        cout << "eleven: " << eleven << endl;
    }
    // Const reference parameter
    {
        string s = "Non-const string";
        print_string(s); // ok: nonconst can be converted to const
        print_string_nc(s); // ok: no conversion
        print_string("Literal"); // ok: literal can be converted to const
        // print_string_nc("Literal"); // error: literal cannot convert to nonconst
    }
    // Exercise 6.2.3
    {
        string s = "UPPERCASE TEXT";
        cout << (has_capital("Kashmoney") ? "true" : "false") << endl;
        lowercase(s);
        cout << s << endl;

    }
    // Array parameters
    {
        int int_arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
        int size = *(&int_arr + 1) - int_arr;
        cout << "size: " << size << endl;
        print_arr(int_arr);

        char arr_char[] = {'s', 'o', 'm', 'e', ' ', 't', 'e', 'x', 't', '\0'};
        cout << "Print array with termination value\n";
        print_arr_char(arr_char);
        cout << "Print array with begin and end pointers\n";
        print_arr_std(std::begin(int_arr), std::end(int_arr));
        cout << "Print array with explicit size parameter\n";
        print_arr_size(int_arr, size);

        cout << "Print array reference parameter\n";
        print_arr_ref(int_arr);
        
    }
    // Command line arguments
    {
        // argc is the argument count
        // argv is the array
        for (size_t i = 0; i < argc; i++)
        {
            cout << "argv[" << i << "]: " << argv[i] << endl;
        }
    }
    // Initializer lists
    {
        // Use curlies to define an initializer_list
        print_list({"Kash", "Monies", "N", "D", "Bank"});
        // As many arguments as you want!
        cout << sum_total({1,2,3,4,5}) << endl;
        cout << sum_total({43,75,33,33,7}) << endl;
    }
    // Return vector from initializer list
    {
        for(auto val : get_numbers())
        {
            cout << val << ", ";
        }
        cout << endl;
    }
    // Recursion
    {
        cout << "factorial_r(5): " << factorial_r(5) << endl;
    }
    // Exercise 6.3.3
    {
        string (&ref_arr)[10] = get_strings_d("money");
        for (size_t i = 0; i < 10; i++)
        {
            cout << "ref_arr[" << i << "]: " << ref_arr[i] << endl;
        }
    }
    // Overloaded function
    {
        int five = 5;
        float ffive = 5.0;
        cout << "subtraction(int, int): ";
        cout << subtraction(five, 3) << endl;
        cout << "subtraction(float, float): ";
        cout << subtraction(ffive, 3.2222) << endl;
    }
    // Default arguments
    {
        cout << dat_string(5) << endl; // Other arguments are provided default values
        cout << dat_string(10, "not_money") << endl;
        cout << dat_string("a") << endl;
        cout << dat_string("a") << endl;
        cout << dat_string("a") << endl;
    }
    // Assertions
    // Used to check for things that "cannot" happen
    {
        int some_int = 10;
        assert(some_int > 0);
        // NDEBUG preprocessor variable controls whether or not assert does
        // anything at all. If NDEBUG is defined the asserts are ignored
        // You can also use this to implement your own debug functionaity
        // Compiler can use flag "-D NDEBUG" to define NDEBUG
        #ifndef NDEBUG
        cout << "Debug info" << endl;
        cout << "__func__: " << __func__ << endl;
        cout << "__FILE__: " << __FILE__ << endl;
        cout << "__LINE__: " << __LINE__ << endl;
        cout << "__DATE__: " << __DATE__ << endl;
        cout << "__TIME__: " << __TIME__ << endl;
        #endif // NDEBUG
    }
    // Function matching
    {
        // Will first use number of args to narrow selection
        // Since myfunc(double, double) has default argument this call can be
        // interpreted as having two arguments
        // After checking number of arguments, it then uses the types to
        // narrow the selection
        // 3.4 can be converted to an int but a conversion will push it down
        // the priority "list"
        // myfunc(double, double) is the best match
        myfunc(3.4);
        // This next call will fail because the call is ambiguous
        // myfunc(int, double);
        // myfunc(3, 3.2);
        // The compiler cannot tell if you want the int converted of the double
        // You can get around this with a cast but that reeks of bad design

        // Exercise 6.6
        // myfunc(2.56, 42); // ambiguous
        myfunc(42); // myfunc(int)
        myfunc(42, 0); // myfunc(int, int)
        myfunc(2.56, 3.14); // myfunc(double, double)

    }
    // Function pointers
    {
        // Define a blank pointer to a function that takes two const int
        // references and returns a bool
        // The parentheses around the *f are required
        bool (*f)(const int &, const int &) = nullptr;
        // An easier way of defining is by using decltype with one of
        // the functions you intend to use
        // Don't forget to include the asterisk to define a pointer
        decltype(is_less) *f2 = nullptr;

        // Attempting to call without assigning a valid function will
        // result in a segmentation fault

        // No need to use adress-of on the function to assign to pointer
        f2 = is_less;
        // Also no need to deref function pointer to call it
        cout << ( f2(2, 5) ? "true" : "false" ) << endl;
        f2 = is_greater;
        cout << ( f2(2, 5) ? "true" : "false" ) << endl;

        // function parameter
        cout << "function pointer parameters" << endl;
        cout << ( compare(5, 10, is_less) ? "true" : "false" ) << endl;
        cout << ( compare(5, 10, is_greater) ? "true" : "false" ) << endl;

        // return function pointer
        cout << "function pointer return" << endl;
        cout << ( getf()(5, 10) ? "true" : "false" ) << endl;
        cout << ( getf2()(5, 10) ? "true" : "false" ) << endl;
    }
    return 0;
}