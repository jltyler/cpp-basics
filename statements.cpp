#include <iostream>
#include <vector>
#include <sstream>
// #include <stdexcept>

using std::cout; using std::cin; using std::endl; 
using std::string; using std::vector;

int main()
{
    {
        // Statements end with semicolons (usually)
        int iVal = 0;
        iVal + 5; // Useless statement
        cout << iVal << endl; // Useful statement
        ; // null statement
        // Why use a null statement?
        std::istringstream str("Input that is seperated by spaces. It also includes punctuation!");
        string s;
        while(str >> s && s[0] != 's') 
            ; // loops but does nothing with null statement
        cout << s << endl;
        // Be wary of inadvertently placing null statements after loops
        auto iter = s.begin();
        // while(iter != s.end()); // OH NO! Infinite loopums
            // ++iter; // not part of the while loop!
        
        // Blocks
        // Multiple statements wrapped in curlies makes a block
        // aka compound statement
        while (iter != s.end())
        { // block begins
            cout << *iter << " ";
            ++iter;
        } // block ends
        cout << endl;
    }
    // Exercise 5.1
    {
        unsigned iter = 0;
        unsigned sum = 0;
        while (sum <= 1000)
            sum += iter, ++iter;
        cout << "iter: " << iter << endl;
        cout << "sum: " << sum << endl;

    }
    // Statement control initialization and scope
    {
        if (true)
            int i = 20;
        // cout << i << endl; // Error! i is not in this scope
        if (int i = 1)
            cout << i << endl;
        // cout << i << endl; // Error! i is not in this scope
    }
    // Switch
    {
        // Good for multiple fixed paths
        // Case labels must be constant
        int iVal = 2;
        int intFive = 5;
        switch (iVal)
        {
        case 0:
            cout << "Zero" << endl;
            // Without a break statement this will continue with the other cases
        case 1:
            cout << "One" << endl;
        case 2:
            cout << "Two" << endl;
        case 3:
            cout << "Three" << endl;
        case 4:
            cout << "Four" << endl;
            break;
        // case intFive: // Error! case label must be constant
        //     cout << "Five" << endl;
        //     break;

        default: // Case used when no other cases match
            cout << "Naw dawg" << endl;
            break;
        }
    }
    // Exercise 5.3.2
    {
        // Count characters
        std::istringstream str("Real bad, pa. They ain't fed me since I got here and the Sheriff's been roughin up on me somethin fierce.");
        string s = "";
        while (getline(str, s));
            // s += '\n';
        int vowels = 0, consonants = 0, whitespaces = 0, estuffs = 0;
        for(auto &c : s)
        {
            char *n;
            switch (c)
            {
            case 'e':
                n = &c + 1;
                if (*n != '\0' && (*n == 'e' || *n == 'r' || *n == ' '))
                    ++estuffs;
            case 'a': case 'i': case 'o': case 'u':
            case 'A': case 'E': case 'I': case 'O': case 'U':
                ++vowels;
                break;
            case ' ': case '\t': case '\n':
                ++whitespaces;
                break;
            default:
                ++consonants;
            }
        }
        cout << "vowels: " << vowels << endl;
        cout << "consonants: " << consonants << endl;
        cout << "whitespaces: " << whitespaces << endl;
        cout << "estuffs: " << estuffs << endl;
    }
    // Exercise 5.4.1
    {
        std::istringstream str("how now low now now now show wow wow wow wow wow bow now now now bow low chow cow");
        vector<string> vec;
        string s;
        while (str >> s)
            vec.push_back(s);

        int best = 0, cnt = 0;
        string sBest = "", sLast = "";
        int iCnt = 100;
        for (auto iter = vec.begin(); iter != vec.end() && iCnt > 0; ++iter, --iCnt)
        {
            if (iter == vec.begin())
            {
                sBest = *iter;
                cnt = 1;
                continue;
            }
            else if (*iter == *(iter - 1))
            {
                ++cnt;
                if (cnt > best)
                {
                    best = cnt;
                    sBest = *iter;
                }
            }
            else
            {
                cnt = 1;
            }
        }
        cout << best << " occurences of \"" << sBest << "\"\n";
    }
    // Exceptions
    {
        // Throwing errors
        // runtime_error is builtin exception type
        int money = 100;
        cout << "Enter \"100\"..." << endl << '>';
        if (cin >> money)
            if (money != 100)
                throw std::runtime_error("Those were simple instructions, no?");
            cout << money << " moneys. Well done." << endl;

        // try catch statements
        try
        {
            int dosh = 200;
            cout << "I wan 232 doshes! GIMME DOSH!\n>";
            while (cin >> money)
            {
                dosh += money;
                if (dosh < 232)
                    cout << "\nGimmemore\n>";
                else if (dosh > 232)
                    cout << "\nNow I got " << dosh << "! That's TOO MUCH.\n",
                    throw std::runtime_error("TOOMUCH");
                else
                {
                    cout << "kthxbye\n"; break;
                }
            }
        }
        catch (const std::runtime_error& err)
        {
            cout << "You gave too much. Why? Why would you do this?\n";
            // cout << dosh; // Error: dosh is not in scope
            cout << "Error: " << err.what();

        }
        
    }
    // Exercise 5.6.3
    {
        int val1, val2;
        cout << "Enter two integers\n>";
        cin >> val1 >> val2;
        try
        {
            if (val2 == 0)
                throw std::runtime_error("Nearly divided by zero there!");
        }
        catch (const std::runtime_error&)
        {
            while (!val2)
            {
                string s;
                cout << "Enter a nonzero value\n>";
                if (cin >> val2)
                    // Loops endlessly if you enter a non integer value
            }
        }
        cout << "Divided: " << val1 / val2 << endl;
        cout << "Finished..." << endl;
    }
    return 0;
}