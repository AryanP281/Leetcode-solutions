
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
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
void deleteLL(ListNode* start);

int main()
{
    vector<int> arr1 = {1,2,4};
    vector<int> arr2 = {1,3,4};

    ListNode* l1 = createLL(arr1);
    ListNode* l2 = createLL(arr2);
    ListNode* sorted = mergeTwoLists(l1,l2);

    deleteLL(sorted);
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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
    ListNode* sortedStart = new ListNode(-1);
    ListNode* l1Curr = l1;
    ListNode* l2Curr = l2;
    
    ListNode* sortedCurr = sortedStart;
    while(l1Curr || l2Curr)
    {
        if(!l1Curr)
        {
            sortedCurr->next = l2Curr;
            l2Curr = l2Curr->next;
        }
        else if(!l2Curr)
        {
            sortedCurr->next = l1Curr;
            l1Curr = l1Curr->next;
        }
        else
        {
            if(l1Curr->val < l2Curr->val)
            {
                sortedCurr->next = l1Curr;
                l1Curr = l1Curr->next;
            }
            else
            {
                sortedCurr->next = l2Curr;
                l2Curr = l2Curr->next;
            }
        }
        

        sortedCurr = sortedCurr->next;
        sortedCurr->next = nullptr;
    }

    ListNode* temp = sortedStart;
    sortedStart = sortedStart->next;
    delete temp;

    return sortedStart;
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