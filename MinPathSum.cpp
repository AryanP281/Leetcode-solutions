/*
#include<iostream>
#include<vector>

using namespace std;

const int neighbourVecs[2][2] = { {1,0}, {0,1} };

int minPathSum(vector<vector<int>>& grid);
vector<pair<int, int>> getNeighbours(int r, int c, int totalRows, int totalCols);

void main()
{
	int gridVals[3][3] = { {1,3,1}, {1,5,1}, {4,2,1} };
	vector<vector<int>> grid;
	for (int a = 0; a < 3; ++a)
	{
		grid.push_back(vector<int>(gridVals[a], gridVals[a] + 3));
	}

	cout << minPathSum(grid);
}

int minPathSum(vector<vector<int>>& grid)
{
	int* nodeMins = new int[grid.size() * grid[0].size()];
	fill_n(nodeMins, grid.size() * grid[0].size(), INT_MAX);
	nodeMins[0] = grid[0][0];

	for (int r = 0; r < grid.size(); ++r)
	{
		for (int c = 0; c < grid[r].size(); ++c)
		{
			vector<pair<int,int>> neighbours = getNeighbours(r, c, grid.size(), grid[r].size());
			for (int a = 0; a < neighbours.size(); ++a)
			{
				int neighbourIndex = neighbours[a].first * grid[neighbours[a].first].size() + neighbours[a].second;
				int newPathSum = nodeMins[r * grid[r].size() + c] + grid[neighbours[a].first][neighbours[a].second];
				if (newPathSum < nodeMins[neighbourIndex])
					nodeMins[neighbourIndex] = newPathSum;
			}
		}
	}

	int minPathSum = nodeMins[(grid.size() - 1) * grid[0].size() + grid[0].size() - 1];
	delete[] nodeMins;

	return minPathSum;
}

vector<pair<int,int>> getNeighbours(int r, int c, int totalRows, int totalCols)
{
	vector<pair<int,int>> neighbours;
	for (int a = 0; a < 2; ++a)
	{
		int neighbourCoords[2] = { r + neighbourVecs[a][0], c + neighbourVecs[a][1] };
		if (neighbourCoords[0] >= 0 && neighbourCoords[0] < totalRows && neighbourCoords[1] >= 0
			&& neighbourCoords[1] < totalCols)
			neighbours.push_back(pair<int,int>(neighbourCoords[0], neighbourCoords[1]));
	}

	return neighbours;
}
*/