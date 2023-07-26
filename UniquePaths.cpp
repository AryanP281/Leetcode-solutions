/*
#include<iostream>
#include<vector>

using namespace std;

int uniquePaths(int m, int n);

void main()
{
	cout << uniquePaths(3,3);
}

int uniquePaths(int m, int n)
{
	int* paths = new int[m * n]();
	paths[0] = 1;
	for (int r = 0; r < m; ++r)
	{
		for (int c = 0; c < n; ++c)
		{
			int downR = r+1;
			int rightC = c + 1 ;
			if (downR < m)
				paths[downR * n + c] += paths[r * n + c];
			if (rightC < n)
				paths[r * n + rightC] += paths[r*n + c];
		}
	}

	int up = paths[(m - 1) * n + n - 1];
	delete[] paths;

	return up;
}
*/