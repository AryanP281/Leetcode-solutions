/*
#include <iostream>
#include<string>

using namespace std;

string makeGood(string s);
bool sameLetter(char lower, char upper);

void main()
{
    cout << makeGood("abBAcC");
}

string makeGood(string s)
{
    bool stringIsGreat;

    do
    {
        stringIsGreat = true;
        for (int a = 0; a < ((int)s.size() - 1); ++a)
        {
            if (islower(s[a]) && isupper(s[a + 1]))
            {
                if (sameLetter(s[a], s[a + 1]))
                {
                    s.erase(s.begin() + a);
                    s.erase(s.begin() + a);
                    stringIsGreat = false;
                }
            }
            else if (isupper(s[a]) && islower(s[a + 1]))
            {
                if (sameLetter(s[a + 1], s[a]))
                {
                    s.erase(s.begin() + a);
                    s.erase(s.begin() + a);
                    stringIsGreat = false;
                }
            }
        }


    } while (!stringIsGreat);


    return s;;
}

bool sameLetter(char lower, char upper)
{
    return (lower - 'a') == (upper - 'A');
}
*/