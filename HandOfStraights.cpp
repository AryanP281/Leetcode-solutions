
#include<bits/stdc++.h>

using namespace std;

bool isNStraightHand(vector<int>& hand, int groupSize);

int main()
{
    vector<int> hand = {2,1};
    cout << isNStraightHand(hand, 2);

    getchar();
    return 0;
}

bool isNStraightHand(vector<int>& hand, int groupSize) 
{
    if(groupSize == 1)
        return true;
    
    map<int,int> cardCounts;
    for(int i = 0; i < hand.size(); ++i)
    {
        map<int,int>::iterator itr = cardCounts.find(hand[i]);
        if(itr == cardCounts.end())
            cardCounts[hand[i]] = 1;
        else
            itr->second++;
    }

    map<int,int>::iterator l,r;
    l = cardCounts.begin();
    r = next(l);
    int currGrpSize = 1;
    int grpMinCount = 1;
    while(r != cardCounts.end())
    {
        if(r->first - prev(r)->first != 1)
        {
            return false;
        }
        else if(currGrpSize == groupSize-1)
        {
            grpMinCount = min(grpMinCount, r->second);

            while(l != r)
            {
                l->second -= grpMinCount;
                l++;
                if(prev(l)->second == 0)
                    cardCounts.erase(prev(l));
            }
            r->second -= grpMinCount;
            r++;
            if(prev(r)->second == 0)
                cardCounts.erase(prev(r));

            if(!cardCounts.empty())
            {
                l = cardCounts.begin();
                r = next(l);
                grpMinCount = l->second;
                currGrpSize = 1;
            }
            else
                break;
            
        }
        else
        {
            grpMinCount = min(grpMinCount,r->second);
            currGrpSize++;
            r++;
        }
    }

    return cardCounts.empty();
}