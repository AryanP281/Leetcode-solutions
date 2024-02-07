
#include<bits/stdc++.h>

using namespace std;

class DisjointSet
{
private:
    unordered_map<int,int> setRoots;
    unordered_map<int,int> setRanks;

    int findSetRoot(int elem)
    {
        unordered_map<int,int>::iterator itr = setRoots.find(elem);

        int root;
        if(itr->second != elem)
        {
            root = findSetRoot(itr->second);
            setRoots[elem] = root;
        }
        else
            root = elem;

        return root;
    }
public:
    DisjointSet(vector<int>& elems)
    {
        for(int i = 0; i < elems.size(); ++i)
        {
            setRoots[elems[i]] = elems[i];
            setRanks[elems[i]] = 0;
        }
    }

    int getSetRoot(int elem)
    {
        int root = findSetRoot(elem);
        setRanks[root] = 1;

        return root;
    }

    void mergeSets(int root1, int root2)
    {
        int rank1 = setRanks[root1];
        int rank2 = setRanks[root2];

        if(rank1 < rank2)
            setRoots[root1] = root2;
        else if(rank1 > rank2)
            setRoots[root2] = root1;
        else
        {
            setRoots[root1] = root2;
            setRanks[root2] += 1;
        }
    }

    int getSetsCount()
    {
        int setsCount = 0;
        for(unordered_map<int,int>::iterator itr = setRoots.begin(); itr != setRoots.end(); ++itr)
        {
            setsCount += 1*(itr->first == itr->second);
        }

        return setsCount;
    }
};

int numIslands(vector<vector<char>>& grid);

int main()
{
    vector<vector<char>> grid = {
    {'1','1','1','1','0'},
    {'1','1','0','1','0'},
    {'1','1','0','0','0'},
    {'0','0','0','0','0'}
    };

    cout << numIslands(grid);

    getchar();
    return 0;
}

int numIslands(vector<vector<char>>& grid) 
{
    vector<int> land;
    for(int r = 0; r < grid.size(); ++r)
    {
        for(int c = 0; c < grid[r].size(); ++c)
        {
            if(grid[r][c] == '1')
                land.push_back((r*grid[r].size()) + c);
        }
    }
    DisjointSet djs(land);

    const int NEIGHBOURS[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    for(int r = 0; r < grid.size(); ++r)
    {
        for(int c = 0; c < grid[r].size(); ++c)
        {
            if(grid[r][c] == '0')
                continue;
            
            for(int n = 0; n < 4; ++n)
            {
                int nR = r + NEIGHBOURS[n][0];
                int nC = c + NEIGHBOURS[n][1];
                if(nR >= 0 && nR < grid.size() && nC >= 0 && nC < grid[r].size())
                {
                    if(grid[nR][nC] == '1')
                    {   
                        int currIndex = r*grid[r].size() + c;
                        int currRoot = djs.getSetRoot(currIndex);

                        int nIndex = nR*grid[r].size() + nC;
                        int nRoot = djs.getSetRoot(nIndex);

                        if(currRoot != nRoot)
                            djs.mergeSets(currRoot, nRoot);
                    }
                }
            }
        }
    }

    return djs.getSetsCount();
}

