/*
#include <iostream>
#include <vector>

using namespace std;

void main()
{
	
}

vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries)
{
	int* xors = new int[arr.size()];
	xors[0] = arr[0];
	for (int a = 1; a < arr.size(); ++a)
	{
		xors[a] = xors[a - 1] ^ arr[a];
	}

	vector<int> queryRes;
	for (int a = 0; a < queries.size(); ++a)
	{
		if (queries[a][0] != 0)
			queryRes.push_back(xors[queries[a][1]] ^ xors[queries[a][0] - 1]);
		else queryRes.push_back(xors[queries[a][1]]);
	}

	delete[] xors;

	return queryRes;
}
*/