
#include<bits/stdc++.h>

using namespace std;

double myPow(double x, int n);
double calc(double x, int n, unordered_map<int64_t,double>& dp);

int main()
{

    cout << myPow(2,-2147483648);

    getchar();
    return 0;
}

double myPow(double x, int n) 
{
    if(x == 0)
        return 0;
    else if(n == 0)
        return 1.0;

    unordered_map<int64_t,double> dp;
    double res = calc(x,abs(n),dp);
    if(n < 0)
        return 1.0/res;

    return res;
}

double calc(double x, int n, unordered_map<int64_t,double>& dp)
{
    if(n == 1)
        return x;
    
    unordered_map<int64_t,double>::iterator itr = dp.find(n);
    if(itr != dp.end())
        return itr->second;

    if(n % 2) // Odd power
        dp[n] = calc(x,abs(floor(((double)n)/2.0)),dp) * calc(x, abs(ceil(((double)n)/2.0)),dp);
    else
    {
        dp[n] = calc(x, abs(n/2), dp);
        dp[n] *= dp[n];
    }
    
    return dp[n];
}