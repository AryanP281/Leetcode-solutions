
#include<bits/stdc++.h>

using namespace std;

int largestSubmatrix(vector<vector<int>>& matrix);

int main()
{
    //vector<vector<int>> matrix = {{0,0,1},{1,1,1},{1,0,1}};
    //vector<vector<int>> matrix = {{1,0,1,0,1}};
    //vector<vector<int>> matrix = {{1,1,0}, {1,0,1}};
    vector<vector<int>> matrix = {{0,0}, {0,0}};
    cout << largestSubmatrix(matrix);

    getchar();
    return 0;
}

int largestSubmatrix(vector<vector<int>>& matrix) 
{
    int** cumSums = new int*[matrix.size()];
    for(int a = 0; a < matrix.size(); ++a)
    {
        cumSums[a] = new int[matrix[a].size()]();
    }
    for(int c = 0; c < matrix[0].size(); ++c)
    {
        cumSums[matrix.size()-1][c] = 1*(matrix.rbegin()->operator[](c) == 1);
        for(int r = matrix.size()-2; r >= 0; --r)
        {
            cumSums[r][c] = (1+cumSums[r+1][c])*(matrix[r][c] == 1);
        }
    }

    int maxArea = 0;
    int currArea;
    for(int r = 0; r < matrix.size(); ++r)
    {
        sort(cumSums[r], cumSums[r]+matrix[r].size());
        for(int c = matrix[r].size()-2; c >= 0 && cumSums[r][c+1] > 0; --c)
        {
            if(cumSums[r][c] != cumSums[r][c+1])
            {
                currArea = cumSums[r][c+1]*(matrix[r].size() - (c+1));
                if(currArea > maxArea)
                    maxArea = currArea;
            }
        }
        currArea = cumSums[r][0]*(matrix[r].size());
        if(currArea > maxArea)
            maxArea = currArea;
    }

    return maxArea;
}