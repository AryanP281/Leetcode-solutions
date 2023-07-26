
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Vec2D;

class Compare
{
public :
    bool operator()(Vec2D& v1, Vec2D& v2)
    {
        return v1.second > v2.second;
    }
};

const int NEIGHBOUR_VECS[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};

int swimInWater(vector<vector<int>>& grid);
int** getNeighbours(int n, int pos);

int main()
{
    //vector<vector<int>> grid = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
    vector<vector<int>> grid = {{3,2},{0,1}};
    cout << swimInWater(grid);

    getchar();
    return 0;
}

int swimInWater(vector<vector<int>>& grid) 
{
    auto releaseMatrixMem = [](int** mtrx, int n) -> void
    {
        n--;
        while(n >= 0)
        {
            delete[] mtrx[n];
            n--;
        }
        delete[] mtrx;
    };
    
    int n = grid.size();

    int* minBottlenecks = new int[n*n];
    fill_n(minBottlenecks,n*n,INT_MAX);
    minBottlenecks[0] = grid[0][0];

    priority_queue<Vec2D,vector<Vec2D>,Compare> nodes;
    nodes.push(Vec2D(0,grid[0][0]));
    while(!nodes.empty())
    {
        Vec2D node = nodes.top();
        nodes.pop();

        if(minBottlenecks[node.first] < node.second) continue;
        
        int** neighbours = getNeighbours(n,node.first);
        for(int i = 0; i < 4 && neighbours[i][0] != -1; ++i)
        {
            int pos = (neighbours[i][0] * n) + neighbours[i][1];
            int newNeighbourBottleneck = max(node.second, grid[neighbours[i][0]][neighbours[i][1]]);
            if(newNeighbourBottleneck < minBottlenecks[pos])
            {
                minBottlenecks[pos] = newNeighbourBottleneck;
                nodes.push(Vec2D(pos,newNeighbourBottleneck));
            }
        }
        releaseMatrixMem(neighbours,4);
    }

    int bottleneck = minBottlenecks[(n*n)-1];
    delete[] minBottlenecks;

    return bottleneck;
}

int** getNeighbours(int n, int pos)
{
    int** neighbours = new int*[4];
    for(int a = 0; a < 4; ++a)
    {
        neighbours[a] = new int[2];
        neighbours[a][0] = -1;
        neighbours[a][1] = -1;
    }
    int i = 0;

    int coords[2] = {pos/n,pos%n};
    for(int a = 0; a < 4; ++a)
    {
        int neighbourCoords[2] = {coords[0]+NEIGHBOUR_VECS[a][0], coords[1]+NEIGHBOUR_VECS[a][1]};
        if(neighbourCoords[0] >= 0 && neighbourCoords[0] < n && neighbourCoords[1] >= 0 && neighbourCoords[1] < n)
        {
            neighbours[i][0] = neighbourCoords[0];
            neighbours[i][1] = neighbourCoords[1];
            ++i;
        }
    }

    return neighbours;
}