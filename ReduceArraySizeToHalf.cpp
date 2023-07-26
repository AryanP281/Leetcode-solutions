/*
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int minSetSize(vector<int>& arr);

void main()
{
	int vals[46] = { 2,28,92,30,100,52,28,48,91,27,66,19,11,53,91,95,74,51,65,65,96,81,21,55,98,3,2,89,99,57,78,34,50,2,57,76,23,90,89,36,53,22,73,59,95,45 };
	//int vals[6] = { 7,7,7,7,7,7 };
	vector<int> arr(vals, vals + 46);

	cout << minSetSize(arr);
}

int minSetSize(vector<int>& arr) 
{
	unordered_map<int, int> counts;
	for (int a = 0; a < arr.size(); ++a)
	{
		unordered_map<int, int>::iterator itr = counts.find(arr[a]);
		if (itr == counts.end())
			counts.insert(pair<int, int>(arr[a], 1));
		else
			itr->second++;
	}

	vector<pair<int, int>> sortedCounts(counts.begin(), counts.end());
	sort(sortedCounts.begin(), sortedCounts.end(), [](pair<int, int>& i, pair<int, int>& j) -> bool
		{
			return (i.second > j.second);
		}
	);

	int i = 0;
	int a = 0;
	for (; a < sortedCounts.size() && i < (arr.size() / 2); ++a)
	{
		i += sortedCounts[a].second;
	}

	return a;
}
*/