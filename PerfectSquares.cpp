
#include<bits/stdc++.h>

using namespace std;

int numSquares(int n);

int main()
{
	cout << numSquares(13);

	getchar();
	return 0;
}

int numSquares(int n) 
{
	vector<int> sols(n+1,INT_MAX);
	sols[0] = 0;
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= floor(sqrt(i)); ++j)
		{
			sols[i] = min(sols[i], 1 + sols[i - (j*j)]);
		}
	}

	return sols[sols.size()-1];
}