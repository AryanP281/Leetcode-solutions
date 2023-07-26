
#include<bits/stdc++.h>

using namespace std;

int longestPalindrome(vector<string>& words);

int main()
{
    vector<string> words = {"cc","ll","xx"};
    cout << longestPalindrome(words);

    getchar();
    return 0;
}

int longestPalindrome(vector<string>& words) 
{
    map<string,int> seenWords;

    map<string,int>::iterator itr;
    int palindromeCount = 0;
    for(int i = 0; i < words.size();++i)
    {
        string palindrome;
        palindrome += words[i][1];
        palindrome += words[i][0];

        itr = seenWords.find(palindrome);
        if(itr != seenWords.end())
        {
            palindromeCount += 2;
            itr->second--;
            if(!itr->second)
                seenWords.erase(itr);
        }
        else
            seenWords[words[i]]++;
    }

    for(itr = seenWords.begin(); itr != seenWords.end(); ++itr)
    {
        if((itr->first)[0] == (itr->first)[1])
        {
            palindromeCount++;
            break;
        }
    }

    return palindromeCount*2;    
}