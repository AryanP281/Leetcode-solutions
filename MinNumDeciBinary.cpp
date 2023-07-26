
#include<bits/stdc++.h>

using namespace std;

int minPartitions(string n);

int main()
{
    cout << minPartitions("82734");
    getchar();
    return 0;
}

int minPartitions(string n) 
{
    int maxDig = 0;
    for(int a = 0; a < n.size(); ++a)
    {
        int dig = n[a] - '0';
        maxDig = maxDig < dig ? dig : maxDig;
    }

    return maxDig;
}