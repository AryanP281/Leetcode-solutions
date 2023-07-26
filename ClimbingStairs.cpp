/*
#include<iostream>

using namespace std;

int climbStairs(int n);

void main()
{
	cout << climbStairs(4);
}

int climbStairs(int n)
{
	As you can climb 1 or 2 stairs at a time, distinct ways to reach i'th step = 
		distinct ways to reach (i-2)th step + distinct ways to reach (i-1)th step
	
	if (n == 1) return 1;
	else if (n == 2) return 2;
	
	int prePrev = 1;
	int prev = 2;
	int current = 0;
	for (int a = 2; a < n; ++a)
	{
		current = prev + prePrev;
		prePrev = prev;
		prev = current;
	}
	
	return current;
}
*/