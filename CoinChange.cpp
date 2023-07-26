/*
#include<iostream>
#include<vector>
#include <unordered_map>

using namespace std;

int coinChange(vector<int>& coins, int amount);
int getChange(int* lookupTable, vector<int>& coins, int amt);

void main()
{
	vector<int> coins = { 186, 419, 83, 408 }; //186, 419, 83, 408
	int amount = 6249; //6249

	cout << coinChange(coins, amount);
}

int coinChange(vector<int>& coins, int amount)
{
	int* lookupTable = new int[amount]();

	int minChange = getChange(lookupTable, coins, amount);
	
	delete[] lookupTable;

	return minChange;
}

int getChange(int* lookupTable, vector<int>& coins, int amt)
{
	if (amt < 0) return -1;
	else if (amt == 0) return 0;

	if (lookupTable[amt - 1] != 0) return lookupTable[amt - 1];

	bool changeFound = false;
	for (int a = 0; a < coins.size(); ++a)
	{
		int remChange = getChange(lookupTable, coins, amt - coins[a]);
		if (remChange != -1)
		{
			changeFound = true;
			if (lookupTable[amt-1] == 0 || remChange + 1 < lookupTable[amt - 1])
				lookupTable[amt - 1] = remChange + 1;
		}
	}

	if (!changeFound) lookupTable[amt - 1] = -1;

	return lookupTable[amt - 1];
}
*/