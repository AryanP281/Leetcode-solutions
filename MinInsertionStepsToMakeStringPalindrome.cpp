
#include<bits/stdc++.h>

using namespace std;

int minInsertions(string s);

int main()
{

    cout << minInsertions("zzazz");

    getchar();
    return 0;
}

int minInsertions(string s) 
{
    int** insertions = new int*[s.size()];
    for(int r = 0; r < s.size(); ++r)
    {
        insertions[r] = new int[s.size()]();
    }

    for(int c = 1, offset = 0; c < s.size(); offset++, c = 1 + offset)
    {
        for(int r = 0; r < s.size() && c < s.size(); ++r, ++c)
        {
            if(s[r] == s[c] && r != c)
                insertions[r][c] = insertions[r+1][c-1];
            else if(s[r] != s[c])
                insertions[r][c] = min(insertions[r+1][c], insertions[r][c-1]) + 1;
        }
    }

    int res = insertions[0][s.size()-1];

    for(int r = 0; r < s.size(); ++r)
    {
        delete[] insertions[r];
    }
    delete[] insertions;

    return res;
}