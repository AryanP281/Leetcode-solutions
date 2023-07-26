
#include<bits/stdc++.h>

using namespace std;

int findMinFibonacciNumbers(int k);
int getMinFibs(vector<int>& fibs, int k);

int main()
{
    cout << findMinFibonacciNumbers(21);

    getchar();
    return 0;
}

int findMinFibonacciNumbers(int k) 
{
   vector<int> fibs = {1,1};
   int i = 2;
   while(*fibs.rbegin() <= k)
   {
       fibs.push_back(fibs[i-1] + fibs[i-2]);
       i++;
   }
   fibs.pop_back();

   return getMinFibs(fibs,k); 
}

int getMinFibs(vector<int>& fibs, int k)
{
    if(k==0) return 0;

    int l = 0;
    int r = fibs.size()-1;
    int maxFib = k;
    while(l <= r)
    {
        int m = l + (r-l)/2;
        if(fibs[m] == k)
        {
            maxFib = fibs[m];
            break;
        }
        else if(fibs[m] < k)
        {
            maxFib = fibs[m];
            l = m+1;
        }
        else
            r = m-1;
    }

    return 1 + getMinFibs(fibs, k - maxFib);
}