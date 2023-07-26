
#include<bits/stdc++.h>

using namespace std;

int minNumberOperations(vector<int>& target);
int getCumSum(int* BIT, int n, int idx);
void increment(int* BIT, int n, int idx, int val);

int main()
{
    //vector<int> target = {1,2,3,2,1};
    //vector<int> target = {3,1,1,2};
    //vector<int> target = {3,1,5,4,2};
    vector<int> target = {1,1,1,1};
    cout << minNumberOperations(target);

    getchar();
    return 0;
}

int minNumberOperations(vector<int>& target) 
{
    map<int,vector<int>> vals;
    for(int a = 0; a < target.size(); ++a)
    {
        vals[target[a]].push_back(a);
    }

    set<int> indices;
    indices.insert(-1);
    indices.insert(target.size());

    int n = target.size()+2;
    int* BIT = new int[n]();

    int movesCount = 0;
    int currVal, diff;
    set<int>::iterator l,r;
    map<int,vector<int>>::iterator valItr = vals.begin();
    while(valItr != vals.end())
    {
        for(int a = 0; a < valItr->second.size(); ++a)
        {
            currVal = getCumSum(BIT, n, valItr->second.at(a));
            if(currVal == target[valItr->second[a]])
            {
                indices.insert(valItr->second[a]);
                continue;
            }

            diff = target[valItr->second[a]]-currVal;

            r = indices.upper_bound(valItr->second[a]);
            l = r;
            --l;

            increment(BIT, n,*l+1, diff);
            increment(BIT, n, *r, -diff);
            
            indices.insert(valItr->second[a]);
            movesCount += diff;
        }

        valItr++;
    }

    delete[] BIT;

    return movesCount;
}

int getCumSum(int* BIT, int n, int idx)
{
    idx++;
    int cumSum = 0;
    while(idx > 0)
    {
        cumSum += BIT[idx];
        idx -= (idx & -idx);
    }

    return cumSum;
}

void increment(int* BIT, int n, int idx, int val)
{
    idx++;
    while(idx < n)
    {
        BIT[idx] += val;
        idx += (idx & -idx);
    }
}

/*
T=[1,2,3,2,1], v=[1:(0,4),2:(1,3),3:(2)], i=[-1,0,1,3,4,5], cs=[1,1,1,-1,-1]
l=0,r=4,[1,1,1,1,1],m=1
l=1,r=3,[1,2,2,2,1],m=2
l=2,r=2,[1,2,3,2,1],m=3

T=[3,1,1,2], v=[1:(1,2),2:(3),3:(0)], i=[-1,1,2,3,4], cs=[3,-2,0,1]
l=0,r=3,[1,1,1,1],m=1
l=3,r=3,[1,1,1,2],m=2
l=0,r=0,[3,1,1,2],m=4

T=[3,1,5,4,2], v=[1:(1),2:(4),3:(0),4:(3),5:(2)], i=[-1,0,1,3,4,5], cs=[3,-2,4,-1,-2]
l=0,r=4,[1,1,1,1,1], m=1
l=2,r=4,[1,1,2,2,2],m=2
l=0,r=0,[3,1,2,2,2],m=4
l=1,r=3,[3,1,4,4,2],m=6
l=2,r=2,[3,1,5,4,2],m=7

T=[1,1,1,1], v=[1:(0,1,2,3,4)], i=[-1,4], cs=[1,0,0,0]
l=0,r=3,[1,1,1,1], m=1
*/