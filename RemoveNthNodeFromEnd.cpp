
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
ListNode* removeNthFromEnd(ListNode* head, int n);
void deleteLL(ListNode* start);

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7};
    ListNode* head = createLL(arr);

    head = removeNthFromEnd(head, 1);

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

ListNode* removeNthFromEnd(ListNode* head, int n) 
{
    ListNode* start = head;
    ListNode* end = head;

    for(int a = 1; a <= n;++a)
    {
        end = end->next;
    }
    if(!end)
    {
        //i.e n == size of ll
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    while(end->next)
    {
        start = start->next;
        end = end->next;
    }

    ListNode* temp = start->next;
    start->next = temp->next;
    delete temp;

    return head;
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

/*
ListNode* start = head;
    ListNode* end = head;

    int nodeCount = 1;
    while(end->next)
    {
        start = start->next;
        if(end->next->next)
        {
            end = end->next->next;
            nodeCount += 2;
        }
        else
        {
            end = end->next;
            nodeCount++;
        }
    }

    auto delNextNode = [](ListNode* prev) -> void
    {
        ListNode* temp = prev->next;
        prev->next = temp->next;
        delete temp;
    };

    if(n == nodeCount - 1)
    {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    else if(nodeCount % 2 == 0)
    {
        int median = (nodeCount / 2.0) + 1;
        if(n <= nodeCount - median)
        {
            for(int a = nodeCount - median; a != n+1; --a)
            {
                start = start->next;
            }
            delNextNode(start);
        }
        else
        {
            ListNode* currNode = head;
            for(int a = 1; a != (nodeCount - median - (n-median)) - 1; ++a)
            {
                currNode = currNode->next;
            }
            delNextNode(currNode);
        }
    }
    else
    {
        int median = ceil(nodeCount / 2.0);
        if(n <= nodeCount - median)
        {
            for(int a = nodeCount - median; a != n+1; --a)
            {
                start = start->next;
            }
            delNextNode(start);
        }
        else
        {
            ListNode* currNode = head;
            for(int a = 1; a != (nodeCount - median - (n-median)) - 1; ++a)
            {
                currNode = currNode->next;
            }
            delNextNode(currNode);
        }
    }
    

    return head;
*/