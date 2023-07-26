
#include<bits/stdc++.h>

using namespace std;

int largestRectangleArea(vector<int>& heights);

int main()
{
    vector<int> heights = {4,3,2,1,7};
    cout << largestRectangleArea(heights);

    getchar();
    return 0;
}

int largestRectangleArea(vector<int>& heights) 
{
    int maxArea = 0;

    stack<int> rectStack;
    rectStack.push(0);

    int currRect, currArea;
    int l;
    for(int i = 1; i < heights.size(); ++i)
    {
        while(!rectStack.empty() && heights[rectStack.top()] >= heights[i])
        {
            currRect = rectStack.top();
            rectStack.pop();

            l = (rectStack.empty() ? 0 : rectStack.top()+1);
            currArea = heights[currRect]*(i-l);
            if(currArea > maxArea)
                maxArea = currArea;
        }
        rectStack.push(i);
    }

    int r = heights.size();
    while(!rectStack.empty())
    {
        currRect = rectStack.top();
        rectStack.pop();

        l = (rectStack.empty() ? 0 : rectStack.top()+1);
        currArea = heights[currRect]*(r-l);
        if(currArea > maxArea)
            maxArea = currArea;
    }

    return maxArea;
}