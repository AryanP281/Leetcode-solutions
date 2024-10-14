
#include<bits/stdc++.h>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix);

int main()
{

    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    spiralOrder(matrix);

    getchar();
    return 0;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
    const int DIRS[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int limits[2][2] = {{0,matrix.size()-1}, {0, matrix[0].size()-1}};

    vector<int> result;
    int r = 0;
    int c = -1;
    while(result.size() != matrix.size()*matrix[0].size())
    {
        for(int i = 0; i < 4; ++i)
        {
            r += DIRS[i][0]; 
            c += DIRS[i][1];
            
            if(r >= limits[0][0] && r <= limits[0][1] && c >= limits[1][0] && c <= limits[1][1])
            {
                while(r >= limits[0][0] && r <= limits[0][1] && c >= limits[1][0] && c <= limits[1][1])
                {
                    result.push_back(matrix[r][c]);
                    r += DIRS[i][0];
                    c += DIRS[i][1];
                }

                if(r < limits[0][0])
                    r++;
                else if(r > limits[0][1])
                    r--;

                if(c < limits[1][0])
                    c++;
                else if(c > limits[1][1])
                    c--;

                if(DIRS[i][1] > 0)
                    limits[0][0] += 1;
                else if(DIRS[i][1] < 0)
                    limits[0][1] -= 1;

                if(DIRS[i][0] > 0)
                    limits[1][1] -= 1;
                else if(DIRS[i][0] < 0)
                    limits[1][0] += 1;
            }
            
        }
    }

    return result;
}