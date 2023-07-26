
#include<bits/stdc++.h>

using namespace std;

int minSteps(string s, string t);

int main()
{

    cout << minSteps("night", "thing");

    getchar();
    return 0;
}

int minSteps(string s, string t) 
{
    int** charCounts = new int*[2];
    for(int8_t i = 0; i < 2; ++i)
    {
        charCounts[i] = new int[26]();
    }

    for(int i = 0; i < s.size(); ++i)
    {
        charCounts[0][s[i] - 'a']++;
    }
    for(int i = 0; i < t.size(); ++i)
    {
        charCounts[1][t[i] - 'a']++;
    }

    int steps = 0;
    for(int8_t i = 0; i < 26; ++i)
    {
        steps += abs(charCounts[0][i] - charCounts[1][i]);
    }


    delete[] charCounts[0];
    delete[] charCounts[1];
    delete[] charCounts;

    return steps;
}