
/*
,(2,0),(8,0),(8,4),(8,13),(10,13)

,(6,0),(12,0),(20,0)

[8,50,65,85,8,73,55,50,29,95,5,68,52,79],74 -- 470

8,(58,0),(58,49),(58,134),(68,134),(68,207),(68,262),(238,262),(238,291),(238,386),(238,391),(385,391),(437,391),(437,470)
*/

#include<bits/stdc++.h>

using namespace std;

long long maxScore(vector<int>& nums, int x);

int main()
{
    vector<int> nums = {8,50,65,85,8,73,55,50,29,95,5,68,52,79};
    cout << maxScore(nums, 74);

    getchar();
    return 0;
}

long long maxScore(vector<int>& nums, int x) 
{
    int64_t* prevBestScores = new int64_t[2]();
    int64_t* currBestScores = new int64_t[2]();

    prevBestScores[nums[0] % 2] = nums[0];
    prevBestScores[1 - (nums[0] % 2)] = -x;

    int64_t maxPossibleScore = nums[0];
    for(int i = 1; i < nums.size(); ++i)
    {
        currBestScores[1 - (nums[i] % 2)] = prevBestScores[1 - (nums[i] % 2)];
        currBestScores[nums[i] % 2] = max(prevBestScores[nums[i] % 2] + nums[i], prevBestScores[1 - (nums[i] % 2)] + nums[i] - x);

        maxPossibleScore = max(maxPossibleScore, max(currBestScores[0], currBestScores[1]));

        delete[] prevBestScores;
        prevBestScores = currBestScores;
        currBestScores = new int64_t[2]();
    }

    delete[] prevBestScores;
    delete[] currBestScores;

    return maxPossibleScore;
}