
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Vec;

class DetectSquares 
{
private: 
    map<int,int>* xCoords;
    map<int,int>* yCoords;

    int sign(int x)
    {
        return -1*(x < 0) + 1*(x > 0);
    }

    int lowerBound(vector<Vec>& arr, int x)
    {
        int l = 0;
        int r = arr.size()-1;
        int lb = arr.size();
        while(l <= r)
        {
            int m = ceil((double)(r+l)/2.0);
            if(arr[m].first == x)
                return m;
            else if(arr[m].first > x)
            {
                lb = m;
                r = m-1;
            }
            else
                l = m+1;
        }

        return lb;
    }

public:
    DetectSquares() 
    {
        xCoords = new map<int,int>[1001];
        yCoords = new map<int,int>[1001];
    }

    ~DetectSquares()
    {
        delete[] xCoords;
        delete[] yCoords;
    }
    
    void add(vector<int> point) 
    {
        xCoords[point[0]][point[1]]++;
        yCoords[point[1]][point[0]]++;
    }
    
    int count(vector<int> point) 
    {
        vector<Vec> hDir(yCoords[point[1]].begin(), yCoords[point[1]].end());
        vector<Vec> vDir(xCoords[point[0]].begin(), xCoords[point[0]].end());

        int squareCount = 0;
        int hPos = lowerBound(hDir, point[0]);
        int vPos = lowerBound(vDir, point[1]);
        for(int i = 0, h=hPos,v=vPos; i < 4; ++i, h=hPos,v=vPos)
        {
            h += 1*((i==0 || i==3) && hPos < hDir.size() && hDir[hPos].first == point[0]) - 1*(i == 1 || i == 2);
            v += 1*((i==0 || i==1) && vPos < vDir.size() && vDir[vPos].first == point[1]) - 1*(i == 2 || i == 3);

            while(h >= 0 && h < hDir.size() && v >= 0 && v < vDir.size())
            {
                if(abs(point[0] - hDir[h].first) < abs(point[1] - vDir[v].first))
                    h += 1*(i == 0 || i == 3) - 1*(i == 1 || i == 2);
                else if(abs(point[0] - hDir[h].first) > abs(point[1] - vDir[v].first))
                    v += 1*(i == 1 || i == 0) - 1*(i == 2 || i == 3);
                else
                {
                    int sideLength = abs(point[0] - hDir[h].first);
                    map<int,int>::iterator lastPoint = xCoords[hDir[h].first].find(point[1] + sign(vDir[v].first - point[1])*sideLength);
                    if(lastPoint != xCoords[hDir[h].first].end())
                        squareCount += hDir[h].second*vDir[v].second*lastPoint->second;

                    h += 1*(i == 0 || i == 3) - 1*(i == 1 || i == 2);
                    v += 1*(i == 1 || i == 0) - 1*(i == 2 || i == 3);
                }
            }
        }

        return squareCount;
    }

    int countAlt(vector<int> point)
    {
        map<int,int>::iterator hItr, vItr, lastP;
        int squareCount = 0;

        hItr = yCoords[point[1]].begin();
        while(hItr != yCoords[point[1]].end())
        {
            if(hItr->first == point[0])
                continue;

            int sideLength = abs(point[0] - hItr->first);
            vItr = xCoords[point[0]].find(point[1]+sideLength);
            if(vItr != xCoords[point[0]].end())
            {
                lastP = xCoords[hItr->first].find(point[1]+sideLength);
                if(lastP != xCoords[hItr->first].end())
                    squareCount += hItr->second*vItr->second*lastP->second;
            }

            vItr = xCoords[point[0]].find(point[1]-sideLength);
            if(vItr != xCoords[point[0]].end())
            {
                lastP = xCoords[hItr->first].find(point[1]-sideLength);
                if(lastP != xCoords[hItr->first].end())
                    squareCount += hItr->second*vItr->second*lastP->second;
            }

            hItr++;
        }

        return squareCount;
    }
};

int main()
{
    vector<string> actions = {"DetectSquares","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add"};
    vector<vector<vector<int>>> pts = {{},{{229,355}},{{229,491}},{{365,491}},{{365,355}},{{452,647}},{{452,297}},{{802,647}},{{802,297}},{{33,359}},{{494,359}},{{494,820}},{{33,820}},{{8,110}},{{8,940}},{{838,940}},{{838,110}},{{92,887}},{{530,449}},{{92,449}},{{530,887}},{{561,544}},{{829,812}},{{829,544}},{{561,812}},{{412,442}},{{192,442}},{{412,222}},{{192,222}},{{926,177}},{{860,177}},{{926,111}},{{860,111}},{{11,962}},{{11,9}},{{964,9}},{{964,962}},{{169,199}},{{169,981}},{{951,981}},{{951,199}},{{420,822}},{{420,901}},{{341,901}},{{341,822}},{{793,806}},{{98,806}},{{98,111}},{{793,111}},{{898,92}},{{898,899}},{{91,92}},{{91,899}},{{418,214}},{{669,214}},{{669,465}},{{418,465}},{{997,20}},{{997,921}},{{96,921}},{{96,20}},{{291,735}},{{884,735}},{{291,142}},{{884,142}},{{956,450}},{{956,65}},{{571,65}},{{571,450}},{{577,890}},{{661,890}},{{577,806}},{{661,806}},{{695,111}},{{504,302}},{{504,111}},{{695,302}},{{628,772}},{{46,190}},{{628,190}},{{46,772}},{{834,216}},{{60,216}},{{834,990}},{{60,990}},{{126,868}},{{978,868}},{{978,16}},{{126,16}},{{724,44}},{{430,44}},{{724,338}},{{430,338}},{{193,16}},{{992,16}},{{193,815}},{{992,815}},{{925,29}},{{745,209}},{{925,209}},{{745,29}},{{454,225}},{{360,131}},{{360,225}},{{454,131}},{{935,22}},{{935,898}},{{59,22}},{{59,898}},{{793,242}},{{939,388}},{{793,388}},{{939,242}},{{133,268}},{{133,970}},{{835,970}},{{835,268}},{{86,80}},{{86,930}},{{936,930}},{{936,80}},{{30,30}},{{30,984}},{{984,30}},{{984,984}},{{728,469}},{{541,469}},{{541,656}},{{728,656}},{{16,0}},{{998,0}},{{998,982}},{{16,982}},{{272,48}},{{272,505}},{{729,505}},{{729,48}},{{223,737}},{{74,588}},{{74,737}},{{223,588}},{{875,302}},{{952,225}},{{952,302}},{{875,225}},{{924,781}},{{924,103}},{{246,103}},{{246,781}},{{281,294}},{{570,5}},{{281,5}},{{570,294}},{{801,153}}};
    vector<int> exp = {0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0};
    DetectSquares ds;
    for(int i = 0; i < actions.size(); ++i)
    {
        if(actions[i] == "add")
            ds.add(pts[i][0]);
        else if(actions[i] == "count")
        {
            int ct = ds.count(pts[i][0]);
            if(ct != exp[i])
            {
                cout << "Incorrect: " << i << '\n';
            }
        }
    }

    getchar();
    return 0;
}

/*

*/

/*

        */