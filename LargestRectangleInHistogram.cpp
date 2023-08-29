/*[2,1,5,6,2,3],[(0,0),(1,4),(0,1),(0,0),(2,1),(0,)]
1,0

[2,4],[(0,1),(0,0)]*/

#include<bits/stdc++.h>

using namespace std;
int largestRectangleArea(vector<int>& heights);

int main()
{
    vector<int> heights = {9,9,11};
    cout << largestRectangleArea(heights);  

    getchar();
    return 0;
}

int largestRectangleArea(vector<int>& heights) 
{
    int** widths = new int*[heights.size()];
    for(int i = 0; i < heights.size(); ++i)
    {
        widths[i] = new int[2]();
    }

    stack<int> toProcess;
    toProcess.push(0);

    for(int i = 1; i < heights.size(); ++i)
    {
        while(toProcess.size() && heights[toProcess.top()] >= heights[i])
        {
            widths[i][0] = i - toProcess.top() + widths[toProcess.top()][0];
            toProcess.pop(); 
        }
        toProcess.push(i);
    }

    toProcess = stack<int>();
    toProcess.push(heights.size()-1);
    for(int i = heights.size()-2; i >= 0; --i)
    {
        while(toProcess.size() && heights[toProcess.top()] >= heights[i])
        {
            widths[i][1] = toProcess.top() - i + widths[toProcess.top()][1];
            toProcess.pop();
        }
        toProcess.push(i);
    }

    int maxArea = 0;
    for(int i = 0; i < heights.size(); ++i)
    {
        maxArea = max(maxArea, heights[i] * (widths[i][0] + widths[i][1] + 1));
    }

    for(int i = 0; i < heights.size(); ++i)
    {
        delete[] widths[i];
    }
    delete[] widths;

    return maxArea;   
}