
#include<bits/stdc++.h>

using namespace std;

int countPalindromicSubsequence(string s);

int main()
{
    cout << countPalindromicSubsequence("tlpjzdmtwderpkpmgoyrcxttiheassztncqvnfjeyxxp");

    getchar();
    return 0;
}

int countPalindromicSubsequence(string s) 
{
    int* prevPos = new int[26];
    fill_n(prevPos, 26, -1);

    unordered_set<char>* palindromes = new unordered_set<char>[26];
    for(int i = 0; i < s.size(); ++i)
    {
        if(prevPos[s[i] - 'a'] != -1)
        {
            for(int j = prevPos[s[i]-'a'] + 1*(palindromes[s[i]-'a'].size() == 0); j < i; ++j)
            {
                palindromes[s[i]-'a'].insert(s[j]);
            }
        }

        if(i == 0 || prevPos[s[i]-'a'] != i-1)
            prevPos[s[i]-'a'] = i;
    }

    int palindromesCount = 0;
    for(int i = 0; i < 26; ++i)
    {
        palindromesCount += palindromes[i].size();
    }

    delete[] prevPos;
    delete[] palindromes;

    return palindromesCount;
}