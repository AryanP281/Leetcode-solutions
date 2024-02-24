
#include<bits/stdc++.h>

using namespace std;

vector<int> partitionLabels(string s);

int main()
{

    vector<int> partitionSizes = partitionLabels("eaaaabaaec");

    getchar();
    return 0;
}

vector<int> partitionLabels(string s) 
{
    int* charMaxPos = new int[26]();
    for(int i = 0; i < s.size(); ++i)
    {
        charMaxPos[s[i] - 'a'] = i;
    }

    vector<int> partitionSizes;
    int l = 0;
    int r = charMaxPos[s[0] - 'a'];
    for(int i = 0; i < s.size(); ++i)
    {
        r = max(r, charMaxPos[s[i] - 'a']);

        if(i == r)
        {
            partitionSizes.push_back(r-l+1);
            l = i+1;
            continue;
        }
    }

    delete[] charMaxPos;

    return partitionSizes;
}