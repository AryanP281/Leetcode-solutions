
/* Proof By Contradiction
 Using left = 0 and right = N-1 pointer; ++left if A[left] < A[right] otherwise --right
○ Proof by contradiction, say, (x, y) forms the optimal max water where x  < y and A[x] < A[y], then there are 2 cases
	1. left arrives at x first
		i) --right already happened at y. So some w on left of x had resulted in --right at y i.e w < x and A[w] > A[y]. In this case (w, y) will form greater than optimal area. Contradiction!
		ii) Or, ++left happened at x before y is visited,  this means for x we found a z on right of y i.e. y < z and A[x] < A[z] then (x, z) will form greater than optimal area. Contradiction!
	2. right arrives at x first
		i. --right had already happened at y before right comes to x. so 1. i) case
○ Similar proof for x < y and  A[x] > A[y], then there are two cases
	1. right arrives at y first
		i. ++left had already happened at  x for some z before right arrives at y such that y < z and A[x] < A[z]; Here (x, z) will form greater than optimal area. Contradiction!
		ii. --right happens at y before x is visited so some w at w < x must have triggered this such that w < x and A[w] > A[y]. Here (w, y) will form greater than optimal area. Contradiction!
	2. left arrives at y first
		i. ++left had already happends. So 1) i) case
○ Not equal to is omitted i.e. A[left] <= A[right] for easier understanding. But it works the same.
*/

#include<bits/stdc++.h>

using namespace std;

int maxArea(vector<int>& height);

int main()
{

    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(height);

    getchar();
    return 0;
}

int maxArea(vector<int>& height) 
{
    int bestArea = 0;

    for(int l = 0, r = height.size()-1; l < r;)
    {
        bestArea = max(bestArea, min(height[l],height[r]) * (r-l));

        if(height[l] < height[r])
            l++;
        else if(height[l] > height[r])
            r--;
        else
        {
            l++;
            r--;
        }
    }

    return bestArea;
}