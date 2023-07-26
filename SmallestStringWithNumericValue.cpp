
#include<bits/stdc++.h>

using namespace std;

string getSmallestString(int n, int k);

int main()
{
    cout << getSmallestString(5,73);

    getchar();
    return 0;
}

string getSmallestString(int n, int k) 
{
    string res = "";
    for(int a = 0; a < n; ++a)
    {
        res += 'a';
    }

    int currSum = n;
    for(int a = n-1; a >= 0 && currSum != k; --a)
    {
        if(currSum + 25 <= k)
        {           
             res[a] = 'z';
             currSum += 25;
        }
        else
        {
            res[a] = 'a' + (k - (currSum - 1) - 1);
            currSum += (k - (currSum - 1)) - 1;
        }
    }

    return res;   
}