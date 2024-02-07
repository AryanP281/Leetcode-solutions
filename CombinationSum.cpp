
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> combinationSum(vector<int>& candidates, int target);
unordered_set<string>* generateCombinations(vector<int>& arr, int target, unordered_set<string>** dp);

int main()
{
    vector<int> candidates = {2};
    combinationSum(candidates, 1);

    getchar();
    return 0;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
{
    unordered_set<string>** dp = new unordered_set<string>*[target+1];
    for(int i = 0; i <= target; ++i)
    {
        dp[i] = nullptr;
    }

    unordered_set<string>* combs = generateCombinations(candidates, target, dp);
    vector<vector<int>> res;
    for(unordered_set<string>::iterator itr = combs->begin(); itr != combs->end(); ++itr)
    {
        int* elemCts = new int[candidates.size()]();

        string val = "";
        int idx = 0;
        for(int j = 0; j < itr->size(); ++j)
        {
            if(itr->operator[](j) == '-')
            {
                elemCts[idx++] += stoi(val); 
                val = "";
            }
            else
                val += itr->operator[](j);
        }

        res.push_back(vector<int>());
        for(int i = 0; i < candidates.size(); ++i)
        {
            for(int j = 0; j < elemCts[i]; ++j)
            {
                res[res.size()-1].push_back(candidates[i]);
            }
        }

        delete[] elemCts;
    }

    for(int i = 0; i <= target; ++i)
    {
        if(dp[i] != nullptr)
            delete dp[i];
    }
    delete[] dp;

    return res;
}

unordered_set<string>* generateCombinations(vector<int>& arr, int target, unordered_set<string>** dp)
{
    if(dp[target])
        return dp[target];
    if(target == 0)
    {
        string combStr = "";
        for(int i = 0; i < arr.size(); ++i)
        {
            combStr += "0-";
        }

        dp[0] = new unordered_set<string>();
        dp[0]->insert(combStr);

        return dp[0];
    }

    dp[target] = new unordered_set<string>();
    for(int i = 0; i < arr.size(); ++i)
    {
        if(arr[i] > target)
            continue;

        unordered_set<string>* combs = generateCombinations(arr, target - arr[i], dp);
        for(unordered_set<string>::iterator itr = combs->begin(); itr != combs->end(); ++itr)
        {   
            int* elemCts = new int[arr.size()]();
            elemCts[i] = 1;

            string val = "";
            int idx = 0;
            for(int j = 0; j < itr->size(); ++j)
            {
                if(itr->operator[](j) == '-')
                {
                    elemCts[idx++] += stoi(val); 
                    val = "";
                }
                else
                    val += itr->operator[](j);
            }

            string combStr = "";
            for(int j = 0; j < arr.size(); ++j)
            {
                combStr += (to_string(elemCts[j]) + '-');
            } 
            dp[target]->insert(combStr);  

            delete[] elemCts;
        }
    }

    return dp[target];
} 
