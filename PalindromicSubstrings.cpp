
#include<bits/stdc++.h>

using namespace std;

int countSubstrings(string s);
bool isPalindrome(unordered_set<char>& chars, int start, int end);

int main()
{
    string str = "abcba";
    cout << countSubstrings(str);

    getchar();
    return 0;
}

int countSubstrings(string s) 
{
    /*
        matrix[i][j] = true iff the substring from ith index to jth index is a palindrome. Thus, the substring from s[i] to s[j] is a 
        palindrome if the ending character i.e s[j] is same as starting character i.e s[i] and the substring from (i+1) to (j-1) is
        palindrome.
        Thus, matrix[i][j] = (s[i] == s[j]) && matrix[i+1][j-1]
    */
    
    bool** matrix = new bool*[s.size()];
    for(int i = 0; i < s.size(); ++i)
    {
        matrix[i] = new bool[s.size()];
        fill_n(matrix[i], s.size(), true);
    }

    int substrings = 0;
    for(int c = 0; c < s.size(); ++c)
    {
        for(int r = 0; r < c; ++r)
        {
            matrix[r][c] = (s[r] == s[c]) && matrix[r+1][c-1];
            substrings += 1*(matrix[r][c]);
        }
        substrings++;
    }

    for(int a = 0; a < s.size(); ++a)
    {
        delete[] matrix[a];
    }
    delete[] matrix;

    return substrings;
}