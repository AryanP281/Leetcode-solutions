
#include<bits/stdc++.h>

using namespace std;

int* getClusters(bool** adjMatrix);
bool equationsPossible(vector<string>& equations);

int main()
{
    vector<string> equations = {"c==c","b==d","x!=z"};
    cout << equationsPossible(equations);

    getchar();
    return 0;
}

bool equationsPossible(vector<string>& equations) 
{
    bool** adjMatrix = new bool*[26];
    for(int r = 0; r < 26; ++r)
    {
        adjMatrix[r] = new bool[26]();
    }
    
    for(int i = 0; i < equations.size(); ++i)
    {
        if(equations[i][1] == '=')
        {
            adjMatrix[equations[i][0] - 'a'][equations[i][3] - 'a'] = true;
            adjMatrix[equations[i][3] - 'a'][equations[i][0] - 'a'] = true;
        }
    }

    int* clusters = getClusters(adjMatrix);
    for(int i = 0; i < equations.size(); ++i)
    {
        if(equations[i][1] == '!' && clusters[equations[i][0] - 'a'] == clusters[equations[i][3] - 'a'])
            return false;
    }

    delete[] clusters;
    for(int r = 0; r < 26; ++r)
    {
        delete[] adjMatrix[r];
    }
    delete[] adjMatrix;

    return true;
}

int* getClusters(bool** adjMatrix)
{
    int* clusterIds = new int[26];
    fill_n(clusterIds, 26, -1);

    bool* visited = new bool[26]();
    int currCluster = 0;
    for(int i = 0; i < 26; ++i)
    {
        if(visited[i])
            continue;

        stack<int> dfsStack;
        dfsStack.push(i);
        visited[i] = true;
        while(!dfsStack.empty())
        {
            int currNode = dfsStack.top();
            dfsStack.pop();
            clusterIds[currNode] = currCluster;
            
            for(int j = 0; j < 26; ++j)
            {
                if(adjMatrix[currNode][j] && !visited[j])
                {
                    visited[j] = true;
                    dfsStack.push(j);
                }
            }
        }
        currCluster++;
    }

    delete[] visited;

    return clusterIds;
}