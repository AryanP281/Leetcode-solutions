/*
#include<iostream>
#include <vector>
#include <string>

using namespace std;

string removeOuterParentheses(string s);

void main()
{
    cout << removeOuterParentheses("()()");
}

string removeOuterParentheses(string s)
{
    int parenthesisBalance = 0;
    vector<string> decompStrings;
    int charIndex = 0;
    string currentDecomp = "";
    while (charIndex < s.size())
    {
        currentDecomp += s[charIndex];
        parenthesisBalance += (-1 * (s[charIndex] == '(')) + (1 * (s[charIndex] == ')'));

        if (parenthesisBalance == 0)
        {
            decompStrings.push_back(currentDecomp);
            currentDecomp.clear();
        }

        ++charIndex;
    }

    string reqStr = "";
    for (int a = 0; a < decompStrings.size(); ++a)
    {
        decompStrings[a].erase(0, 1);
        decompStrings[a].erase(decompStrings[a].size() - 1, 1);
        reqStr += decompStrings[a];
    }

    return reqStr;
}
*/