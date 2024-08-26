#include<bits/stdc++.h>

using namespace std;

int strStr(string haystack, string needle);

int main()
{
    cout << strStr("abaababaababab","abaababab");


    getchar();
    return 0;
}

int strStr(string haystack, string needle) 
{
    //Generating KMP array
    int* kmpArr = new int[needle.size()]();
    int l = 0;
    int r = 1;
    while(r < needle.size())
    {
        if(needle[r] == needle[l])
        {
            kmpArr[r] = l+1;
            l++;
            r++;
        }
        else {
            if(l > 0)
                l = kmpArr[l-1];
            else
            {
                kmpArr[r] = 0;  
                r++;
            }
        }
    }

    //Matching with haystack
    int i = 0;
    for(int j = 0; j < haystack.size(); ++j)
    {
        if(haystack[j] == needle[i])
        {
            if(i == needle.size()-1)
                return (j+1)-needle.size();
            i++;
        }
        else if(i != 0)
        {
            i = kmpArr[i-1];
            while(i >= 0)
            {
                if(needle[i] == haystack[j])
                {
                    i++;
                    break;
                }
                else if(i == 0)
                    break;
                
                i = kmpArr[i-1];
            }
        }
    }

    delete[] kmpArr;

    return -1;        
}

/*
for(int r = 1; r < needle.size(); ++r)
    {
        if(needle[l] == needle[r])
        {
            kmpArr[r] = kmpArr[r-1] + 1;
            l++;
        }
        else
        {
            l = kmpArr[r-1];
            while(l >= 0)
            {
                if(l == 0)
                {
                    kmpArr[r] = 1*(needle[l] == needle[r]);
                    l += 1*(needle[l] == needle[r]);
                    break;
                }
                
                if(needle[l] == needle[r])
                {
                    kmpArr[r] = ++l;
                    break;
                }
                else
                    l = kmpArr[l-1];
            }
        }
    }
*/
