
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,string> Vec;

string intToRoman(int num);
Vec* getNextDigit(Vec* charValMap, int x);

int main()
{
    int integer;
    cin >> integer;
    getchar();

    cout << intToRoman(integer);

    getchar();
    return 0;
}

string intToRoman(int num) 
{
    Vec charValMap[] = {Vec(1, "I"), Vec(4, "IV"), Vec(5, "V"), Vec(9, "IX"), Vec(10, "X"), Vec(40, "XL"), Vec(50, "L"), 
    Vec(90, "XC"), Vec(100, "C"), Vec(400, "CD"), Vec(500, "D"), Vec(900, "CM"), Vec(1000, "M")};

    string roman = "";
    Vec* nextDigit;
    while(num > 0)
    {
        nextDigit = getNextDigit(charValMap, num);
        roman += nextDigit->second;
        num -= nextDigit->first;
    }

    return roman;
}

Vec* getNextDigit(Vec* charValMap, int x)
{
    int l = 0;
    int r = 12;
    int m;

    Vec* prev;
    while(l <= r)
    {
        m = (l+r) / 2;
        if(charValMap[m].first == x)
            return (charValMap + m);
        else if(charValMap[m].first < x)
        {
            prev = charValMap + m;
            l = m+1;
        }
        else
            r = m-1;
    }

    return prev;
}