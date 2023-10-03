
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head);

ListNode* generateLL(vector<int>& arr, int cycleS)
{
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;

    for(int i = 1; i < arr.size(); ++i)
    {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }

    return head;
}

int main()
{
    vector<int> arr = {3,2,0,-4};
    ListNode* head = generateLL(arr);

    cout << (hasCycle(head) ? "True" : "False");

    getchar();
    return 0;
}

bool hasCycle(ListNode *head) 
{
    if(!head || !head->next)
        return false;

    ListNode* tortoise = head;
    ListNode* hare = tortoise->next->next;

    while(hare)
    {
        if(hare == tortoise)
            return true;

        tortoise = tortoise->next;
        hare = hare->next ? hare->next->next : nullptr;
    }   

    return false;     
}