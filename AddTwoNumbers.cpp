
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
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
void deleteLL(ListNode* start);

int main()
{
    vector<int> l1Arr = {0};
    vector<int> l2Arr = {0};

    ListNode* l1 = createLL(l1Arr);
    ListNode* l2 = createLL(l2Arr);

    ListNode* sum = addTwoNumbers(l1, l2);

    deleteLL(l1);
    deleteLL(l2);
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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{   
    int carry = 0;
    auto add = [&carry](ListNode* x, ListNode* y) -> int
    {
        int sum = x->val + y->val + carry;
        carry = sum / 10;

        return sum % 10;
    };

    ListNode* sumStart = new ListNode(add(l1,l2));
    ListNode* sumCurr = sumStart;
    ListNode* l1Curr = l1->next;
    ListNode* l2Curr = l2->next;
    while(l1Curr || l2Curr)
    {
        if(!l1Curr)
        {
            int sum = l2Curr->val + carry;
            sumCurr->next = new ListNode(sum % 10);
            carry = sum / 10;
            l2Curr = l2Curr->next;
        }
        else if(!l2Curr)
        {
            int sum = l1Curr->val + carry;
            sumCurr->next = new ListNode(sum % 10);
            carry = sum / 10;
            l1Curr = l1Curr->next;
        }
        else
        {
            int tempCarry = carry;
            sumCurr->next = new ListNode(add(l1Curr,l2Curr));
            l1Curr = l1Curr->next;
            l2Curr = l2Curr->next;
        }

        sumCurr = sumCurr->next;
    }
    if(!carry) sumCurr->next = nullptr;
    else
    {
        sumCurr->next = new ListNode(carry);
        sumCurr->next->next = nullptr;
    }

    return sumStart;
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