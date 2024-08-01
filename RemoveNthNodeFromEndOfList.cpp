
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main()
{


    getchar();
    return 0;
}

ListNode* removeNthFromEnd(ListNode* head, int n) 
{
    ListNode* dummyStart = new ListNode(-1,head);

    //Finding the node to delete
    ListNode* itrSlow = dummyStart;
    ListNode* itrFast = dummyStart;
    int nodeCount = 1;
    int toDel = 0;
    while(true)
    {
        if(!itrFast->next)
        {
            int ll = nodeCount*2-1;
            toDel = ll - n + 1;
            break;
        }
        else if(!itrFast->next->next)
        {
            int ll = nodeCount*2;
            toDel = ll - n + 1;
            break;
        }
        else
        {
            itrFast = itrFast->next->next;
            itrSlow = itrSlow->next;
            nodeCount++;
        }
    }

    itrSlow = dummyStart;
    nodeCount = 1;
    while(itrSlow)
    {
        int nextNode = nodeCount+1;
        if(nextNode == toDel)
        {
            ListNode* nn = itrSlow->next;
            itrSlow->next = nn->next;
            delete nn;
            break;
        }
        
        itrSlow = itrSlow->next;
        nodeCount++;
    }

    return dummyStart->next;
}