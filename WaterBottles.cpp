
#include<bits/stdc++.h>

using namespace std;

int numWaterBottles(int numBottles, int numExchange);

int main()
{

    cout << numWaterBottles(2,3);

    getchar();
    return 0;
}

int numWaterBottles(int numBottles, int numExchange) 
{
    int bottlesDrunk = numBottles;
    int emptyBottles = numBottles;

    while(emptyBottles >= numExchange)
    {
        bottlesDrunk += (emptyBottles / numExchange);
        emptyBottles = (emptyBottles / numExchange) + (emptyBottles % numExchange);
    }

    return bottlesDrunk;   
}