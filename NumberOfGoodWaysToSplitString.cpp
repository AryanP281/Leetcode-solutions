/*
#include<iostream>
#include<string>

using namespace std;

int numSplits(string s);

void main()
{
    string s = "acbadbaada";

    cout << numSplits(s);
}

int numSplits(string s)
{
    int leftChars[26] = {};
    int rightChars[26] = {};
    int uniques[2] = { 1,0 };

    leftChars[s[0] - 'a']++;
    for (int a = 1; a < s.size(); ++a)
    {
        uniques[1] += 1 * (rightChars[s[a] - 'a']++ == 0);
    }

    int goodWays = 1 * (uniques[0] == uniques[1]);
    for (int a = 1; a < s.size() - 1; ++a)
    {
        leftChars[s[a] - 'a']++;
        rightChars[s[a] - 'a']--;

        uniques[0] += 1 * (leftChars[s[a] - 'a'] == 1);
        uniques[1] -= 1 * (rightChars[s[a] - 'a'] == 0);
        goodWays += 1 * (uniques[0] == uniques[1]);
    }

    return goodWays;
}
*/