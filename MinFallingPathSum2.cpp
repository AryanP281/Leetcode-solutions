
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Vec;

int minFallingPathSum(vector<vector<int>>& arr);

int main()
{

    vector<vector<int>> arr = {{50,-18,-38,39,-20,-37,-61,72,22,79},
    {82,26,30,-96,-1,28,87,94,34,-89},
    {55,-50,20,76,-50,59,-58,85,83,-83},
    {39,65,-68,89,-62,-53,74,2,-70,-90},
    {1,57,-70,83,-91,-32,-13,49,-11,58},
    {-55,83,60,-12,-90,-37,-36,-27,-19,-6},
    {76,-53,78,90,70,62,-81,-94,-32,-57},
    {-32,-85,81,25,80,90,-24,10,27,-55},
    {39,54,39,34,-45,17,-2,-61,-81,85},
    {-77,65,76,92,21,68,78,-13,39,22}} ;
    cout << minFallingPathSum(arr);

    getchar();
    return 0;
}

int minFallingPathSum(vector<vector<int>>& arr) 
{
    Vec min1(-1,INT_MAX), min2(-1, INT_MAX);

    for(int c = 0; c < arr.size(); ++c)
    {
        if(arr[0][c] < min1.second)
        {
            min2 = min1;
            min1 = Vec(c,arr[0][c]);
        }
        else if(arr[0][c] < min2.second)
            min2 = Vec(c,arr[0][c]);
    }

    Vec newMin1, newMin2;
    int currSum;
    for(int r = 1; r < arr.size(); ++r)
    {
        newMin1 = Vec(-1,INT_MAX);
        newMin2 = Vec(-1, INT_MAX);
        for(int c = 0; c < arr.size(); ++c)
        {
            currSum = (arr[r][c] + min1.second)*(c != min1.first) + (arr[r][c] + min2.second)*(c == min1.first);
            if(currSum < newMin1.second)
            {
                newMin2 = newMin1;
                newMin1 = Vec(c, currSum);
            }
            else if(currSum < newMin2.second)
                newMin2 = Vec(c, currSum);
        }

        min1 = newMin1;
        min2 = newMin2;
    }

    return min1.second;
}