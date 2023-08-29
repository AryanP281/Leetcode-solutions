
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,string> Vec;

class TimeMap 
{
private:
    unordered_map<string,vector<Vec>> store;    
public:
    TimeMap() 
    {
        
    }
    
    void set(string key, string value, int timestamp) 
    {
        store[key].push_back(Vec(timestamp, value));
    }
    
    string get(string key, int timestamp) 
    {
        unordered_map<string,vector<Vec>>::iterator itr = store.find(key);

        if(itr == store.end() || itr->second.empty())
            return "";
        
        vector<Vec>* vals = &(itr->second);
        int l = 0;
        int r = itr->second.size()-1;
        int idx = -1;
        while(l <= r)
        {
            int m = floor((float)(l+r)/2.0f);

            if((*vals)[m].first == timestamp)
            {
                idx = m;
                break;
            }
            else if((*vals)[m].first > timestamp)
                r = m-1;
            else
            {
                idx = m;
                l = m+1;
            }
        }

        if(idx == -1)
            return "";

        return (*vals)[idx].second;
    }   
};

int main()
{
    TimeMap tmp;
    tmp.set("foo","bar",1);
    cout << tmp.get("foo",1) << '\n';
    cout << tmp.get("foo",3) << '\n';
    tmp.set("foo","bar2",4);
    cout << tmp.get("foo",4) << '\n';
    cout << tmp.get("foo",5) << '\n';

    getchar();
    return 0;
}

