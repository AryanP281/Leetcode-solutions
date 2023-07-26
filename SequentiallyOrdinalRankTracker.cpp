
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,string> Vec;

class VecCmp
{
public:
    bool operator()(Vec v1, Vec v2) const
    {
        if(v1.first == v2.first)
            return lexicographical_compare(v1.second.begin(), v1.second.end(), v2.second.begin(), v2.second.end());
        
        return v1.first > v2.first;
    }
};

class SORTracker 
{
private:
    set<Vec,VecCmp> fh;
    set<Vec,VecCmp> sh;
    int i;

public:
    SORTracker() 
    {
        i = 1;
    }
    
    void add(string name, int score) 
    {
        Vec newPlace(score, name);
        if(fh.size() < i || score >= fh.rbegin()->first)
            fh.insert(newPlace);
        else
            sh.insert(newPlace);

        if(fh.size() > i)
        {
            Vec toMove = *fh.rbegin();
            fh.erase(--fh.end());
            sh.insert(toMove);
        }
    }
    
    string get() 
    {
        string place = fh.rbegin()->second;
        i += 1;

        if(sh.size())
        {
            Vec toMove = *sh.begin();
            sh.erase(sh.begin());
            fh.insert(toMove);
        }

        return place;
    }
};

int main()
{
    typedef pair<string,int> Place;

    SORTracker sor;

    vector<Place> ops = {{"bradford", 2}, {"branford", 3}, {}, {"alps", 2}, {}, {"orland", 2}, {}, {"orlando", 3}, {}, {"alpine", 2}, {}, {}};
    for(int i = 0; i < ops.size(); ++i)
    {
        if(ops[i].second)
            sor.add(ops[i].first, ops[i].second);
        else
            cout << sor.get() << '\n';
    }

    getchar();
    return 0;
}