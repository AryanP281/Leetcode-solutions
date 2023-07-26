
#include<bits/stdc++.h>

using namespace std;

string minInteger(string num, int k);
int getOffset(int* BIT, int n, int idx);
void increment(int* BIT, int n, int idx);

int main()
{
    string str = "294984148179";
    cout << minInteger(str, 11);

    getchar();
    return 0;
}

string minInteger(string num, int k) 
{    
    int* BIT = new int[num.size()+1]();

    queue<int>* digitPos = new queue<int>[10];
    for(int a = 0; a < num.size(); ++a)
    {
        digitPos[num[a] - '0'].push(a);
    }

    string resStr = "";
    resStr.reserve(num.size());
    int i = 0;
    int actualPos;
    while(i < num.size())
    {
        for(int a = 0; a < 10; ++a)
        {
            if(digitPos[a].empty())
                continue;

            actualPos = digitPos[a].front() - getOffset(BIT,num.size()+1,digitPos[a].front());
            if(actualPos <= k)
            {
                resStr += '0' + a;
                k -= actualPos;
                increment(BIT,num.size()+1,digitPos[a].front());
                digitPos[a].pop();
                break;
            }
        }
        ++i;
    }

    delete[] BIT;
    delete[] digitPos;

    return resStr;
}

int getOffset(int* BIT, int n, int idx)
{
    idx++;
    int offset = 0;
    while(idx > 0)
    {
        offset += BIT[idx];
        idx -= (idx & -idx);
    }

    return offset;
}

void increment(int* BIT, int n, int idx)
{
    idx++;
    while(idx < n)
    {
        BIT[idx]++;
        idx += (idx & -idx);
    }
}