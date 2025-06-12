
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Pair;

class Window
{
private:
    unordered_map<int,int> membership;

public:
    Window() {}

    unordered_map<int,int>& getWindow() {return membership;}

    int size() const
    {
        return membership.size();
    }

    void increment(int key, int val)
    {
        membership[key] += val;
    }

    void decrement(int key, int val)
    {
        membership[key] -= val;
        
        unordered_map<int,int>::iterator itr = membership.find(key);
        if(itr->second <= 0)
            membership.erase(itr);
    }
};

vector<int> smallestRange(vector<vector<int>>& nums);

int main()
{
    vector<vector<int>> nums = {{1,2,3},{1,2,3},{1,2,3}};
    vector<int> interval = smallestRange(nums);

    getchar();

    return 0;
}

vector<int> smallestRange(vector<vector<int>>& nums) 
{
    const int K = nums.size();

    multimap<int,int> heap;
    vector<int> indices(K, 0);
    for(int i = 0; i < nums.size(); ++i)
    {
        heap.insert(Pair(nums[i][0], i));
        indices[i]++;
    }

    Pair interval(0, INT_MAX);
    while(heap.size() == K)
    {
        Pair currMin = *heap.begin();

        int currIntervalLen = heap.rbegin()->first - currMin.first;
        if(currIntervalLen < interval.second - interval.first)
            interval = Pair(currMin.first, heap.rbegin()->first);

        heap.erase(heap.begin());
        if(indices[currMin.second] < nums[currMin.second].size())
        {
            heap.insert(Pair(nums[currMin.second][indices[currMin.second]], currMin.second));
            indices[currMin.second] += 1;
        }
    }

    return {interval.first, interval.second};
}

vector<int> smallestRange(vector<vector<int>>& nums) 
{
    const int K = nums.size();

    multimap<int,int> heap;
    vector<int> indices(K,0);
    for(int i = 0; i < nums.size(); ++i)
    {
        heap.insert(Pair(nums[i][0], i));
        indices[i]++;
    }
    
    vector<Pair> flattened;
    while(!heap.empty())
    {
        Pair newElement = *heap.begin();
        heap.erase(heap.begin());
        flattened.push_back(newElement);
        if(indices[newElement.second] < nums[newElement.second].size())
        {
            heap.insert(Pair(nums[newElement.second][indices[newElement.second]], newElement.second));
            indices[newElement.second]++;
        }
    }

    Pair interval(flattened[0].first, (*flattened.rbegin()).first);
    int l = 0;
    Window window;
    for(int r = 0; r < flattened.size(); ++r)
    {
        window.increment(flattened[r].second, 1);

        while(window.size() >= K)
        {
            int currIntervalLen = flattened[r].first - flattened[l].first;
            if(currIntervalLen < interval.second-interval.first)
                interval = Pair(flattened[l].first, flattened[r].first);

            window.decrement(flattened[l].second, 1);
            l++;
        }
    }

    return {interval.first, interval.second};
}