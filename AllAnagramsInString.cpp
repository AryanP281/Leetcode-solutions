
#include<bits/stdc++.h>

using namespace std;

vector<int> findAnagrams(string s, string p);
bool isAnagram(int* stringLetters, int* windowLetters);

int main()
{
    findAnagrams("cbaebabacd", "abc");


    getchar();
    return 0;
}

vector<int> findAnagrams(string s, string p) 
{
    /**Uses sliding window**/
    
    if(s.size() < p.size()) return vector<int>();
    
    vector<int> res;

    int stringLetters[26] = {0};
    for(int a = 0; a < p.size(); ++a)
    {
        stringLetters[p[a] - 'a']++;
    }

    int windowLetters[26] = {0};
    for(int a = 0; a < p.size(); ++a)
    {
        windowLetters[s[a] - 'a']++;
    }
    if(isAnagram(stringLetters, windowLetters)) res.push_back(0);

    for(int a = p.size(); a < s.size(); ++a)
    {
        windowLetters[s[a - p.size()] - 'a']--;
        windowLetters[s[a] - 'a']++;
        if(isAnagram(stringLetters, windowLetters)) res.push_back(a - p.size()+1);
    }

    return res;
}

bool isAnagram(int* stringLetters, int* windowLetters)
{
    for(int a = 0; a < 26; ++a)
    {
        if(stringLetters[a] != windowLetters[a]) return false;
    }

    return true;
}