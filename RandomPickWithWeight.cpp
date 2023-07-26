
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pi;

class Solution 
{
private :
    vector<pi> indices;
    int sum;

    int getRand()
    {
        return 1 + (rand() % 100);
    }

    int binarySearch(int prob)
    {
        int l = 0;
        int r = indices.size();
        int mid = 0;
        while(l+1 < r)
        {
            mid = l + ((r-l)/2);
            if(indices[mid].second <= prob) l = mid;
            else r = mid;
        }

        if(indices[l].second > prob) return l;
        return r;
    }

public:
    Solution(vector<int>& w) 
    {
        this->sum = 0;
        for(int a = 0; a < w.size(); ++a)
        {
            indices.push_back(pi(a,w[a]));
            sum += w[a];
        }
        
        int cumSum = 0;
        for(int a = 0; a < indices.size(); ++a)
        {
            cumSum += indices[a].second;
            indices[a].second = ((double)cumSum / (double)sum) * 100;
        }

        sort(indices.begin(), indices.end(), [](pi& p1, pi& p2) -> bool
        {
            return p1.second < p2.second;
        });
    }
    
    int pickIndex() 
    {
        int randNum = getRand();

        return binarySearch(randNum);
    }
};

int main()
{
    vector<int> w = {3,14,1,7};
    Solution sol(w);

    for(int a = 0; a < 5; ++a)
    {
        cout << sol.pickIndex() << '\n';
    }

    getchar();
    return 0;
}

/*
int binarySearch(int randNum, int l, int r)
    {
        if(l >= r-1)    
            return (indices[l].second < randNum && l != indices.size()-1) ? indices[l+1].first : indices[l].first; 
        
        int m = l + ((r-l) / 2);

        if(randNum == indices[m].second) return indices[m].first;
        else if(randNum < indices[m].second) return binarySearch(randNum, l,m-1);
        
        return binarySearch(randNum,m+1,r);
    }*/