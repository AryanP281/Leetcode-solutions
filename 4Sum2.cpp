
#include<bits/stdc++.h>

using namespace std;

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D);

int main()
{
    vector<int> A = {-1,1,1,1,-1};
    vector<int> B = {0,-1,-1,0,1};
    vector<int> C = {-1,-1,1,-1,-1};
    vector<int> D = {0,1,0,-1,-1};

    cout << fourSumCount(A,B,C,D);

    getchar();
    return 0;
}

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) 
{
    vector<int> sums;
    unordered_map<int,int> diffs;
    unordered_map<int,int>::iterator itr;

    for(int r = 0; r < A.size(); ++r)
    {
        for(int c = 0; c < B.size(); ++c)
        {
            sums.push_back(A[r] + B[c]);
            
            itr = diffs.find(-(C[r] + D[c]));
            if(itr != diffs.end())
                itr->second++;
            else
                diffs[-(C[r] + D[c])] = 1;
        }
    }

    int tuples = 0;
    for(int a = 0; a < sums.size(); ++a)
    {
        itr = diffs.find(sums[a]);
        if(itr != diffs.end()) tuples += itr->second;
    }

    return tuples;
}

/*
vector<int> sums;
    unordered_map<int,int> diffs;
    unordered_map<int,int>::iterator itr;

    for(int r = 0; r < A.size(); ++r)
    {
        for(int c = 0; c < B.size(); ++c)
        {
            sums.push_back(A[r] + B[c]);
            
            itr = diffs.find(-(C[r] + D[c]));
            if(itr != diffs.end())
                itr->second++;
            else
                diffs[-(C[r] + D[c])] = 1;
        }
    }

    int tuples = 0;
    for(int a = 0; a < sums.size(); ++a)
    {
        itr = diffs.find(-sums[a]);
        if(itr != diffs.end()) tuples += itr->second;
    }

    return tuples;
*/