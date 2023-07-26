
#include<bits/stdc++.h>

using namespace std;

int countPrimeSetBits(int L, int R);
unordered_set<int> getPrimes(int n);
int getSetBits(int x);

int main()
{
    cout << countPrimeSetBits(10,15);

    getchar();
    return 0;
}

int countPrimeSetBits(int L, int R) 
{
    unordered_set<int> primes = getPrimes(sizeof(int)*8);

    int numsCount = 0;
    for(int a = L; a <= R; ++a)
    {
        if(primes.count(getSetBits(a)) == 1)
            ++numsCount;
    }

    return numsCount;   
}

unordered_set<int> getPrimes(int n)
{
    int* nums = new int[n-2+1];
    for(int a = 0; a < (n-2+1); ++a)
    {
        nums[a] = 2+a;
    }

    for(int a = 0; a <= (floor(sqrt(n)) - 2); ++a)
    {
        if(nums[a] == 0)
            continue;
        
        for(int b = 2; nums[a]*b <= n; ++b)
        {
            nums[nums[a]*b - 2] = 0;
        }
    }

    unordered_set<int> primes;
    for(int a = 0; a < (n-2+1); ++a)
    {
        if(nums[a] != 0)
            primes.insert(nums[a]);
    }

    delete[] nums;

    return primes;
}

int getSetBits(int x)
{
    int setBits = 0;
    for(int i = 0; i < sizeof(int)*8; ++i)
    {
        setBits += 1*((x & (1 << i)) != 0);
    }

    return setBits;
}