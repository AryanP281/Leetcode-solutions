
#include<bits/stdc++.h>

using namespace std;

int kthGrammar(int n, int k);

int main()
{

    cout << kthGrammar(3,6);

    getchar();
    return 0;
}

int kthGrammar(int n, int k) 
{
    const int bitMap[2] = {1,2};

    stack<int> bitPos;
    int currK = k;
    while(currK > 2)
    {
        bitPos.push(currK);
        currK = ceil((double)currK / 2.0);
    }

    int currBit = (currK == 2) ? 1 : 0;
    int prevPos = currK;
    while(!bitPos.empty())
    {
        int nextBit = (bitMap[currBit] >> min(1,bitPos.top() % prevPos)) & 1;
        prevPos = bitPos.top();
        bitPos.pop();
        currBit = nextBit;
    }

    return currBit; 
}