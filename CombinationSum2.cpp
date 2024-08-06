#include<bits/stdc++.h>

using namespace std;

int main()
{

    getchar();
    return 0;
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
{
    sort(candidates.begin(), candidates.end());

    vector<vector<int>> combinations;
    vector<int> currCombo;
    generateSums(0,currCombo,0,candidates,target,combinations);

    return combinations;
}

void generateSums(int i, vector<int>& currCombo, int currSum, vector<int>& candi, int target, vector<vector<int>>& combos)
{
    if(i >= candi.size())
        return;

    for(int j = i; j < candi.size(); ++j)
    {
        if(j != 0 && candi[j] == candi[j-1])
            continue;

        currSum += candi[j];
        currCombo.push_back(candi[j]);

        if(currSum == target)
        {
            combos.push_back(currCombo);
            currCombo.pop_back();
            break;
        }
        else if(currSum > target)
        {
            currCombo.pop_back();
            break;
        }
            
        generateSums(j+1,currCombo,currSum,candi,target,combos);
        currSum -= candi[j];
        currCombo.pop_back();
    }
}