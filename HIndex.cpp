/*
#include <iostream>
#include <vector>
#include<map>
#include<algorithm>

using namespace std;

int hIndex(vector<int>& citations);

void main()
{
    int vals[5] = { 3,0,6,1,5 };
    vector<int> citations(vals, vals + 5);

    cout << hIndex(citations);
}

int hIndex(vector<int>& citations)
{
    sort(citations.begin(), citations.end());
    int* citationCounts = new int[citations[citations.size() - 1] + 1]{ 0 };
    for (int a = citations.size() - 1; a >= 0; --a)
    {
        int cit = citations[a];
        for (int b = 0; b <= cit; ++b)
        {
            citationCounts[b]++;
        }
    }
    
    int hi = 0;
    for (int a = citations[citations.size() - 1]; a >= 0; --a)
    {
        if (citationCounts[a] >= a)
        {
            hi = a;
            break;
        }
    }

    delete[] citationCounts;

    return hi;
}*/