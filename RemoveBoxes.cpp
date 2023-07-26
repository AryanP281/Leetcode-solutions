
#include<bits/stdc++.h>

using namespace std;

int removeBoxes(vector<int>& boxes);
int solve(vector<int>& arr, int l, int r, int k, int*** lookupTable);

int main()
{
    vector<int> arr = {1,3,2,2,2,3,4,3,1};
    cout << removeBoxes(arr);

    getchar();
    return 0;
}

int removeBoxes(vector<int>& boxes) 
{
    int*** lookupTable = new int**[boxes.size()];
    for(int a = 0; a < boxes.size(); ++a)
    {
        lookupTable[a] = new int*[boxes.size()];
        for(int b = 0; b < boxes.size(); ++b)
        {
            lookupTable[a][b] = new int[boxes.size()]();
        }
    }

    return solve(boxes, 0, boxes.size()-1, 0, lookupTable);   
}

int solve(vector<int>& arr, int l, int r, int k, int*** lookupTable)
{
    if(l > r) return 0;

    int index = (arr.size()*l) + (arr.size()*r) + k;

    if(lookupTable[l][r][k] != 0)
        return lookupTable[l][r][k];

    lookupTable[l][r][k] = pow((k+1),2) + solve(arr, l+1,r,0,lookupTable);
    for(int a = l+1; a <= r; ++a)
    {
        if(arr[a] == arr[l])
            lookupTable[l][r][k] = max(lookupTable[l][r][k], solve(arr,l+1,a-1,0,lookupTable) + solve(arr,a,r,k+1,lookupTable));
    }  

    return lookupTable[l][r][k];
}