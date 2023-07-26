
#include<bits/stdc++.h>

using namespace std;

int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target);

int main()
{
    vector<vector<int>> matrix = {{0,1,1,1,0,1},{0,0,0,0,0,1},{0,0,1,0,0,1},{1,1,0,1,1,0},{1,0,0,1,0,0}};
    cout << numSubmatrixSumTarget(matrix,0);
    getchar();
    return 0;
}

int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) 
{
    vector<vector<int>> cumSums(matrix.size(), vector<int>(matrix[0].size(),0));
    int submatricesCount = 0;
    unordered_map<int,int> sums;
    unordered_map<int,int>::iterator itr;
    for(int r = 0; r < matrix.size(); ++r)
    {
        cumSums[r][0] = matrix[r][0];
        sums[0] = 1;
        sums[matrix[r][0]]++;
        submatricesCount += 1*(matrix[r][0] == target);
        for(int c = 1; c < matrix[r].size(); ++c)
        {
            cumSums[r][c] = cumSums[r][c-1] + matrix[r][c];
            itr = sums.find(cumSums[r][c] - target);
            if(itr != sums.end())
                submatricesCount += itr->second;
            sums[cumSums[r][c]]++;
        }
        sums.clear();
    }

    vector<int>* prevRowCumSum, *currRowCumSums;
    for(int rStart = 0; rStart < matrix.size()-1; ++rStart)
    {
        prevRowCumSum = &cumSums[rStart];
        currRowCumSums = new vector<int>();
        for(int r = rStart+1; r < matrix.size(); ++r)
        {
            sums[0] = 1;
            for(int c = 0; c < matrix[r].size(); ++c)
            {
                currRowCumSums->push_back(cumSums[r][c] + prevRowCumSum->at(c));
                itr = sums.find(*(currRowCumSums->rbegin()) - target);
                if(itr != sums.end())
                    submatricesCount += itr->second;
                sums[*(currRowCumSums->rbegin())]++;
            }
            sums.clear();
            if(prevRowCumSum != &cumSums[rStart])
                delete prevRowCumSum;
            prevRowCumSum = currRowCumSums;
            currRowCumSums = new vector<int>();
        }

        delete currRowCumSums;
    }

    return submatricesCount;
}