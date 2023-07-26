
#include<bits/stdc++.h>

using namespace std;

struct ListNode 
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

int getLinkedListSize(ListNode* head);
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);

int main()
{
    vector<int> common = {};
    vector<int> aVals = {2,6,4};
    vector<int> bVals = {1,5};

    ListNode* headA, *headB, *headCommon;

    //headCommon = new ListNode(common[0]);
    headCommon = nullptr;
    ListNode* currNode = headCommon;
    for(int a = 1; a < common.size(); ++a, currNode = currNode->next)
    {
        currNode->next = new ListNode(common[a]);
    }

    headA = new ListNode(aVals[0]);
    currNode = headA;
    for(int a = 1; a < aVals.size(); ++a, currNode = currNode->next)
    {
        currNode->next = new ListNode(aVals[a]);
    }
    currNode->next = headCommon;

    headB = new ListNode(bVals[0]);
    currNode = headB;
    for(int a = 1; a < bVals.size(); ++a, currNode = currNode->next)
    {
        currNode->next = new ListNode(bVals[a]);
    }
    currNode->next = headCommon;

    cout << (getIntersectionNode(headA, headB))->val;

    getchar();
    return 0;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
    int aSize = getLinkedListSize(headA);
    int bSize = getLinkedListSize(headB);

    if(aSize > bSize)
    {
        for(int i = 0; i < aSize - bSize; ++i)
        {
            headA = headA->next;
        }
    }
    else if(bSize > aSize)
    {
        for(int i = 0; i < bSize - aSize; ++i)
        {
            headB = headB->next;
        }
    }

    while(headA && headB && headA != headB)
    {
        headA = headA->next;
        headB = headB->next;
    }

    return (headA == headB) ? headA : nullptr;
}

int getLinkedListSize(ListNode* head)
{
    ListNode* currNode = head;

    int size = 0;
    while(currNode)
    {
        size++;
        currNode = currNode->next;
    }

    return size;
}