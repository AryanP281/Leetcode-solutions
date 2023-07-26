
#include<bits/stdc++.h>

using namespace std;

class DisjointSet
{
private :
    vector<int> parents;
    unordered_map<int,int> rootRanks;

    void compressPath(vector<int>& path, int root)
    {
        for(int a = 0; a < path.size(); ++a)
        {
            parents[path[a]] = root;
        }
    }

public :
    DisjointSet(int nodes)
    {
        for(int a = 0; a < nodes; ++a)
        {
            parents.push_back(a);
            rootRanks[a] = 0;
        }
    }

    int find(int node)
    {
        vector<int> path;
        path.reserve(parents.size());

        int currNode = node;
        while(parents[currNode] != currNode)
        {
            path.push_back(currNode);
            currNode = parents[currNode];
        }

        compressPath(path, currNode);

        return currNode;
    }

    void unionOp(int x, int y)
    {
        int xRoot = find(x);
        int yRoot = find(y);

        if(xRoot == yRoot)
            return;

        unordered_map<int,int>::iterator xRankItr = rootRanks.find(xRoot);
        unordered_map<int,int>::iterator yRankItr = rootRanks.find(yRoot); 

        if(xRankItr->second == yRankItr->second)
        {
            parents[xRoot] = yRoot;
            yRankItr->second++;
            rootRanks.erase(xRankItr);
        }
        else if(xRankItr->second > yRankItr->second)
        {
            parents[yRoot] = xRoot;
            rootRanks.erase(yRankItr);
        }
        else
        {
            parents[xRoot] = yRoot;
            rootRanks.erase(xRankItr);
        }
    }

    int getSetCounts() const
    {
        return rootRanks.size();
    }
};

struct Cell
{
    int north;
    int west;
    int south;
    int east;

    Cell()
    {
        north = west = south = east = -1;
    }
};

int regionsBySlashes(vector<string>& grid);

int main()
{

    vector<string> grid = {
                            " /",
                            "/ "

                            };
    
    cout << regionsBySlashes(grid);

    getchar();
    return 0;
}

int regionsBySlashes(vector<string>& grid) 
{
    int nodesCount = 4 + (6*(grid.size()-1)) + 2*((grid.size()-1)*(grid.size()-1));
    DisjointSet djs(nodesCount);

    Cell** gridCells = new Cell*[grid.size()];
    for(int r = 0; r < grid.size(); ++r)
    {
        gridCells[r] = new Cell[grid.size()];
    }
    int prevMax = -1;
    int currIndex;
    for(int r = 0; r < grid.size(); r++)
    {
        for(int c = 0; c < grid.size(); ++c)
        {
            currIndex = prevMax+1;

            if(gridCells[r][c].north == -1)
            {
                gridCells[r][c].north = currIndex;
                currIndex++;
            }

            if(gridCells[r][c].west == -1)
            {
                gridCells[r][c].west = currIndex;
                currIndex++;
            }

            if(gridCells[r][c].south == -1)
            {
                gridCells[r][c].south = currIndex;
                if(r != grid.size()-1)
                    gridCells[r+1][c].north = currIndex;
                currIndex++;
            }

            if(gridCells[r][c].east == -1)
            {
                gridCells[r][c].east = currIndex;
                if(c != grid.size()-1)
                    gridCells[r][c+1].west = currIndex;
            }

            prevMax = currIndex;
        }
    }

    for(int r = 0; r < grid.size(); ++r)
    {
        for(int c = 0; c < grid[r].size(); ++c)
        {
            switch(grid[r][c])
            {
                case ' ' : {
                    djs.unionOp(gridCells[r][c].north, gridCells[r][c].west);
                    djs.unionOp(gridCells[r][c].west,gridCells[r][c].south);
                    djs.unionOp(gridCells[r][c].south, gridCells[r][c].east);
                }; break;

                case '/' : {
                    djs.unionOp(gridCells[r][c].north, gridCells[r][c].west);
                    djs.unionOp(gridCells[r][c].south, gridCells[r][c].east);
                }; break;

                case '\\' : {
                    djs.unionOp(gridCells[r][c].north,gridCells[r][c].east);
                    djs.unionOp(gridCells[r][c].south,gridCells[r][c].west);
                };break;
            }
        }
    }

    for(int r = 0; r < grid.size(); ++r)
    {
        delete[] gridCells[r];
    }
    delete[] gridCells;

    return djs.getSetCounts();
}