/*
The median divides the merged array into two halves - left & right. Thus, finding the leftmost element in the left half is equivalent to
finding the median and right half. Binary search can be used for this purpose.

We can perform binary search on the smaller array to get the elements from it that are included in the left half. Thus, the elements 
from the larger array will be its first (partitionSize - numElementsFromSmallerArray) elements.

Let l = 0 and r = size_smaller_array - 1
Then untill we find the solution we can get the middle element the currently considered range as -
m = (l+r) / 2
Thus the elements from 0 to m are assumed to belong to the left half of the merged array. Thus, the first (half_size - m) elements from
larger array will also be included in the left half.

Now, if the mth element from the smaller array is < the smallest element from larger array assumed to be in right half; and the largest
element from bigger array in left half is < the smallest element from smaller array assumed to be in right half, then we have found the partition and can thereby obtain the median

Else if mth element from the smaller array is > the smallest element from larger array assumed to be in right half, then the left half will include
fewer elements from smaller array and more from larger. Hence update - 
r = m-1

Else if largest element from bigger array in left half is > the smallest element from smaller array assumed to be in right half, then
more elements from smaller array need to be included in the left half. Hence update - 
l = m+1

In this way binary search can be used to determine the partition point.

*/

#include<bits/stdc++.h>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

int main()
{
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};

    cout << findMedianSortedArrays(nums1,nums2);

    getchar();
    return 0;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
    vector<int>& smallerArr = nums1.size() < nums2.size() ? nums1 : nums2;
    vector<int>& largerArr = smallerArr == nums1 ? nums2 : nums1;
    int partitionSize = floor((float)(smallerArr.size() + largerArr.size())/2.0f);
    int l = 0;
    int r = smallerArr.size()-1;

    while(true)
    {
        int smallArrEndIndex = floor((float)(l+r) / 2.0f);
        int largeArrEndIndex = partitionSize - smallArrEndIndex - 2;

        int smallLeft = smallArrEndIndex >= 0 ? smallerArr[smallArrEndIndex] : INT_MIN;
        int smallRight = smallArrEndIndex + 1 < smallerArr.size() ? smallerArr[smallArrEndIndex+1] : INT_MAX;
        int bigLeft = largeArrEndIndex >= 0 ? largerArr[largeArrEndIndex] : INT_MIN;
        int bigRight = largeArrEndIndex + 1 < largerArr.size() ? largerArr[largeArrEndIndex+1] : INT_MAX;

        if(smallLeft <= bigRight && bigLeft <= smallRight)
        {
            if(((smallerArr.size() + largerArr.size()) % 2) == 0)
                return ((double)(max(smallLeft,bigLeft) + min(smallRight, bigRight)) / 2.0);
            else
                return min(smallRight, bigRight);
        }
        else if(smallLeft > bigRight)
            r = smallArrEndIndex-1;
        else
            l = smallArrEndIndex+1;
    }
}