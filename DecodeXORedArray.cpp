
#include<bits/stdc++.h>

using namespace std;

vector<int> decode(vector<int>& encoded, int first);

int main()
{   

    vector<int> encoded = {6,2,7,3};
    vector<int> decoded = decode(encoded, 4);

    for(int a = 0; a < decoded.size(); ++a)
    {
        cout << decoded[a] << ' ';
    }

    getchar();
    return 0;
}

vector<int> decode(vector<int>& encoded, int first) 
{
    vector<int> decoded;
    decoded.push_back(first);

    for(int i = 0; i < encoded.size();++i)
    {
        decoded.push_back(encoded[i] ^ *decoded.rbegin());
    }

    return decoded;
}