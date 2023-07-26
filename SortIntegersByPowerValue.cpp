/*
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

int getKth(int lo, int hi, int k);
int getPowerValue(int x, unordered_map<int,int>& cache);
bool cmp(pair<int, int>& i, pair<int, int>& j);

void main()
{
    cout << getKth(1, 1000, 777);
}

int getKth(int lo, int hi, int k)
{
    unordered_map<int, int> powerValsCache;
    vector<pair<int, int>> powerVals;
    for (int a = lo; a <= hi; ++a)
    {
        powerVals.push_back(pair<int, int>(a, getPowerValue(a, powerValsCache)));
    }

    sort(powerVals.begin(), powerVals.end(), cmp);

    return powerVals[k - 1].first;
}

int getPowerValue(int x, unordered_map<int,int>& cache)
{
    if (x == 1) return 0;

    unordered_map<int, int>::iterator itr = cache.find(x);

    if (itr != cache.end()) return itr->second;

    int powerVal;
    if (x % 2 == 0) powerVal = getPowerValue(x / 2, cache) + 1;
    else powerVal = getPowerValue((3 * x) + 1, cache) + 1;

    cache[x] = powerVal;

    return powerVal;
}

bool cmp(pair<int, int>& i, pair<int, int>& j)
{
    if (i.second < j.second) return true;
    else if (i.second == j.second) return i.first < j.first;

    return false;
}
*/