
#include<bits/stdc++.h>

using namespace std;

int minCostToMoveChips(vector<int>& position);

int main()
{
    vector<int> positions = {1,1000000000};
    cout << minCostToMoveChips(positions);
    
    getchar();
    return 0;
}

int minCostToMoveChips(vector<int>& position) 
{
    int oddChips = 0;
    int evenChips = 0;
    for(int a = 0; a < position.size(); ++a)
    {
        if(position[a] % 2 == 0) 
            ++evenChips;
        else
            ++oddChips;
    }

    return min(oddChips, evenChips);
}   