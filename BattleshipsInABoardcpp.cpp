/*
#include<iostream>
#include<vector>

using namespace std;

class UnionFind
{
private :
	int n;
	int* elements;
	int* setSizes;

	int getLeader(int e)
	{
		if (elements[e] == e) return e;

		int leader = getLeader(elements[e]);
		
		elements[e] = leader; //Path compression

		return leader;
	}

public :
	UnionFind(int elementsCount) : n(elementsCount)
	{
		elements = new int[n+1];
		fill_n(elements, n+1, -1);
		setSizes = new int[n+1] {0};
	}

	~UnionFind()
	{
		delete[] elements;
		delete[] setSizes;
	}

	int find(int e)
	{
		if (elements[e] == -1) return -1;

		return getLeader(e);
	}

	void performUnion(int e1, int e2)
	{
		int leader1 = find(e1);
		int leader2 = find(e2);

		if (leader1 == leader2) return;

		int* smallerSetLeader = (setSizes[leader1] > setSizes[leader2]) ? &leader2 : &leader1;
		int* largerSetLeader = (smallerSetLeader == &leader1) ? &leader2 : &leader1;

		elements[*smallerSetLeader] = *largerSetLeader;

		setSizes[*largerSetLeader] += setSizes[*smallerSetLeader];
		setSizes[*smallerSetLeader] = 0;
	}

	void add(int e)
	{
		if (elements[e] != -1) return;

		elements[e] = e;
		setSizes[e] = 1;
	}

	int getSetsCount() const
	{
		int sets = 0;
		for (int* itr = setSizes; itr < setSizes + n + 1; ++itr)
		{
			sets += (*itr > 0);
		}

		return sets;
	}
};

struct Vec2D
{
	int x;
	int y;

	Vec2D(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	int convertTo1D(Vec2D& gridDims)
	{
		return (this->x * gridDims.y) + this->y;
	}
};


int countBattleships(vector<vector<char>>& board);
vector<Vec2D> getNeighbours(Vec2D& coords, Vec2D& gridDims);

void main()
{
	char grid[3][4] = { {'X','.','.','X'}, {'.','.','.','X'}, {'.','.','.','X'} };
	vector<vector<char>> board;
	for (int a = 0; a < 3; ++a)
	{
		board.push_back(vector<char>(grid[a], grid[a] + 4));
	}

	cout << countBattleships(board);
}

int countBattleships(vector<vector<char>>& board)
{
	Vec2D boardDims(board.size(), board[0].size());
	
	UnionFind uf(boardDims.x * boardDims.y);

	for (int r = 0; r < board.size(); ++r)
	{
		for (int c = 0; c < board[r].size(); ++c)
		{
			if (board[r][c] == 'X')
			{
				Vec2D coords(r, c);
				int index = coords.convertTo1D(boardDims);
				uf.add(index);
				vector<Vec2D> neighbours = getNeighbours(coords, boardDims);
				for (int a = 0; a < neighbours.size(); ++a)
				{
					if (board[neighbours[a].x][neighbours[a].y] != 'X') continue;

					int neighbourIndex = neighbours[a].convertTo1D(boardDims);
					uf.add(neighbourIndex);
					uf.performUnion(index, neighbourIndex);
				}
			}
		}
	}

	return uf.getSetsCount();
}

vector<Vec2D> getNeighbours(Vec2D& coords, Vec2D& gridDims)
{
	Vec2D neighbourVecs[4] = { Vec2D(0,-1), Vec2D(-1,0), Vec2D(0,1), Vec2D(1,0) };

	vector<Vec2D> neighbours;
	for (int a = 0; a < 4; ++a)
	{
		Vec2D neighbour( coords.x + neighbourVecs[a].x, coords.y + neighbourVecs[a].y);

		if ((neighbour.x >= 0 && neighbour.x < gridDims.x) && (neighbour.y >= 0 &&
			neighbour.y < gridDims.y))
		{
			neighbours.push_back(neighbour);
		}
	}

	return neighbours;
}
*/