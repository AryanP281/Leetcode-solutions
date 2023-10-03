
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

ListNode* reverseKGroup(ListNode* head, int k);
vector<ListNode*> reverseLL(ListNode* head);

int main()
{
    vector<int> arr = {1,2,3,4,5};
    ListNode* head = generateLL(arr);
    ListNode* reversedHead = reverseKGroup(head, 3);
    while(reversedHead)
    {
        cout << reversedHead->val << "->";
        reversedHead = reversedHead->next;
    }

    getchar();
    return 0;
}

ListNode* reverseKGroup(ListNode* head, int k) 
{
    ListNode* dummyHead = new ListNode(-1);
    dummyHead->next = head;
    ListNode* left = dummyHead;
    ListNode* right = head;
    ListNode* next;

    int currCount = 1;
    while(right)
    {
        while(right && currCount < k)
        {
            right = right->next;
            currCount++;
        }
        
        if(right)
        {
            next = right->next;
            right->next = nullptr;

            vector<ListNode*> reversedSegment = reverseLL(left->next);
            left->next = reversedSegment[0];
            reversedSegment[1]->next = next;
            right = next;
            left = reversedSegment[1];
            currCount = 1;
        }
    }   

    return dummyHead->next;
}

vector<ListNode*> reverseLL(ListNode* head)
{
    ListNode* currHead = head;
    while(head->next != nullptr)
    {
        ListNode* tempNode = head->next->next;
        head->next->next = currHead;
        currHead = head->next;
        head->next = tempNode;
    }        

    return {currHead,head};
}