
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Vec;

struct HeapCompare
{
    bool operator()(vector<int>& tree1, vector<int>& tree2) const
    {
        return tree1[0] > tree2[0];
    }
};

int cutOffTree(vector<vector<int>>& forest);
int getMinSteps(Vec& start, Vec& end, vector<vector<int>>& forest);

int main()
{
    

    getchar();

    return 0;
}

int cutOffTree(vector<vector<int>>& forest) 
{
    priority_queue<vector<int>, vector<vector<int>>, struct HeapCompare> treeHeap;

    for(int r = 0; r < forest.size(); ++r)
    {
        for(int c = 0; c < forest[r].size(); ++c)
        {
            if(forest[r][c] > 1)
                treeHeap.push({forest[r][c], r, c});
        }
    }

    Vec currPos(0,0);
    int stepsCount = 0;
    while(!treeHeap.empty())
    {
        vector<int> nextTree = treeHeap.top();
        treeHeap.pop();

        Vec endPos(nextTree[1], nextTree[2]);
        int newSteps = getMinSteps(currPos, endPos, forest);
        if(newSteps == -1)
        {
            stepsCount = -1;
            break;
        }

        stepsCount += newSteps;
        currPos = endPos;
    }

    return stepsCount;
}

int getMinSteps(Vec& start, Vec& end, vector<vector<int>>& forest)
{
    const vector<int> DIRS[] = {{-1,0},{0,1},{1,0},{0,-1}};
    vector<vector<bool>> visited(forest.size(), vector<bool>(forest[0].size(), false));

    queue<Vec>* currLevel = new queue<Vec>();
    queue<Vec>* nextLevel = new queue<Vec>();

    currLevel->push(start);
    visited[start.first][start.second] = true;

    int stepsCount = 0;
    while(!visited[end.first][end.second] && !currLevel->empty())
    {
        while(!visited[end.first][end.second] && !currLevel->empty())
        {
            Vec currPos = currLevel->front();
            currLevel->pop();

            for(const vector<int>& dir : DIRS)
            {
                int nR = currPos.first + dir[0];
                int nC = currPos.second + dir[1];

                if(nR >= 0 && nR < forest.size() && nC >= 0 && nC < forest[nR].size())
                {
                    if(!visited[nR][nC] && forest[nR][nC] > 0)
                    {
                        visited[nR][nC] = true;
                        nextLevel->push(Vec(nR,nC));
                    }
                }
            }
        }

        currLevel = nextLevel;
        nextLevel = new queue<Vec>();
        stepsCount++;
    }

    delete currLevel;
    delete nextLevel;
    
    if(!visited[end.first][end.second])
        return -1;
    
    return stepsCount;
}
