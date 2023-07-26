
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> permute(vector<int>& nums);
void generatePermutations(vector<int>& currPermutation, queue<int>& availableNums, vector<vector<int>>& permutations, int maxSize);

int main()
{
    vector<int> nums = {1};
    vector<vector<int>> permutations = permute(nums);
    for(int a = 0; a < permutations.size(); ++a)
    {
        for(int b = 0; b < permutations[a].size(); ++b)
        {
            cout << permutations[a][b] << ' ';
        }
        cout << '\n';
    }

    getchar();
    return 0;
}

vector<vector<int>> permute(vector<int>& nums) 
{
    int fac = nums.size();
    for(int a = fac-1; a >= 1; --a)
    {
        fac *= a;
    }
    
    vector<vector<int>> permutations;   
    permutations.reserve(fac);

    queue<int> availableNums;
    for(int a = 0; a < nums.size(); ++a)
    {
        availableNums.push(nums[a]);
    }

    vector<int> currPermutation;
    generatePermutations(currPermutation, availableNums, permutations, nums.size());

    return permutations;
}

void generatePermutations(vector<int>& currPermutation, queue<int>& availableNums, vector<vector<int>>& permutations, int maxSize)
{
    if(currPermutation.size() == maxSize)
    {
        permutations.push_back(currPermutation);
        return;
    }

    int totalChoices = availableNums.size();
    int choice;
    for(int a = 0;a < totalChoices; ++a)
    {
        choice = availableNums.front();
        availableNums.pop();
        currPermutation.push_back(choice);
        generatePermutations(currPermutation, availableNums, permutations, maxSize);
        currPermutation.pop_back();
        availableNums.push(choice);
    }

}