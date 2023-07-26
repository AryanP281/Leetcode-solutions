/*
#include<iostream>
#include<vector>

using namespace std;

int lastTravelDay;
vector<int>* ticketCosts;

int mincostTickets(vector<int>& days, vector<int>& costs);
int getMinCost(int day, bool* travelDays, int* lookupTable);

void main()
{
	vector<int> days = { 1,2,3,4,5,6,7,8,9,10,30,31 };
	vector<int> costs = { 2,7,15 };

	cout << mincostTickets(days, costs);
}

int mincostTickets(vector<int>& days, vector<int>& costs)
{
	ticketCosts = &costs;

	bool travelDays[365] = { false };
	for (int a = 0; a < days.size(); ++a)
	{
		travelDays[days[a] - 1] = true;
	}

	lastTravelDay = days[days.size() - 1];
	int* lookupTable = new int[lastTravelDay]();

	int minCost = getMinCost(days[0], travelDays, lookupTable);

	delete[] lookupTable;
	
	return minCost;
}

int getMinCost(int day, bool* travelDays, int* lookupTable)
{
	if (day > lastTravelDay) return 0;
	if (lookupTable[day-1] != 0) return lookupTable[day-1];

	if (travelDays[day - 1])
	{
		int day_1 = (*ticketCosts)[0] + getMinCost(day + 1, travelDays, lookupTable);
		int day_7 = (*ticketCosts)[1] + getMinCost(day + 7, travelDays, lookupTable);
		int day_30 = (*ticketCosts)[2] + getMinCost(day + 30, travelDays, lookupTable);

		lookupTable[day - 1] = min(day_30, min(day_1, day_7));
	}
	else
		lookupTable[day - 1] = getMinCost(day + 1, travelDays, lookupTable);

	return lookupTable[day - 1];
}
*/