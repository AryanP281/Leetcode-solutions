
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
int val;
ListNode *next;
ListNode() : val(0), next(nullptr) {}
ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* generateLL(vector<int>& arr)
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

void reorderList(ListNode* head);
ListNode* reverseLL(ListNode* head);

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7};
    ListNode* head = generateLL(arr);
    reorderList(head);

    for(ListNode* i = head; i; i = i->next)
    {
        cout << i->val << "->";
    }

    getchar();
    return 0;
}

void reorderList(ListNode* head) 
{
    if(!head->next || !head->next->next)
        return;

    ListNode* left = head;
    ListNode* right = head->next->next;

    while(right)
    {
        left = left->next;
        right = right->next ? right->next->next : right->next;
    }

    right = left->next;
    left->next = nullptr;
    right = reverseLL(right);

    left = head;
    
    ListNode* newHead = new ListNode();
    ListNode* currHead = newHead;
    while(left || right)
    {
        if(!left)
        {
            currHead->next = right;
            right = right->next;
            continue;
        }
        else if(!right)
        {
            currHead->next = left;
            left = left->next;
            continue;
        }

        currHead->next = left;
        left = left->next;
        currHead = currHead->next;
        currHead->next = right;
        right = right->next;
        currHead = currHead->next;
    }

    delete newHead;
}

ListNode* reverseLL(ListNode* head)
{
    if(!head)
        return nullptr;
    
    ListNode* currHead = head;

    while(head->next)
    {
        ListNode* temp = head->next->next;
        head->next->next = currHead;
        currHead = head->next;
        head->next = temp;
    }

    return currHead;
}