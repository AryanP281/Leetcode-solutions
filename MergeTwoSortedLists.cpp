
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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);

int main()
{
    vector<int> l1 = {0};
    vector<int> l2 = {};

    ListNode* h1 = generateLL(l1);
    //ListNode* h2 = generateLL(l2);

    ListNode* merged = mergeTwoLists(h1,nullptr);

    for(ListNode* i = merged; i; i = i->next)
    {
        cout << i->val << "->";
    }

    getchar();
    return 0;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
{
    //Creating a dummy head
    ListNode* mergedHead = new ListNode();
    ListNode* currNode = mergedHead;

    ListNode* l1 = list1;
    ListNode* l2 = list2;
    while(l1 || l2)
    {
        if(!l1 || (l2 && l1->val >= l2->val))
        {
            currNode->next = l2;
            l2 = l2->next; 
        }
        else if(!l2 || (l1 && l2->val >= l1->val))
        {
            currNode->next = l1;
            l1 = l1->next;
        }

        currNode = currNode->next;
    }

    return mergedHead->next;
}