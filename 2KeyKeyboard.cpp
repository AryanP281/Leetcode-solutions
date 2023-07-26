
#include<bits/stdc++.h>

using namespace std;

int minSteps(int n);
unordered_set<int>* getFactors(int x);

int main()
{
	cout << minSteps(7);

	getchar();
	return 0;
}

int minSteps(int n) 
{
	int* stepsCache = new int[n];
	stepsCache[0] = 0;

	unordered_set<int>* factors;
	unordered_set<int>::iterator itr;
	for(int i = 2; i <= n; ++i)
	{
		stepsCache[i-1] = INT_MAX;

		factors = getFactors(i);
		for(itr = factors->begin(); itr != factors->end(); ++itr)
		{
			stepsCache[i-1] = min(stepsCache[i-1], stepsCache[*itr-1] + 1 + ((i / *itr) - 1) );
		}

		delete factors;
	}

	int result = stepsCache[n-1];
	
	delete[] stepsCache;
	return result;
}

unordered_set<int>* getFactors(int x)
{
	unordered_set<int>* factors = new unordered_set<int>();
	factors->insert(1);

	int root = floor(sqrt(x));
	for(int a = 2; a <= root; ++a)
	{
		if(!(x % a))
		{
			factors->insert(a);
			factors->insert(x / a);
		}
	}

	return factors;
}