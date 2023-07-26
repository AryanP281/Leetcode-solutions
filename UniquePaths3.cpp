/*
#include<iostream>
#include<vector>

using namespace std;

struct Vec2D
{
	int x;
	int y;
	Vec2D(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

const Vec2D dirVecs[4] = { Vec2D(0,-1), Vec2D(-1,0), Vec2D(0,1), Vec2D(1,0) };

int uniquePathsIII(vector<vector<int>>& grid);
Vec2D getStartPos(vector<vector<int>>& grid);
void traverse(vector<vector<int>>& grid, Vec2D currentNode, bool* traversedNodes, int* pathsCtr);
vector<Vec2D> getNeighbours(Vec2D& node, int r, int c);
bool allNodesTraversed(vector<vector<int>>& grid, bool* traversedNodes);

void main()
{
	int gridVals[2][2] = { {0,1}, {2,0} };
	vector<vector<int>> grid;
	for (int a = 0; a < 2; ++a)
	{
		grid.push_back(vector<int>(gridVals[a], gridVals[a] + 4));
	}

	cout << uniquePathsIII(grid);
}

int uniquePathsIII(vector<vector<int>>& grid)
{
	int pathsCount = 0;
	Vec2D startPos = getStartPos(grid);
	bool* traversedNodes = new bool[grid.size() * grid[0].size()]{ false };
	traverse(grid, startPos, traversedNodes, &pathsCount);

	return pathsCount;
}

Vec2D getStartPos(vector<vector<int>>& grid)
{
	Vec2D startPos(0, 0);

	for (int r = 0; r < grid.size(); ++r)
	{
		for (int c = 0; c < grid[r].size(); ++c)
		{
			if (grid[r][c] == 1)
			{
				startPos.x = r;
				startPos.y = c;
				return startPos;
			}
		}
	}

	return startPos;
}

void traverse(vector<vector<int>>& grid, Vec2D currentNode, bool* traversedNodes, int* pathsCtr)
{
	if (grid[currentNode.x][currentNode.y] == 2)
	{
		traversedNodes[(currentNode.x * grid[0].size()) + currentNode.y] = true;
		*pathsCtr += 1 * (allNodesTraversed(grid, traversedNodes));
		traversedNodes[(currentNode.x * grid[0].size()) + currentNode.y] = false;
		return;
	}

	traversedNodes[(currentNode.x * grid[0].size()) + currentNode.y] = true;

	vector<Vec2D> neighbours = getNeighbours(currentNode, grid.size(), grid[0].size());
	for (int a = 0; a < neighbours.size(); ++a)
	{
		if (traversedNodes[(neighbours[a].x * grid[0].size()) + neighbours[a].y] ||
			grid[neighbours[a].x][neighbours[a].y] == -1) 
			continue;

		traverse(grid, neighbours[a], traversedNodes, pathsCtr);
	}

	traversedNodes[(currentNode.x * grid[0].size()) + currentNode.y] = false;
}

vector<Vec2D> getNeighbours(Vec2D& node, int r, int c)
{
	vector<Vec2D> neighbours;
	for (const Vec2D* itr = dirVecs; itr != dirVecs + 4; ++itr)
	{
		Vec2D neighbour(node.x + itr->x, node.y + itr->y);
		if (neighbour.x >= 0 && neighbour.x < r && neighbour.y >= 0 && neighbour.y < c)
			neighbours.push_back(neighbour);
	}

	return neighbours;
}

bool allNodesTraversed(vector<vector<int>>& grid, bool* traversedNodes)
{
	int n = grid.size() * grid[0].size();
	for (int a = 0; a < n; ++a)
	{
		if (!traversedNodes[a] && grid[a / grid[0].size()][a%grid[0].size()] != -1) 
			return false;
	}

	return true;
}
*/