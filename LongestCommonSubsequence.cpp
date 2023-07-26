
#include<bits/stdc++.h>

using namespace std;

int longestCommonSubsequence(string text1, string text2);

int main()
{
    string text1 = "abcdgh";
    string text2 = "aedfhr";
    cout << longestCommonSubsequence(text1, text2);

    getchar();
    return 0;
}

int longestCommonSubsequence(string text1, string text2) 
{
    int** table = new int*[text1.size()];
    for(int a = 0; a < text1.size(); ++a)
    {
        table[a] = new int[text2.size()];
        fill_n(table[a],text2.size(),0);
    }

    for(int i = 0; i < text1.size(); ++i)
    {
        for(int j = 0; j < text2.size(); ++j)
        {
            if(text1[i] == text2[j])
            {
                if(i == 0 || j == 0)
                    table[i][j] = 1;
                else
                    table[i][j] = table[i-1][j-1] + 1;
            }
            else
            {
                if(i == 0 && j == 0)
                    table[i][j] = 0;
                else if(i == 0)
                    table[i][j] = table[i][j-1];
                else if(j == 0)
                    table[i][j] = table[i-1][j];
                else
                    table[i][j] = max(table[i-1][j], table[i][j-1]);
            }
        }
    }

    return table[text1.size()-1][text2.size()-1];    
}