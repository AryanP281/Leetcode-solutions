
#include<bits/stdc++.h>

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* createLL(vector<int>& arr);
void deleteLL(ListNode* start);

int main()
{

    getchar();
    return 0;
}

ListNode* createLL(vector<int>& arr)
{
    ListNode* start = new ListNode(arr[0]);
    ListNode* curr = start;
    for(int a = 1; a < arr.size(); ++a)
    {
        curr->next = new ListNode(arr[a]);
        curr = curr->next;
    }
    curr->next = nullptr;

    return start;
}

void deleteLL(ListNode* start)
{
    while(start)
    {
        ListNode* temp = start;
        start = start->next;
        delete temp;
    }
}

ListNode* deleteDuplicates(ListNode* head) 
{
    ListNode* start = new ListNode(-1,head);

    ListNode* prev = start;
    ListNode* currNode = head->next;
    while(prev->next)
    {
        int currVal = currNode->val;
        while(currNode && currNode->val = currVal)
        {

        }
    }

    ListNode* temp = start;
    start = start->next;
    delete temp;

    return start;
}