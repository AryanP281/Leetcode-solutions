
#include<bits/stdc++.h>

using namespace std;

int numberOfBeams(vector<string>& bank);

int main()
{
    vector<string> bank = {"000","111","000"};
    cout << numberOfBeams(bank);


    getchar();
    return 0;
}

int numberOfBeams(vector<string>& bank) 
{
    int prevDevices = 0;
    int currDevices = 0;
    int beams = 0;

    for(int r = 0; r < bank.size(); ++r)
    {
        currDevices = 0;
        for(int c = 0; c < bank[r].size(); ++c)
        {
            currDevices += 1*(bank[r][c] == '1');
        }

        beams += currDevices*prevDevices;
        prevDevices = currDevices*(currDevices != 0) + prevDevices*(currDevices == 0);
    } 

    return beams;       
}