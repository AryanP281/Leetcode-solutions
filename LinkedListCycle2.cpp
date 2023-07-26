
#include<bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* createLL(vector<int>& arr);
ListNode* detectCycle(ListNode *head);
void deleteLL(ListNode* start);

int main()
{
    vector<int> arr = {1,2};
    ListNode* head = createLL(arr);
    ListNode* loopStart = detectCycle(head);
    cout << loopStart->val << '\n';

    //deleteLL(head);
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
    curr->next = start;

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

ListNode* detectCycle(ListNode *head) 
{
    if(!head || !head->next) return nullptr;
    
    ListNode* hare = head;
    ListNode* tortoise = head;

    while(hare && hare->next)
    {
        hare = hare->next->next;
        tortoise = tortoise->next;

        if(tortoise == hare) break;
    }

    if(tortoise != hare) return nullptr;

    tortoise = head;
    while(tortoise != hare)
    {
        tortoise = tortoise->next;
        hare = hare->next;
    }

    return tortoise;
}