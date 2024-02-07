
#include<bits/stdc++.h>

using namespace std;

bool checkValidString(string s);
int checkValidity(int currPos, string& str, int currOpen, int** dp);

int main()
{
    string str = "(*))";
    cout << (checkValidString(str) ? "true" : "false");

    getchar();
    return 0;
}

bool checkValidString(string s) 
{
    int** dp = new int*[s.size()];
    for(int i = 0; i < s.size(); ++i)
    {
        dp[i] = new int[s.size()];
        fill_n(dp[i], s.size(), -1);
    }

    int isValid = checkValidity(0,s,0,dp);   

    for(int i = 0; i < s.size(); ++i)
    {
        delete[] dp[i];
    }
    delete[] dp;

    return isValid;
}

int checkValidity(int currPos, string& str, int currOpen, int** dp)
{
    if(currPos == str.size())
        return currOpen ? 0 : 1;
    else if(dp[currPos][currOpen] != -1)
        return dp[currPos][currOpen];

    switch(str[currPos])
    {
        case ')': {
            if(currOpen == 0)
                return 0;
            dp[currPos][currOpen] = checkValidity(currPos+1,str,currOpen-1,dp);
        }; break;

        case '(': {
            dp[currPos][currOpen] = checkValidity(currPos+1, str, currOpen+1, dp);
        }; break;

        case '*': {
            dp[currPos][currOpen] = checkValidity(currPos+1, str, currOpen+1, dp);
            if(currOpen != 0)
                dp[currPos][currOpen] = dp[currPos][currOpen] || checkValidity(currPos+1,str,currOpen-1,dp);
            dp[currPos][currOpen] = dp[currPos][currOpen] || checkValidity(currPos+1,str,currOpen,dp);
        }; break;
    }

    return dp[currPos][currOpen];
}