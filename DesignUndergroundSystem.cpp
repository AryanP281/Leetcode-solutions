
#include<bits/stdc++.h>

using namespace std;

struct Journey
{
    string start;
    int startTime;

    Journey(string s, int st)
    {
        start = s;
        startTime = st;
    }

    Journey() : Journey("",0) {}
};

class UndergroundSystem 
{
private: 
    unordered_map<int,Journey> pending;
    unordered_map<string,unordered_map<string,vector<int>>> times;

public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) 
    {
        pending[id] = Journey(stationName, t);    
    }
    
    void checkOut(int id, string stationName, int t) 
    {
        Journey journey = pending[id];

        unordered_map<string,unordered_map<string,vector<int>>>::iterator itr = times.find(journey.start);
        if(itr == times.end())
        {
            times[journey.start][stationName] = {t - journey.startTime, 1};
            return;
        }

        unordered_map<string,vector<int>>::iterator itr2 = itr->second.find(stationName);
        if(itr2 == itr->second.end())
        {
            itr->second[stationName] = {t - journey.startTime, 1};
            return;
        }

        itr2->second[0] += t - journey.startTime;
        itr2->second[1]++;
    }
    
    double getAverageTime(string startStation, string endStation) 
    {
        vector<int>& timeData = times[startStation][endStation];

        return ((double)timeData[0]/(double)timeData[1]);    
    }
};

int main()
{
    UndergroundSystem us;
    us.checkIn(45,"Leyton",3);
    us.checkIn(32,"Paradise",8);
    us.checkIn(27,"Leyton",10);
    us.checkOut(45,"Waterloo",15);
    us.checkOut(27,"Waterloo",20);
    us.checkOut(32,"Cambridge",22);
    cout << us.getAverageTime("Paradise","Cambridge");

    getchar();
    return 0;
}

