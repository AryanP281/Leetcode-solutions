
#include<bits/stdc++.h>

using namespace std;

string getHappyString(int n, int k);
void generateHappyString(int n, int k, string& happyString);

int main()
{
    cout << getHappyString(10,100);

    getchar();
    return 0;
}

string getHappyString(int n, int k) 
{
    int stringsCount = 3 * pow(2,n-1);
    if(k > stringsCount)
        return "";
    
    string happyString = "";
    generateHappyString(n,k,happyString);

    return happyString;
}

void generateHappyString(int n, int k, string& happyString)
{
    if(n == 0)
        return;

    double pw = pow(2,n-1);
    int offset = min(3,(int)ceil((double)k/pw));
    int offsetPrev = (int)floor((double)k/pw);

    char alphabet[3] = {'a','b','c'};
    int ch = -1;
    for(int i = 0; i < offset; ch = (ch+1) % 3)
    {
        if(happyString.size() && alphabet[ch+1] == *happyString.rbegin())
            continue;
        i++;
    }
    happyString += alphabet[ch];

    if(offset == offsetPrev)
    {
        for(int i = n-1; i > 0; --i)
        {
            if(happyString.size() && *happyString.rbegin() == 'c')
                happyString += 'b';
            else
                happyString += 'c';
        }
    }
    else
        generateHappyString(n-1,k-(pw*offsetPrev), happyString);
}