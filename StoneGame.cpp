
/********************************INCORRECT**************/

#include<bits/stdc++.h>

using namespace std;

bool stoneGame(vector<int>& piles);
int getOptimalScore(vector<int>& arr,int l, int r, int** lookupTable);

int main()
{
    vector<int> piles = {5,3,4,5};
    cout << (stoneGame(piles) ? "True" : "False");

    getchar();
    return 0;
}

bool stoneGame(vector<int>& piles) 
{
    typedef pair<int,int> Vec2D;

    auto getIndex = [](int r, int c, int n) -> int
    {
        return (r*n) + c;
    };
    
    Vec2D* lookupTable = new Vec2D[piles.size()*piles.size()]();
    for(int i = 0; i < piles.size(); ++i)
    {
        lookupTable[getIndex(i,i,piles.size())] = Vec2D(piles[i], 0);
    }

    for(int c = 1; c < piles.size(); ++c)
    {
        Vec2D coords = Vec2D(0,c);
        int op1,op2;
        while(coords.first < piles.size() && coords.second < piles.size())
        {
            op1 = piles[coords.first] + lookupTable[getIndex(coords.first+1,coords.second,piles.size())].second;
            op2 = piles[coords.second] + lookupTable[getIndex(coords.first, coords.second-1,piles.size())].second;

            int index = getIndex(coords.first, coords.second, piles.size());
            if(op1 > op2)
            {
                lookupTable[index].first = op1;
                lookupTable[index].second = lookupTable[getIndex(coords.first+1,coords.second,piles.size())].first;
            }
            else
            {
                lookupTable[index].first = op2;
                lookupTable[index].second = lookupTable[getIndex(coords.first, coords.second-1,piles.size())].first;
            }

            coords.first++;
            coords.second++; 
        }
    }

    int index = getIndex(0, piles.size()-1,piles.size());
    bool alexWins = lookupTable[index].first > lookupTable[index].second;
    delete[] lookupTable;

    return alexWins;
}