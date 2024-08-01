#include<bits/stdc++.h>

using namespace std;


int main()
{

    getchar();
    return 0;
}

bool isHappy(int n) 
{
    unordered_set<int> seen;

    while(n != 1)
    {
        if(seen.count(n))
            return false;

        seen.insert(n);
        
        vector<int> dgs = getDigits(n);
        n = 0;
        for(int i = 0; i < dgs.size(); ++i)
        {
            n += dgs[i]*dgs[i];
        }
    }   

    return true;
}

vector<int> getDigits(int x)
{
    vector<int> digits;
    while(x > 0)
    {
        digits.push_back(x % 10);
        x = floor((double)x / 10.0);
    }
    
    return digits;
}