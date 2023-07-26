
#include<bits/stdc++.h>

using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k);
int getPos(vector<vector<int>>& mtrx, int val);

int main()
{

    vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
    cout << kthSmallest(matrix, 8);

    getchar();
    return 0;
}

int kthSmallest(vector<vector<int>>& matrix, int k) 
{
    int l = matrix[0][0];
    int r = *(matrix.rbegin()->rbegin());

    while(l < r)
    {
        int mid = l + ((r-l)/2);
        int midPos = getPos(matrix, mid);

        if(midPos < k) l=mid+1;
        else r = mid;
    }

    return l;
}

int getPos(vector<vector<int>>& mtrx, int val)
{
    int pos = 0;
    int c = mtrx.size()-1;
    for(int r = 0; r < mtrx.size(); ++r)
    {
        while(c != -1 && mtrx[r][c] > val) c--;
        if(c == -1) break;
        pos += c+1;
    }

    return pos;
}