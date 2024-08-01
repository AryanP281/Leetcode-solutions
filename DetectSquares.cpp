
#include<bits/stdc++.h>

using namespace std;

class DetectSquares 
{
private:
    unordered_multiset<int>* xMap;
    unordered_multiset<int>* yMap;

public:
    DetectSquares() 
    {
        xMap = new unordered_multiset<int>[1001];
        yMap = new unordered_multiset<int>[1001];

    }
    
    void add(vector<int> point) 
    {
        xMap[point[0]].insert(point[1]);
        yMap[point[1]].insert(point[0]);    
    }
    
    int count(vector<int> point) 
    {
        //4 possible squares
        unordered_multiset<int>::iterator itr;
        int triangleCts = 0;

        //Possibility 1&2: Point is top/bottom left vertex
        for(itr = yMap[point[1]].begin(); itr != yMap[point[1]].end(); ++itr)
        {
            if(*itr <= point[0])
                continue;

            int sl = *itr - point[0];
            triangleCts += (xMap[point[0]].count(point[1] - sl)*xMap[*itr].count(point[1] - sl)) +
            (xMap[point[0]].count(point[1] + sl)*xMap[*itr].count(point[1] + sl));
        }

        //Possibility 3&4: Point is top/bottom right vertex
        for(itr = yMap[point[1]].begin(); itr != yMap[point[1]].end(); ++itr)
        {
            if(*itr >= point[0])
                continue;

            int sl = point[0] - *itr;
            triangleCts += (xMap[point[0]].count(point[1] - sl)*xMap[*itr].count(point[1] - sl)) + 
            (xMap[point[0]].count(point[1] + sl)*xMap[*itr].count(point[1] + sl));
        } 

        return triangleCts;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */

int main()
{
    DetectSquares ds;
    ds.add({3,10});
    ds.add({11,2});
    ds.add({3,2});
    ds.add({11,2});
    ds.count({11,10});


    getchar();
    return 0;
}