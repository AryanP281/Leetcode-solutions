/*
#include<iostream>
#include<vector>

using namespace std;

const int DIR_VECS[8][2] = { {0,-1}, {-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1} };

vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king);

void main()
{
	int queenPos[34][2] = { {5,6} ,{7,7},{2,1},{0,7},{1,6},{5,1},{3,7},{0,3},{4,0},
		{1,2},{6,3},{5,0},{0,4},{2,2},{1,1},{6,4},{5,4},{0,0},{2,6},{4,5},{5,2},
		{1,4},{7,5},{2,3},{0,5},{4,2},{1,0},{2,7},{0,1},{4,6},{6,1},{0,6},{4,3},{1,7} };
	//int queenPos[7][2] = {  {0,0} ,{1,1},{2,2},{3,4},{3,5},{4,4},{4,5} };
	int kingPos[2] = { 3,4 };

	vector<vector<int>> queens;
	for (int a = 0; a < 34; ++a)
	{
		queens.push_back(vector<int>(queenPos[a], queenPos[a] + 2));
	}
	vector<int> king(kingPos, kingPos + 2);

	vector<vector<int>> res = queensAttacktheKing(queens, king);
}

vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king)
{
	bool* occupiedSites = new bool[8 * 8]{ false };
	for (vector<int>& queen : queens)
	{
		occupiedSites[(queen[0] * 8) + queen[1]] = true;
	}

	vector<vector<int>> res;
	for (int a = 0; a < 8; ++a)
	{
		vector<int> current = king;
		current[0] += DIR_VECS[a][0];
		current[1] += DIR_VECS[a][1];
		while (current[0] >= 0 && current[0] < 8 && current[1] >= 0 && current[1] < 8)
		{
			if (occupiedSites[(current[0]*8) + current[1]])
			{
				res.push_back(current);
				break;
			}

			current[0] += DIR_VECS[a][0];
			current[1] += DIR_VECS[a][1];
		}
	}

	delete[] occupiedSites;

	return res;
}
*/