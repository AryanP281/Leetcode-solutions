
#include<bits/stdc++.h>

using namespace std;


bool canConstruct(string s, int k);

int main()
{
    string str = "yzyzyzyzyzyzyzy";
    cout << canConstruct(str,2);

    getchar();
    return 0;
}

bool canConstruct(string s, int k) 
{
    //Palindromes cannot be constructed as enough letters are not available
    if(s.size() < k) return false;
    
    //Getting number of occurrences of each alpahbet
    int charCounts[26] = {0};
    for(int a = 0; a < s.size(); ++a)
    {
        charCounts[s[a] - 'a']++;
    }

    int emptyPalindromes = k; //The number of palindromes that are empty i.e do not have a single letter. Initially, all palindromes are empty
    int nonOddPalindromes = k; //The number of palindromes that do not have a middle character with occurrence = 1

    for(int a = 0; a < 26; ++a)
    {
        if(charCounts[a] == 0) continue;

        if(charCounts[a] % 2 == 0)
        {
            /*The the alphabet occurs even number of times, place all of its occurrences in one of the empty palindromes. 
            Hence, number of empty palindromes decreases by 1. If no empty palindrome is available, all of its occurrences can be
            placed in any of the non-empty palindromes.*/

            if(emptyPalindromes > 0)
                emptyPalindromes--;
        }
        else
        {
            /*If the alphabet occurs odd number of times, place all of its occurrences in one of the empty palindromes. Hence, number
            of empty palindromes decreases by one and as an odd character is placed, number of non odd palindromes also decreases
            by 1. If no non-empty palindrome is available, the alphabet can only be placed in a palindrome which does not already have
            an odd character. If no such palindrome is availabel i.e nonOddPalindromes==0, then it is not possible to construct K palindromes
            and we can return false*/
            
            if(emptyPalindromes > 0)
            {
                emptyPalindromes--;
                nonOddPalindromes--;
            }
            else
            {
                if(nonOddPalindromes == 0)
                    return false;
                nonOddPalindromes--;
            }
            
        } 
    }

    return true;
}
