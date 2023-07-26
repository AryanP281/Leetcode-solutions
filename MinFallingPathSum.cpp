/*
#include<iostream>
#include<vector>

using namespace std;

int minFallingPathSum(vector<vector<int>>& A);
int getMinPath(int* lookupTable, int index, vector<vector<int>>& mtrx);

void main()
{
	vector<vector<int>> mtrx = { {1,2,3}, {4,5,6}, {7,8,9} };

	cout << minFallingPathSum(mtrx);
}

int minFallingPathSum(vector<vector<int>>& A)
{
	int* lookupTable = new int[A.size() * A[0].size()];
	fill_n(lookupTable, (A.size()-1) * A[0].size(), INT_MAX);
	int r = A.size() - 1;
	for (int c = 0; c < A[r].size(); ++c)
	{
		lookupTable[(r * A[r].size()) + c] = A[r][c];
	}

	int minPath = INT_MAX;
	for (int c = 0; c < A[0].size(); ++c)
	{
		minPath = min(minPath, getMinPath(lookupTable, c, A));
	}

	delete[] lookupTable;

	return minPath;
}

int getMinPath(int* lookupTable, int index, vector<vector<int>>& mtrx)
{
	if (lookupTable[index] != INT_MAX) return lookupTable[index];

	int coords[2] = { floor(index / mtrx[0].size()), index % mtrx[0].size() };
	for (int a = max(0, coords[1] - 1); a <= min((int)mtrx[0].size()-1, coords[1] + 1); ++a)
	{
		int nextIndex = (coords[0] + 1) * (mtrx[0].size()) + a;
		lookupTable[index] = min(mtrx[coords[0]][coords[1]] + getMinPath(lookupTable, nextIndex, mtrx),
			lookupTable[index]);
	}

	return lookupTable[index];
}
*/