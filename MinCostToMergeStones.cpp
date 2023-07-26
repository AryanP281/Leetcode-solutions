
#include<bits/stdc++.h>

using namespace std;

int mergeStones(vector<int>& stones, int K);

int main()
{
    vector<int> stones = {3,5,1,2,6};
    cout << mergeStones(stones, 3);

    getchar();
    return 0;
}

int mergeStones(vector<int>& stones, int K) 
{
    typedef pair<int,int> Vec;
    
    if((stones.size()-1)%(K-1) != 0) return -1;

    int** lookupTable = new int*[stones.size()];
    for(int r = 0; r < stones.size(); ++r)
    {
        lookupTable[r] = new int[stones.size()]();
    }

    int* prefixSums = new int[stones.size()];
    prefixSums[0] = stones[0];
    for(int a = 1; a < stones.size(); ++a)
    {
        prefixSums[a] = prefixSums[a-1]+stones[a];
    }

    Vec coords(0,0);
    for(int start = 0; start < stones.size(); ++start)
    {
        coords.first = 0;
        coords.second = start;
        for(; coords.first < stones.size() && coords.second < stones.size(); coords.first++,coords.second++)
        {
            if(coords.first == coords.second)
                lookupTable[coords.first][coords.second] = 0;
            else if(coords.second - coords.first + 1 < K)
                lookupTable[coords.first][coords.second] = 0;
            else if(coords.second - coords.first + 1 == K)
                lookupTable[coords.first][coords.second] = prefixSums[coords.second] - prefixSums[coords.first] + stones[coords.first];
            else
            {
                lookupTable[coords.first][coords.second] = INT_MAX;
                for(int mid = coords.first; mid < coords.second; mid += K-1)
                {
                    lookupTable[coords.first][coords.second] = min(lookupTable[coords.first][coords.second], 
                    lookupTable[coords.first][mid] + lookupTable[mid+1][coords.second]);
                }

                if((coords.second - coords.first) % (K-1) == 0)
                    lookupTable[coords.first][coords.second] += prefixSums[coords.second] - prefixSums[coords.first] + stones[coords.first];
            }
        }
    }

    return lookupTable[0][stones.size()-1];   
}