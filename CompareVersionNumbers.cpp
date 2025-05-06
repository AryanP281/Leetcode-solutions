
#include<bits/stdc++.h>

using namespace std;

int main()
{

    getchar();

    return 0;
}

int compareVersion(string version1, string version2) 
{
    vector<int> revisions[2];
    version1.push_back('.');
    version2.push_back('.');

    int l = -1;
    for(int r = 1; r < version1.size(); ++r)
    {
        if(version1[r] == '.')
        {
            int revision = 0;
            for(int i = r-1; i > l; --i)
            {
                revision += (version1[i] - '0')*pow(10,r-1-i);
            }
            revisions[0].push_back(revision);
            l=r;
        }
    }

    l = -1;
    for(int r = 1; r < version2.size(); ++r)
    {
        if(version2[r] == '.')
        {
            int revision = 0;
            for(int i = r-1; i > l; --i)
            {
                revision += (version2[i] - '0')*pow(10,r-1-i);
            }
            revisions[1].push_back(revision);
            l=r;
        }
    }

    if(revisions[0].size() != revisions[1].size())
    {
        vector<int>& smallerArr = (revisions[0].size() < revisions[1].size()) ? revisions[0] : revisions[1];
        vector<int>& largerArr = (revisions[0].size() < revisions[1].size()) ? revisions[1] : revisions[0];
        while(smallerArr.size() != largerArr.size())
            smallerArr.push_back(0);
    }

    for(int i = 0; i < revisions[0].size(); ++i)
    {
        if(revisions[0][i] < revisions[1][i])
            return -1;
        else if(revisions[0][i] > revisions[1][i])
            return 1;
    }

    return 0;
}