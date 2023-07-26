
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Vec2D;;

class Compare
{
public :
    bool operator()(Vec2D& i1, Vec2D& i2)
    {
        return i1.first < i2.first;
    }
};

int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit);

int main()
{
    vector<int> values = {9,8,8,7,6};
    vector<int> labels = {0,0,0,1,1};

    cout << largestValsFromLabels(values, labels, 3, 2);

    getchar();
    return 0;
}

int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) 
{
    priority_queue<Vec2D, vector<Vec2D>, Compare> items;
    for(int a = 0; a < values.size(); ++a)
    {
        items.push(Vec2D(values[a], labels[a]));
    }

    int currSum = 0;
    int currCount = 0;
    unordered_map<int,int> itemCounts;
    unordered_map<int,int>::iterator itr;
    while(!items.empty() && currCount != num_wanted)
    {
        itr = itemCounts.find(items.top().second);
        if(itr == itemCounts.end())
        {
            currSum += items.top().first;
            itemCounts[items.top().second] = 1;
            currCount++;
        }
        else if(itr->second < use_limit)
        {
            currSum += items.top().first;
            itr->second += 1;
            currCount++;
        }
        
        items.pop();
    }


    return currSum;
}