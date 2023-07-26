/*
#include <iostream>
#include<string>
#include<unordered_map>

using namespace std;

unordered_map<string, char> charMapping;

string freqAlphabets(string s);
void generateMapping();

void main()
{
    cout << freqAlphabets("10#11#12");
}

string freqAlphabets(string s)
{
    generateMapping();

    string opt = "";
    for (int a = 0; a < s.size(); ++a)
    {
        if (a <= s.size() - 3 && (s[a] == '1' || s[a] == '2') && s[a + 2] == '#')
        {
            opt += charMapping.at(string(s.begin() + a, s.begin() + a + 3));
            a += 2;
            continue;
        }

        opt += charMapping.at(string(1, s[a]));
    }

    return opt;
}

void generateMapping()
{
    for (char ch = 'a'; ch <= 'i'; ++ch)
    {
        charMapping[string(1, '1' + (ch - 'a'))] = ch;
    }

    for (char ch = 'j'; ch <= 'z'; ++ch)
    {
        charMapping[to_string(10 + (int)(ch - 'j')) + "#"] = ch;
    }
}
*/