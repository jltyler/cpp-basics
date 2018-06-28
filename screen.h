#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <vector>

class Screen
{
    // We can declare a friend class which, in this case, allows WindowManager
    // to access private members of screen
    friend class WindowManager;
    // We can also explicitly only allow a certain member function of
    // WindowManager to be a friend
    // This would require WindowManager and its clear member to be defined
    // friend void WindowManager::clear(screen_index);
    public:
    // Local typedefs are inside the class scope
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos wd, pos ht):
        width(wd), height(ht), contents(ht * wd, ' ') {}
    Screen(pos wd, pos ht, char c):
        width(wd), height(ht), contents(ht * wd, c) {}
    char get() const { return contents[cursor]; }
    char get(pos, pos) const;
    Screen & set(char);
    Screen & set(pos, pos, char);
    Screen & move(pos, pos);
    // We overload print here so that it can be called on const objects
    // but still manage to return the original object
    // With only the nonconst we would not be able to call this function on
    // a const object even though the function does not change anything
    // With only the const version we would not be able to convert it back to
    // a nonconst from a const object
    Screen & print(std::ostream &);
    const Screen & print(std::ostream &) const;
    private:
    void disp(std::ostream &) const;
    // This next function is only for informational purposes
    // See the definition below
    pos return_type(pos);
    pos cursor = 0;
    pos width = 0, height = 0;
    std::string contents;
    // A class definition isn't finished until it hits the closing brace
    // As a result we CANNOT define a member as one of its own
    // This code would throw an error since Screen is an incomplete type
    // Screen thisScreen;
    // However, we CAN declare a POINTER to one of its own
    Screen * thisScreen; // This is legal but the pointer is uninitialized
    // If we initialized as a new Screen it we would run into a loop where each
    // Screen defines a new Screen until we ran out of memory
};

// Note that we can use pos typedef because this is a member function and
// inside the scope of the class
// Also we can define this as inline even though the in-class declaration is not
// Lastly, having a Screen ref return and returning *this will return the
// object that is being used and allow us to chain calls together
// ie: myScreen.move(3,3).get();
inline Screen & Screen::move(pos r, pos c)
{
    cursor = r * width + c;
    return *this;
}

int height = 20; // Used below
// We have to expicitly refer to Screen::pos typedef for the return type
// because the return type is considered outside the scope of the class
// when we define it here but the parameter list is inside the class scope
// Note that the in-class declaration uses only 'pos' for the return
Screen::pos Screen::return_type(pos height)
{
    // using height as a parameter HIDES the outer (class) scope variable
    // When we change height right here we are changing the parameter
    // and NOT the class member
    height = 10; // Changes parameter
    // We can use this->height to explicitly refer to the member
    // This is bad code though and you should really just name things better
    this->height = 10; // Changes member and not parameter
    // We can also explicitly refer to the scope outside of the class with
    // the global scope operator ::
    ::height = 10; // Changes the int that is defined right before this function
    return 100;
}

inline char Screen::get(pos r, pos c) const
{
    return contents[r * width + c];
}

inline Screen & Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen & Screen::set(pos r, pos c, char cc)
{
    contents[r * width + c] = cc;
    return *this;
}

void Screen::disp(std::ostream & os) const
{
    std::string line;
    for (pos i = 0; i < height; ++i)
    {
        line = contents.substr(i * width, width);
        os << line << std::endl;
    }
    os << std::endl;
    return;
}

Screen & Screen::print(std::ostream & os)
{
    disp(os);
    return *this;
}

const Screen & Screen::print(std::ostream & os) const
{
    disp(os);
    return *this;
}

class WindowManager
{
    public:
    typedef std::vector<Screen>::size_type screen_index;
    void clear(screen_index);
    private:
    std::vector<Screen> screens{Screen(80, 24)};
};

void WindowManager::clear(screen_index i)
{
    Screen & s = screens[i]; // get screen
    // If we had not defined WindowManager as a friend inside Screen
    // this code would be illegal
    // However, this is only for demonstration and a better way of handling
    // this functionality would be to define a public clear function for Screen
    s.contents = std::string(s.width * s.height, ' ');
}

// Useless class that's only here to demonstrate some quirks about classes
class myClass
{
    int a;
    int b;
    // class members are initialized in the order that they are defined
    // IN THE CLASS (the order of the list below does NOT MATTER)
    myClass(int val, double val2, std::string str):
        b(val), a(b) {}
    // UNDEFINED BEHAVIOR because a is actually initialized
    // FIRST! a will initialize to b's UNDEFINED value
    // This will still compile but you are likely to get garbage values

    // We can use Delegating Constructors to refer to other constructors
    // if we can simply use the other constructor with some values
    // Uses similar syntax to the initializer list but with the class name
    // We provide the arguments in parentheses
    myClass(): myClass(10, 10.01, "myClass") {}
    // Now we have a default constructor that delegates to the other constructor
    // and provides arguments to it
    // Although the function bodies are empty, if they were not the delegating
    // constructor body would execute AFTER the original constructor body
};

// constexpr class
class Debug
{
    public:
    constexpr Debug(bool h, bool i, bool o):
        hw(h), io(i), other(o) {}
    constexpr Debug(bool b = true): 
        hw(b), io(b), other(b) {}
    constexpr bool any() const { return hw || io || other;}
    void set_io(bool b) {io = b;}
    void set_hw(bool b) {hw = b;}
    void set_other(bool b) {other = b;}
    private:
    bool hw, io, other;
};

#endif //SCREEN_H