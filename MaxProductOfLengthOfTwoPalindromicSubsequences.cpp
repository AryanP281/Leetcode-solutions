
#include<bits/stdc++.h>

using namespace std;

int maxProduct(string s);
bool isPalindromic(uint16_t subSeq, string& str);
int getSetBits(uint16_t x);

int main()
{
    cout << maxProduct("accbcaxxcxx");

    getchar();
    return 0;
}

int maxProduct(string s) 
{
    unordered_set<uint16_t> palindromicSubseqs;

    uint16_t lim = pow(2,s.size()) - 1;
    for(uint16_t subSeq = 1; subSeq < lim; subSeq++)
    {
        if(isPalindromic(subSeq, s))
            palindromicSubseqs.insert(subSeq);
    }

    int maxLenProd = 1;
    for(unordered_set<uint16_t>::iterator itr1 = palindromicSubseqs.begin(); itr1 != palindromicSubseqs.end(); ++itr1)
    {
        uint16_t sseq1 = *itr1;
        for(unordered_set<uint16_t>::iterator itr2 = next(itr1); itr2 != palindromicSubseqs.end(); ++itr2)
        {
            uint16_t sseq2 = *itr2;
            if((sseq1 & sseq2) == 0)
                maxLenProd = max(maxLenProd, getSetBits(*itr1) * getSetBits(*itr2));
        }
    }

    return maxLenProd;
}

bool isPalindromic(uint16_t subSeq, string& str)
{
    string subSeqStr = "";
    for(int i = 0; i < str.size(); ++i)
    {
        if(subSeq & (1 << i))
            subSeqStr += str[i];
    }

    for(int l = 0, r = subSeqStr.size()-1; l <= r; l++,r--)
    {
        if(subSeqStr[l] != subSeqStr[r])
            return false;
    }

    return true;
}

int getSetBits(uint16_t x)
{
    int bitsCount = 0;
    for(int i = 0; i < 16; ++i)
    {
        bitsCount += (x & (1 << i)) >> i;
    }

    return bitsCount;
}