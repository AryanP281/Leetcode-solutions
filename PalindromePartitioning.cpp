
#include<bits/stdc++.h>

using namespace std;

vector<vector<string>> partition(string s);
void palindromePartitioning(int i, string& s, bool** isPalindrome, vector<vector<string>>* dp);

int main()
{

    partition("bb");

    getchar();

    return 0;
}

vector<vector<string>> partition(string s) 
{
    bool** isPalindrome = new bool*[s.size()];
    for(int i = 0; i < s.size(); i++)
    {
        isPalindrome[i] = new bool[s.size()]();
        isPalindrome[i][i] = true;
    }

    for(int l = 2; l <= s.size(); ++l)
    {
        for(int r = 0; r < s.size(); ++r)
        {
            if(r+l-1 >= s.size())
                break;
            
            if(s[r] == s[r+l-1])
            {
                isPalindrome[r][r+l-1] = true;
                if(r+1 <= (r+l-2))
                    isPalindrome[r][r+l-1] &= isPalindrome[r+1][r+l-2];
            }
        }
    }
    
    
    vector<vector<string>>* dp = new vector<vector<string>>[s.size()];

    palindromePartitioning(0, s, isPalindrome, dp);

    vector<vector<string>> res = dp[0];
    delete[] dp;
    
    return res;
}

void palindromePartitioning(int i, string& s, bool** isPalindrome, vector<vector<string>>* dp)
{
    if(!(dp[i].empty()))
        return;

    for(int j = i; j < s.size(); ++j)
    {
        if(isPalindrome[i][j])
        {
            if(j == s.size()-1)
            {
                dp[i].push_back({s.substr(i,j-i+1)});
                continue;
            }

            palindromePartitioning(j+1, s, isPalindrome, dp);
            string substr = s.substr(i,j-i+1);
            for(int k = 0; k < (dp+j+1)->size(); ++k)
            {
                dp[i].push_back({substr});
                for(int l = 0; l < dp[j+1][k].size(); ++l)
                {
                    dp[i].rbegin()->push_back(dp[j+1][k][l]);
                }
            }
        }
    }
}