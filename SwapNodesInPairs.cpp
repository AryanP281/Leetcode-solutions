
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
ListNode* swapPairs(ListNode* head);
void deleteLL(ListNode* start);

int main()
{
    vector<int> arr = {1};
    ListNode* head = createLL(arr);
    head = swapPairs(head);

    deleteLL(head);
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

ListNode* swapPairs(ListNode* head) 
{
    ListNode* currStart = new ListNode(-1);
    ListNode* currPrev = currStart;
    currPrev->next = head;

    while(currPrev && currPrev->next && currPrev->next->next)
    {
        ListNode* temp = currPrev->next;
        currPrev->next = currPrev->next->next;
        temp->next = currPrev->next->next;
        currPrev->next->next = temp;

        currPrev = currPrev->next->next;
    }

    ListNode* swapped = currStart->next;
    delete currStart;

    return swapped;
}