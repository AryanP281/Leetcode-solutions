
#include<bits/stdc++.h>

using namespace std;

int romanToInt(string s);

int main()
{
    string roman;
    cin >> roman;
    getchar();

    cout << romanToInt(roman);

    getchar();
    return 0;
}

int romanToInt(string s) 
{
    int integer = 0;

    for(int i = 0; i < s.size(); ++i)
    {
        switch(s[i]) 
        {
            case 'I': {
                if(i != s.size()-1)
                {
                    if(s[i+1] == 'V')
                        integer += 4;
                    else if(s[i+1] == 'X')
                        integer += 9;
                    else
                        integer++;
                    i += 1*(s[i+1] == 'V' || s[i+1] == 'X');
                }
                else
                    integer++;
            }; break;
            case 'V': integer += 5; break;
            case 'X': {
                if(i != s.size()-1)
                {
                    if(s[i+1] == 'L')
                        integer += 40;
                    else if(s[i+1] == 'C')
                        integer += 90;
                    else
                        integer += 10;
                    i += 1*(s[i+1] == 'L' || s[i+1] == 'C');
                }
                else
                    integer += 10;
            }; break;
            case 'L': integer += 50; break;
            case 'C': {
                if(i != s.size()-1)
                {
                    if(s[i+1] == 'D')
                        integer += 400;
                    else if(s[i+1] == 'M')
                        integer += 900;
                    else
                        integer += 100;
                    i += 1*(s[i+1] == 'D' || s[i+1] == 'M');
                }
                else
                    integer += 100;
            }; break;
            case 'D': integer += 500; break;
            case 'M': integer += 1000; break;
        }
    }

    return integer;    
}