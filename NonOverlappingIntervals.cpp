
#include<bits/stdc++.h>

using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals);

int main()
{
	vector<vector<int>> intervals = {{1,4},{2,3},{5,10},{6,8},{7,9},{8,10},{1,11}};
	
	cout << eraseOverlapIntervals(intervals);

	getchar();
	return 0;
}

int eraseOverlapIntervals(vector<vector<int>>& intervals)
{
	auto overlap = [](vector<int>& i1, vector<int>& i2) -> bool
	{
		return ((i1[0] == i2[0]) || (i1[0] < i2[0] && i1[1] > i2[0]) || (i2[0] < i1[0] && i2[1] > i1[0]));
	};

	
	sort(intervals.begin(), intervals.end(), [](vector<int>& i1, vector<int>& i2) -> bool{
		return (i1[0] < i2[0]) || (i1[0] == i2[0] && i1[1] < i2[1]);
	});
	list<vector<int>> sortedIntervalList(intervals.begin(), intervals.end());

	list<vector<int>>::iterator leftItr = sortedIntervalList.begin();
	list<vector<int>>::iterator rightItr = sortedIntervalList.begin();
	++rightItr;

	int toEraseCount = 0;
	list<vector<int>>::iterator tempItr;
	while(rightItr != sortedIntervalList.end())
	{
		if(leftItr == rightItr)
		{
			++rightItr;
			continue;
		}
		
		if(overlap(*leftItr, *rightItr))
		{
			if(rightItr->at(1) > leftItr->at(1))
			{
				tempItr = rightItr;
				++rightItr;
				sortedIntervalList.erase(tempItr);
			}
			else
			{
				tempItr = leftItr;
				++leftItr;
				sortedIntervalList.erase(tempItr);
			}

			++toEraseCount;
		}
		else
			leftItr++;
	}

	return toEraseCount;
}
