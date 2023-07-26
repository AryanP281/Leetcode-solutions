/*
#include<iostream>
#include<vector>

using namespace std;

int matrixScore(vector<vector<int>>& A);
int getRowVals(vector<vector<int>>& mat, vector<int>& rowVals);
int getRowFlipVal(vector<vector<int>>& mat, int row, vector<int>& rowVals);
int getColFlipVal(vector<vector<int>>& mat, int col, vector<int>& rowVals);
void flipRow(vector<vector<int>>& mat, int r, vector<int>& rowVals);
void flipCol(vector<vector<int>>& mat, int c, vector<int>& rowVals);

void main()
{
	int matVals[3][4] = { {0,0,1,1}, {1,0,1,0}, {1,1,0,0} };
	vector<vector<int>> mat;
	for (int a = 0; a < 3; ++a)
	{
		mat.push_back(vector<int>(matVals[a], matVals[a] + 4));
	}

	cout << matrixScore(mat);
}

int matrixScore(vector<vector<int>>& A) 
{
	vector<int> rowVals;
	int currentSum = getRowVals(A, rowVals);

	for (int r = 0; r < A.size(); ++r)
	{
		for (int c = 0; c < A[r].size(); ++c)
		{
			int rowFlipVal = getRowFlipVal(A, r, rowVals);
			int colFlipVal = getColFlipVal(A, c, rowVals);
			if (rowFlipVal > colFlipVal)
			{
				if (rowFlipVal > currentSum)
				{
					flipRow(A, r, rowVals);
					currentSum = rowFlipVal;
				}
			}
			else
			{
				if (colFlipVal > currentSum)
				{
					flipCol(A, c, rowVals);
					currentSum = colFlipVal;
				}
			}
		}
	}

	return currentSum;
}

int getRowVals(vector<vector<int>>& mat, vector<int>& rowVals)
{
	int sum = 0;
	for (int r = 0; r < mat.size(); ++r)
	{
		int val = 0;
		for (int c = 0; c < mat[r].size(); ++c)
		{
			val += mat[r][c] * pow(2, mat[r].size() - 1 - c);
		}
		rowVals.push_back(val);
		sum += val;
	}

	return sum;
}

int getRowFlipVal(vector<vector<int>>& mat, int row, vector<int>& rowVals)
{
	int val = 0;
	for (int r = 0; r < mat.size(); ++r)
	{
		if (r == row)
		{
			for (int c = 0; c < mat[r].size(); ++c)
			{
				val += (mat[r][c] == 0) * pow(2, mat[r].size() - 1 - c);
			}
		}
		else val += rowVals[r];
	}

	return val;
}

int getColFlipVal(vector<vector<int>>& mat, int col, vector<int>& rowVals)
{
	int val = 0;
	for (int r = 0; r < mat.size(); ++r)
	{
		val += (mat[r][col] == 1) * (rowVals[r] - pow(2, mat[r].size() - 1 - col)) +
			(mat[r][col] == 0) * (rowVals[r] + pow(2, mat[r].size() - 1 - col));
	}

	return val;
}

void flipRow(vector<vector<int>>& mat, int r, vector<int>& rowVals)
{
	int val = 0;
	for (int c = 0; c < mat[r].size(); ++c)
	{
		val += (mat[r][c] == 0) * pow(2, mat[r].size() - 1 - c);
		mat[r][c] = (mat[r][c] == 0);
	}

	rowVals[r] = val;
}

void flipCol(vector<vector<int>>& mat, int c, vector<int>& rowVals)
{
	for (int r = 0; r < mat.size(); ++r)
	{
		rowVals[r] += -(mat[r][c] == 1) * pow(2, mat[r].size() - 1 - c) +
			(mat[r][c] == 0) * pow(2, mat[r].size() - 1 - c);
		mat[r][c] = (mat[r][c] == 0);
	}
}
*/