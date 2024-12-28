
#include<bits/stdc++.h>

using namespace std;

bool isPathCrossing(string path);

int main()
{
    string path = "NESWW";
    cout << isPathCrossing(path);

    getchar();
    return 0;
}

bool isPathCrossing(string path) 
{
    
    int currPos[2] = {0,0};
    unordered_map<int,unordered_set<int>> visited;
    visited[0].insert(0);

    for(int i = 0; i < path.size(); ++i)
    {
        switch(path[i])
        {
            case 'N': currPos[0] += 1; break;
            case 'S': currPos[0] -= 1; break;
            case 'E': currPos[1] += 1; break;
            case 'W': currPos[1] -= 1; break;
        }
        unordered_map<int,unordered_set<int>>::iterator itr = visited.find(currPos[0]);
        if(itr != visited.end() && itr->second.count(currPos[1]))
            return true;
        else if(itr != visited.end())
            itr->second.insert(currPos[1]);
        else
            visited[currPos[0]] = {currPos[1]};
    }

    return false;
}