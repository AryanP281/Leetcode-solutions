/*
#include<iostream>
#include<vector>

using namespace std;

struct Vec2D
{
	int r;
	int c;

	Vec2D(int row, int col) : r(row), c(col) {}
	vector<int> toVector()
	{
		vector<int> vec;
		vec.push_back(r);
		vec.push_back(c);

		return vec;
	}
};

const Vec2D DIRS[4] = { Vec2D(0,1), Vec2D(1,0), Vec2D(0,-1), Vec2D(-1,0) };

vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0);

void main()
{
	spiralMatrixIII(5, 6, 1, 4);
}

vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) 
{
	vector<vector<int>> cells;
	cells.push_back(Vec2D(r0, c0).toVector());

	int step = 0;
	int d = 0;
	Vec2D current(r0, c0);
	while (cells.size() < R * C)
	{
		step++;
		for (int a = 0; a < 2; ++a)
		{
			for (int b = 0; b < step; ++b)
			{
				current.r += DIRS[d].r;
				current.c += DIRS[d].c;

				if (current.r >= 0 && current.r < R && current.c >= 0 && current.c < C)
					cells.push_back(current.toVector());
			}
			d = (d + 1) % 4;
		}
	}

	return cells;
}
*/
