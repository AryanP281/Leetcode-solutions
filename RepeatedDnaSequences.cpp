
#include<bits/stdc++.h>

using namespace std;

vector<string> findRepeatedDnaSequences(string s);
int getEncd(char ch);

int main()
{
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    findRepeatedDnaSequences(s);
}

vector<string> findRepeatedDnaSequences(string s) 
{
    if(s.size() < 10)
        return {};

    int seq = 0;
    for(int i = 0; i < 10; ++i)
    {
        int encd = getEncd(s[i]);
        seq |= (encd << 2*i);
    }

    unordered_map<int,int> seqs;
    seqs[seq] = 1;

    for(int r = 10; r < s.size(); ++r)
    {
        seq = seq >> 2;
        seq |= getEncd(s[r]) << 18;
        seqs[seq]++;
    }

    vector<string> opt;
    for(auto itr = seqs.begin(); itr != seqs.end(); ++itr)
    {
        if(itr->second == 1)
            continue;

        string seqString = "";
        for(int i = 0; i < 10; ++i)
        {
            int encd = (itr->first >> 2*i) & 0b11;
            switch(encd)
            {
                case 0: seqString += 'A'; break;
                case 1: seqString += 'C'; break;
                case 2: seqString += 'G'; break;
                case 3: seqString += 'T'; break;
            }
        }

        opt.push_back(seqString);
    }

    return opt;
}

int getEncd(char ch)
{   
    int pos = 0;
    switch(ch)
    {
        case 'C': pos = 1; break;
        case 'G': pos = 2; break;
        case 'T': pos = 3; break;
    }

    return pos;
}