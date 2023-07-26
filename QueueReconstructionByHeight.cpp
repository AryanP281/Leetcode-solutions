/*
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> reconstructQueue(vector<vector<int>>& people);

void main()
{
	int vals[6][2] = { {7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2} };
	vector<vector<int>> people;
	for (int a = 0; a < 6; ++a)
	{
		people.push_back(vector<int>(vals[a], vals[a] + 2));
	}

	vector<vector<int>> queue = reconstructQueue(people);
}

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
{
	sort(people.begin(), people.end(),
		[](vector<int>& a, vector<int>& b) -> bool
		{
			if (a[0] > b[0]) return true;
			else if (a[0] == b[0] && a[1] < b[1]) return true;

			return false;
		}
	);

	vector<vector<int>> queue;
	//queue.push_back(people[0]);
	for (int a = 0; a < people.size(); ++a)
	{
		queue.insert(queue.begin() + min((int)queue.size(), people[a][1]), people[a]);
	}

	return queue;
}
*/