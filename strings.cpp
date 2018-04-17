#include <iostream>
#include <string>

using std::string; using std::cin; using std::cout; using std::endl;

void inputWordsAndWhitespace()
{
    string outputText;
    string inputLine;
    string testText = "Oh wow lookit!\n SKREEEE!";
    // while (getline(cin, inputLine)) // one line at a time
    while (cin >> inputLine) // one word at a time
    {
        outputText += inputLine + '\n';
    }
    cout << outputText;
    return;
}

void comparingStrings()
{
    string string1, string2;
    cout << "Enter string 1:\n";
    getline(cin, string1);
    cout << "Enter string 2:\n";
    getline(cin, string2);
    auto size1 = string1.size();
    auto size2 = string2.size();
    if (size1 == size2)
    {
        cout << "\"" << string1 << "\" and \"" << string2 << "\" are the same length!\n";
    }
    else if (size1 < size2)
    {
        cout << "\"" << string1 << "\" is shorter than \"" << string2 << "\"\n";
    }
    else if (size1 > size2)
    {
        cout << "\"" << string1 << "\" is longer than \"" << string2 << "\"\n";
    }
    if (string1 == string2)
    {
        cout << "\"" << string1 << "\" and \"" << string2 << "\" are equal!\n";
        return;
    }
    if (string1 > string2)
    {
        cout << "\"" << string1 << "\" is greater than \"" << string2 << "\"\n";
        return;
    }
    else
    {
        cout << "\"" << string1 << "\" is less than \"" << string2 << "\"\n";
        return;
    }
}

void iterationString()
{
    unsigned currentChar = 0;
    unsigned letters = 0, digits = 0, puncts = 0, spaces = 0;
    string string1 = "Attention all employees!\nStay single file!\nResistance is futile!";
    for (auto c : string1) // Iterate thru string1 reading into c
    {
        if (isalpha(c))
            letters++;
        if (isdigit(c))
            digits++;
        if (ispunct(c))
            puncts++;
        if (isspace(c))
            spaces++;
        // cout << currentChar << ": " << c << endl;
        currentChar++;
    }
    cout << "\"" << string1 << "\"\n";
    cout << "Character count\n  Letters: " << letters <<
    "\n  Digits: " << digits <<
    "\n  Spaces: " << spaces <<
    "\n  Punctuation: " << puncts << endl;

    string copy1 = string1;
    for ( auto &c : copy1) // With a reference we can modify the characters
    {
        // if (c == ' ')
        //     c = '_';
        // if (c == 'e')
        //     c = 'x';
        c = 'X';
    }
    cout << copy1 << endl;

    string copy2 = string1;
    decltype(copy2.size()) ii = 0;
    while (ii < copy2.size())
    {
        auto &c = copy2[ii];
        c = 'E';
        ii++;
    }
    cout << copy2 << endl;

    string copy3 = string1;
    for (size_t i = 0; i < copy3.size(); i++)
    {
        auto &c = copy3[i];
        c = '#';
    }
    cout << copy3 << endl;
}

void stripPunct()
{
    string inputText;
    getline(cin, inputText);
    string outputText;
    for(auto c : inputText)
    {
        if (!ispunct(c))
            outputText += c;
    }
    cout << outputText << endl;
}

int main()
{
    // inputWordsAndWhitespace();
    // comparingStrings();
    iterationString();
    // stripPunct();
    return 0;
}