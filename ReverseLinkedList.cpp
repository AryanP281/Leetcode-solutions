
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
int val;
ListNode *next;
ListNode() : val(0), next(nullptr) {}
ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head);

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

int main()
{
    vector<int> arr = {1,2};
    ListNode* head = generateLL(arr);
    ListNode* reversedHead = reverseList(head);

    getchar();
    return 0;
}

ListNode* reverseList(ListNode* head) 
{
    if(head == nullptr)
        return nullptr;

    ListNode* currHead = head;
    while(head->next != nullptr)
    {
        ListNode* tempNode = head->next->next;
        head->next->next = currHead;
        currHead = head->next;
        head->next = tempNode;
    }        

    return currHead;
}