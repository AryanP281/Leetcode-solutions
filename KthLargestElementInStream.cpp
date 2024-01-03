
#include<bits/stdc++.h>

using namespace std;

class KthLargest 
{
private:
    multiset<int> heap;
    int k;

public:
    KthLargest(int k, vector<int>& nums) 
    {
        this->k = k;

        sort(nums.begin(), nums.end());
        for(int i = nums.size()-1; i >= ((int)nums.size()-k) && i >= 0; i--)
        {
            heap.insert(nums[i]);
        }    
    }
    
    int add(int val) 
    {
        if(heap.size() < k)
            heap.insert(val);
        else if(val > *(heap.begin()))
        {
            heap.insert(val);
            heap.erase(heap.begin());
        }

        return *(heap.begin());    
    }
};

int main()
{
    vector<int> init = {5,-1}; 
    KthLargest kl(3, init);
    vector<int> additions = {2,1,-1,3,4};
    for(int i = 0; i < additions.size(); ++i)
    {
        cout << kl.add(additions[i]) << '\n';
    }

    getchar();
    return 0;
}

