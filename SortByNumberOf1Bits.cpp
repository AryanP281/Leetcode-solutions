/*
#include<iostream>
#include<vector>
#include<random>
#include<time.h>

using namespace std;

class Solution
{
private:
    int* bitCounts;
    int getMax(vector<int>::iterator start, vector<int>::iterator end)
    {
        int maxE = INT_MIN;
        for (vector<int>::iterator curr = start; curr != end; ++curr)
        {
            maxE = max(*curr, maxE);
        }

        return maxE;
    }

    void getBits(int n)
    {
        bitCounts[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            bitCounts[i] = bitCounts[i & (i - 1)] + 1;
        }
    }

public:
    Solution() {}

    vector<int> sortByBits(vector<int>& arr)
    {
        int maxVal = getMax(arr.begin(), arr.end());
        bitCounts = new int[maxVal+1];
        getBits(maxVal);

        int* bitCountsRef = bitCounts;
        sort(arr.begin(), arr.end(),
            [bitCountsRef](int i, int j)->bool
            {
                if (bitCountsRef[i] < bitCountsRef[j]) return true;
                else if (bitCountsRef[i] == bitCountsRef[j]) return i < j;

                return false;
            });

        delete[] bitCounts;

        return arr;
    }
};

void main()
{
    Solution sol;

    int arrVals[9] = { 0,1,2,3,4,5,6,7,8 };

    vector<int> arr(arrVals, arrVals + 9);
    vector<int> sorted = sol.sortByBits(arr);
}
*/