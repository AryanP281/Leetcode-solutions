/*
#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K);
void getCumSumMatrix(vector<vector<int>>& mat, vector<vector<int>>& dp);

void main()
{
	int mtrxVals[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
	vector<vector<int>> mat;
	for (int a = 0; a < 3; ++a)
	{
		mat.push_back(vector<int>(mtrxVals[a], mtrxVals[a] + 3));
	}

	vector<vector<int>> res = matrixBlockSum(mat, 2);
}

vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) 
{
	vector<vector<int>> dp; //The cumulative sum matrix
	getCumSumMatrix(mat, dp);

	vector<vector<int>> ans;
	int bounds[2][2];
	for (int i = 0; i < mat.size(); ++i)
	{
		ans.push_back(vector<int>());

		bounds[0][0] = max(0, i - k);
		bounds[1][0] = min((int)(mat.size() - 1), i + k);
		for (int j = 0; j < mat[0].size(); ++j)
		{
			bounds[0][1] = max(0, j - k);
			bounds[1][1] = min((int)mat[0].size() - 1, j + k);

			int val = dp[bounds[1][0]][bounds[1][1]];
			if (bounds[0][0] != 0 && bounds[0][1] != 0)
			{
				val -= dp[bounds[1][0]][bounds[0][1] - 1] +
					dp[bounds[0][0] - 1][bounds[1][1]] - dp[bounds[0][0] - 1][bounds[0][1] - 1];
			}
			else if (bounds[0][0] == 0 && bounds[0][1] != 0)
				val -= dp[bounds[1][0]][bounds[0][1] - 1];
			else if (bounds[0][0] != 0 && bounds[0][1] == 0)
				val -= dp[bounds[0][0] - 1][bounds[1][1]];

			ans[i].push_back(val);
		}
	}

	return ans;
}

void getCumSumMatrix(vector<vector<int>>& mat, vector<vector<int>>& dp)
{
	for (int r = 0; r < mat.size(); ++r)
	{
		dp.push_back(vector<int>());
		for (int c = 0; c < mat[r].size(); ++c)
		{
			int val = (c != 0 ? dp[r][c - 1] : 0) + (r != 0 ? dp[r - 1][c] : 0) +
				(r != 0 && c != 0 ? -dp[r - 1][c - 1] : 0) + mat[r][c];
			dp[r].push_back(val);
		}
	}
}
*/