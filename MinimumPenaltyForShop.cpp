
#include<bits/stdc++.h>

using namespace std;

int bestClosingTime(string customers);

int main()
{
    string custs = "YYNY";
    cout << bestClosingTime(custs);

    getchar();
    return 0;
}

int bestClosingTime(string customers) 
{
    int closePenalty = 0;
    int openPenalty = 0;

    for(int i = 0; i < customers.size(); ++i)
    {
        closePenalty += 1*(customers[i] == 'Y');
    }

    int minPenalty = closePenalty;
    int optimalClosingHour = 0;
    for(int i = 0; i < customers.size(); ++i)
    {
        openPenalty += 1*(customers[i] == 'N');
        closePenalty -= 1*(customers[i] == 'Y');
        if(openPenalty+closePenalty < minPenalty)
        {
            minPenalty = openPenalty+closePenalty;
            optimalClosingHour = i+1;
        }
    }

    return optimalClosingHour;        
}