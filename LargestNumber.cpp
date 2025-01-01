
#include<bits/stdc++.h>

using namespace std;

string largestNumber(vector<int>& nums);

int main()
{

    vector<int> nums = {432,43243};
    cout << largestNumber(nums);

    getchar();

    return 0;
}

string largestNumber(vector<int>& nums) 
{
    /*
        Let concatenation of two strings(nums) A and B be denoted by A+B. To prove correctness of custom comparator, need to prove transitivity
        i.e if (A+B) > (B+A) and (B+C) > (C+B), then (A+B) > (A+C).
    */
    
    auto cmp = [](int x, int y) -> bool {
        return (to_string(x) + to_string(y)) > (to_string(y) + to_string(x));
    };

    sort(nums.begin(), nums.end(), cmp);

    if (nums[0] == 0) return "0";

    string res = "";
    for(int i = 0; i < nums.size(); ++i)
    {
        res += to_string(nums[i]);
    }

    return res;
}