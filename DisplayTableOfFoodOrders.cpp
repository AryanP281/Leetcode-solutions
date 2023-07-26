/*
#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

vector<vector<string>> displayTable(vector<vector<string>>& orders);

void main()
{
	string orderVals[6][3] = { {"David", "3", "Ceviche"}, {"Corina", "10", "Beef Burrito"},
		{"David", "3", "Fried Chicken"}, {"Carla", "5", "Water"}, {"Carla", "5", "Ceviche"},
		{"Rous", "3", "Ceviche"} };
	vector<vector<string>> orders;
	for (int a = 0; a < 6; ++a)
	{
		orders.push_back(vector<string>(orderVals[a], orderVals[a] + 3));
	}

	vector<vector<string>> table = displayTable(orders);
}

vector<vector<string>> displayTable(vector<vector<string>>& orders)
{
	unordered_map<string, int> tableOrders[500];
	set<string> dishes;

	for (int a = 0; a < orders.size(); ++a)
	{
		int table = stoi(orders[a][1]);
		string& dish = orders[a][2];

		if (dishes.count(dish) == 0)
			dishes.insert(dish);

		unordered_map<string, int>::iterator itr = tableOrders[table - 1].find(dish);
		if (itr == tableOrders[table - 1].end())
			tableOrders[table - 1][dish] = 1;
		else
			itr->second++;
	}

	vector<vector<string>> dispTable;
	dispTable.push_back(vector<string>());
	dispTable[0].push_back("Table");
	for (set<string>::iterator itr = dishes.begin(); itr != dishes.end(); ++itr)
	{
		dispTable[0].push_back(*itr);
	}

	for (int a = 0; a < 500; ++a)
	{
		if (!tableOrders[a].empty())
		{
			dispTable.push_back(vector<string>());
			dispTable.rbegin()->push_back(to_string(a + 1));
			for (set<string>::iterator itr = dishes.begin(); itr != dishes.end(); ++itr)
			{
				unordered_map<string, int>::iterator tableItr = tableOrders[a].find(*itr);
				if (tableItr != tableOrders[a].end())
					dispTable.rbegin()->push_back(to_string(tableItr->second));
				else
					dispTable.rbegin()->push_back(string(1, '0'));
			}
		}
	}

	return dispTable;
}
*/