
#include<bits/stdc++.h>

using namespace std;

bool hasAllCodes(string s, int k);

int main()
{
    string s = "01100";
    cout << hasAllCodes(s,2);

    getchar();
    return 0;
}

bool hasAllCodes(string s, int k) 
{
    if(k > s.size())
        return false;
    
    uint32_t window = 0;
    for(int i = 0; i < k; i++)
    {
        window |= (uint32_t)((s[i] - '0') << (k-i-1));
    }

    unordered_set<uint32_t> codes = {window};

    for(int r = k; r < s.size(); ++r)
    {
        window = window << 1;
        window &= (uint32_t)~(1 << k);
        window |= (uint32_t)(s[r] - '0');
        codes.insert(window);
    }

    return (codes.size() == pow(2,k));
}