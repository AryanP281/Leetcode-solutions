
#include<bits/stdc++.h>

using namespace std;

int mctFromLeafValues(vector<int>& arr);
int getMinCost(vector<int>& arr, int l, int r, int* lookupTable);


int main()
{
    vector<int> arr = {6,2,4};
    cout << mctFromLeafValues(arr);

    getchar();
    return 0;
}

int mctFromLeafValues(vector<int>& arr) 
{
    int* lookupTable = new int[arr.size()*arr.size()];
    fill_n(lookupTable, arr.size()*arr.size(),-1);       

    return getMinCost(arr,0,arr.size()-1,lookupTable);
}

int getMinCost(vector<int>& arr, int l, int r, int* lookupTable)
{
    if(l==r) return 0;
    
    int index = (l*arr.size()) + r;
    if(lookupTable[index] != -1)
        return lookupTable[index];

    lookupTable[index] = INT_MAX;
    for(int k = l; k < r; ++k)
    {
        int newCost = getMinCost(arr,l,k,lookupTable) + getMinCost(arr,k+1,r,lookupTable) + 
        (*max_element(arr.begin()+l,arr.begin()+k+1) * *max_element(arr.begin()+k+1,arr.begin()+r+1));
        if(lookupTable[index] > newCost)
            lookupTable[index] = newCost;
    }

    return lookupTable[index];
}