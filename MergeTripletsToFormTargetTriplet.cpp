
#include<bits/stdc++.h>

using namespace std;

bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target);

int main()
{
    vector<vector<int>> triplets = {{2,5,3},{1,8,4},{1,7,5}};
    vector<int> target = {2,7,5};
    cout << mergeTriplets(triplets, target);

    getchar();
    return 0;
}

bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) 
{
    multimap<int,vector<int>,greater<int>> heaps[3];
    for(int i = 0; i < triplets.size(); ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            heaps[j].insert(pair<int,vector<int>>(triplets[i][j], triplets[i]));
        }
    }

    for(int i = 0; i < 3; ++i)
    {
        bool tripletFound = false;
        for(multimap<int,vector<int>>::iterator itr = heaps[i].begin(); itr != heaps[i].end() && !tripletFound; itr++)
        {
            if(itr->first == target[i] && itr->second[(i+1) % 3] <= target[(i+1) % 3] && itr->second[(i+2) % 3] <= target[(i+2) % 3])
                tripletFound = true;
            else if(itr->first < target[i])
                break;
        }

        if(!tripletFound)
            return false;
    }

    return true;    
}