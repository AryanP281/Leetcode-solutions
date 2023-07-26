/*
    Let Si = Subtext i
    S1 = AXB, Sk = CYD, S1=Sk, A=C, B=D
    Consider, A=D
    Thus, C=B, X=Y. Therefore, (A)(X)(B)......(C)(Y)(D) for the input string.
    This can be recursively extended for any substring of the input string.
*/



#include<bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 9;

int longestDecomposition(string text);
int getDecomp(int l, int r, string& txt);

int main()
{
    string text = "aaa";
    cout << longestDecomposition(text);

    getchar();
    return 0;
}

int longestDecomposition(string text) 
{
    return getDecomp(0, text.size()-1, text);
}

int getDecomp(int l, int r, string& text)
{
    if(l > r)
        return 0;
    else if(l==r)
        return 1;

    int64_t rollingHashes[2] = {0,0};
    int64_t leftHashPow = 1;

    for(int start = l, end = r; start < end; ++start, --end)
    {
        rollingHashes[0] = (rollingHashes[0] + (text[start] - 'a' + 1)*leftHashPow) % MOD;
        leftHashPow = (leftHashPow*31) % MOD;

        rollingHashes[1] = (rollingHashes[1] * 31) % MOD;
        rollingHashes[1] = (rollingHashes[1] + (text[end]-'a'+1)) % MOD;

        if(rollingHashes[0] == rollingHashes[1] && text.substr(l,start-l+1) == text.substr(end, r-end+1))
            return getDecomp(start+1, end-1, text) + 2;
    }

    return 1;
}


/*
int longestDecomposition(string text) 
{
    vector<vector<int>> dp(text.size(), vector<int>(text.size(), -1));
    for(int r = 0; r < text.size(); ++r)
    {
        dp[r][r] = 1;
    }

    return getDecomp(0, text.size()-1, text, dp);
}

int getDecomp(int l, int r, string& txt, vector<vector<int>>& dp)
{
    if(l > r)
        return 0;
    else if(dp[l][r] != -1)
        return dp[l][r];

    dp[l][r] = 1;
    int64_t rollingHashes[2] = {0,0};
    int64_t hash1Pow = 1;
    for(int start = l, end = r; start < end; start++,end--)
    {
        rollingHashes[0] = (rollingHashes[0] + ((txt[start] - 'a' + 1)*hash1Pow)) % MOD;
        hash1Pow = (hash1Pow*31) % MOD;

        rollingHashes[1] = (rollingHashes[1] * 31) % MOD;
        rollingHashes[1] = (rollingHashes[1] + (txt[end] - 'a' + 1)) % MOD;

        if(rollingHashes[0] == rollingHashes[1] && txt.substr(l, start-l+1) == txt.substr(end, r - end+1))
            dp[l][r] = max(dp[l][r], 2+getDecomp(start+1, end-1, txt, dp));
    }

    return dp[l][r];
}
*/