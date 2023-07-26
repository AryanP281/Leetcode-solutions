
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Vec;

int main()
{


    getchar();
    return 0;
}

void getInplaceFreqs(vector<int>& arr)
{
    sort(arr.begin(), arr.end());

    Vec currBigger(0,0);
    for(int i = 0; i < arr.size(); ++i)
    {
        if(arr[i] > (i+1))
        {
            
        }
    }
}

vector<int> generateArray(int n)
{
    vector<int> arr(n,0);

    for(int i = 0; i < n; ++i)
    {
        arr[i] = (rand() % n) + 1;
    }

    return arr;
}

vector<int> generateSol(vector<int>& arr)
{
    unordered_map<int,int> freqs;

    for(int i = 0; i < arr.size(); ++i)
    {
        
    }
}