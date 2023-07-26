
#include<bits/stdc++.h>

using namespace std;

vector<int> canSeePersonsCount(vector<int>& heights);

int main()
{

    vector<int> heights = {5,1,2,3,10};
    vector<int> res = canSeePersonsCount(heights);

    for(int a = 0; a < res.size(); ++a)
    {
        cout << res[a] << ',' << ' ';
    }

    getchar();
    return 0;
}

vector<int> canSeePersonsCount(vector<int>& heights) 
{
    vector<int> visiblePeople(heights.size(), 0);
    stack<int> peopleStack;

    peopleStack.push(0);
    for(int i = 1; i < heights.size(); ++i)
    {
        while(!peopleStack.empty() && heights[peopleStack.top()] <= heights[i])
        {
            visiblePeople[peopleStack.top()]++;
            peopleStack.pop();
        }
        if(!peopleStack.empty())
            visiblePeople[peopleStack.top()]++;

        peopleStack.push(i);
    }

    return visiblePeople;
}