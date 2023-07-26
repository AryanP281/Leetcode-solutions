
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Vec;

int minimumOneBitOperations(int n);
int changeToTarget(int num, int bitPos, int targetBit, int* flipsCount, unordered_map<int,Vec>* cache);

int main()
{
    cout << minimumOneBitOperations(333);

    getchar();
    return 0;
}

int minimumOneBitOperations(int n) 
{
    unordered_map<int, Vec>* cache = new unordered_map<int,Vec>[sizeof(int)*8];
    
    int flipsCount = 0;
    for(int a = sizeof(n)*8-1; a >= 0 && n != 0; --a)
    {
        n = changeToTarget(n, a, 0, &flipsCount, cache);
    }

    delete[] cache;
    return flipsCount;
}

int changeToTarget(int num, int bitPos, int targetBit, int* flipsCount, unordered_map<int,Vec>* cache)
{
    if(bitPos < 0)
        return num;
    
    auto getBit = [](int num,int pos) -> int
    {
        return (1*((num & (1 << pos)) != 0));
    };

    auto setBit = [&num](int pos, int value) -> void
    {
        if(value == 0)
            num &= ~(1 << pos);
        else
            num |= (1 << pos);
    };

    auto getPre = [&num](int pos) -> int
    {
        int pre = 0;
        for(int a = 0; a < pos; ++a)
        {
            pre |= (num & (1 << a));
        }
        return pre;
    };

    int bit = getBit(num,bitPos);
    if(bit == targetBit)
        return num;

    if(bitPos == 0)
        setBit(bitPos, (bit == 0 ? 1 : 0));
    else
    {
        int prefix = getPre(bitPos);
        unordered_map<int,Vec>::iterator itr = cache[bitPos].find(prefix);
        if(itr != cache[bitPos].end())
        {
            *flipsCount += itr->second.first + 1;
            setBit(bitPos, targetBit);
            for(int a = bitPos-1; a >= 0; --a)
            {
                setBit(a, getBit(itr->second.second, a));
            }
            return num;
        }
        
        int startFlips = *flipsCount;
        num = changeToTarget(num, bitPos-1,1,flipsCount,cache);
        for(int a = bitPos-2; a >= 0; --a)
        {
            num = changeToTarget(num, a, 0, flipsCount,cache);
        }
        setBit(bitPos, targetBit);

        cache[bitPos][prefix] = Vec(*flipsCount - startFlips, getPre(bitPos));
    }

    (*flipsCount)++;
    return num;
}