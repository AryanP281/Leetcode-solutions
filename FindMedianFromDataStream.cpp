
#include<bits/stdc++.h>

using namespace std;

class MedianFinder 
{
private:
    multiset<int> lh;
    multiset<int> rh;

public:
    MedianFinder() 
    {
        
    }
    
    void addNum(int num) 
    {

        int n = lh.size() + rh.size();
        if(n == 0)
            lh.insert(num);
        else
        {
            if(num < *lh.rbegin())
                lh.insert(num);
            else
                rh.insert(num);
            
            int m = ceil((double)++n/2.0);
            while(lh.size() != m)
            {
                if(lh.size() < m)
                {
                    lh.insert(*rh.begin());
                    rh.erase(rh.begin());
                }
                else
                {
                    rh.insert(*lh.rbegin());
                    lh.erase(prev(lh.end()));
                }
            }
        }

    }
    
    double findMedian() 
    {
        int n = lh.size() + rh.size();

        //Odd size
        if(n % 2)
            return *lh.rbegin();
        else
            return ((double)(*lh.rbegin() + *rh.begin() )) / 2.0;   
    }
};

int main()
{
    MedianFinder mf;
    
    int i = 0;
    vector<vector<int>> vals = {{12},{},{10},{},{13},{},{11},{},{5},{},{15},{},{1},{},{11},{},{6},{},{17},{},{14},{},{8},{},{17},{},{6},{},{4},{},{16},{},{8},{},{10},{},{2},{},{12},{},{0},{}};
    for(int r = 0; r < vals.size(); ++r)
    {
        if(vals[r].size() == 0)
            cout << mf.findMedian() << '\n';
        else
            mf.addNum(vals[r][0]);
    }


    getchar();
    return 0;
}

