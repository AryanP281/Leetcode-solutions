
#include<bits/stdc++.h>

using namespace std;

int minOperations(vector<int>& nums);

int main()
{
    vector<int> nums = {0};
    cout << minOperations(nums);

    getchar();
    return 0;
}

int minOperations(vector<int>& nums) 
{
    queue<int> oddNums;
    queue<int> evenNums;
    int zerosCount = 0;
    for(int a = 0; a < nums.size(); ++a)
    {
        if(nums[a] == 1) continue;
        if(nums[a] == 0) zerosCount++;
        else if(nums[a] % 2 == 0)
            evenNums.push(nums[a]);
        else
            oddNums.push(nums[a]);
    }

    int operationsReq = 0;
    while(!oddNums.empty() || !evenNums.empty())
    {
        int oddNum;
        while(!oddNums.empty())
        {
            oddNum = oddNums.front();
            oddNums.pop();
            evenNums.push(oddNum-1);
            ++operationsReq;
        }

        int evenNumsToProcess = evenNums.size();
        int newNum;
        while(evenNumsToProcess)
        {
            newNum = evenNums.front() / 2;
            evenNums.pop();
            if(newNum != 1)
            {
                if(newNum % 2 == 0)
                    evenNums.push(newNum);
                else
                    oddNums.push(newNum);
            }

            --evenNumsToProcess;
        }
        operationsReq++;
    }

    operationsReq += nums.size();
    operationsReq -= zerosCount;

    return max(0,operationsReq);
}