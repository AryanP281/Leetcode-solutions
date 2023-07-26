
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
ListNode* rotateRight(ListNode* head, int k);
void deleteLL(ListNode* start);

int main()
{
    vector<int> arr = {1,2,3,4,5};
    ListNode* head = createLL(arr);
    head = rotateRight(head, 5);

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

ListNode* rotateRight(ListNode* head, int k) 
{
    if(!head) return nullptr;
    
    ListNode* start = new ListNode(-1,head);
    int n = 0;
    ListNode* end = start->next;
    while(end)
    {
        ++n;
        end = end->next;
    }

    int rotations = (k % n);

    ListNode* curr = start;
    for(int i = 0; i < n - rotations; ++i)
    {
        curr = curr->next;
    }

    ListNode* rotatedStart = start;
    while(curr->next)
    {
        ListNode* pluckedNode = curr->next;
        curr->next = pluckedNode->next;

        pluckedNode->next = rotatedStart->next;
        rotatedStart->next = pluckedNode;
        rotatedStart = pluckedNode;
    }

    ListNode* temp = start;
    start = start->next;
    delete temp;

    return start;
}   