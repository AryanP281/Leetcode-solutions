
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

class CompareNode
{
public :
    bool operator()(ListNode* x, ListNode* y)
    {
        return x->val > y->val;
    }
};

ListNode* createLL(vector<int>& arr);
ListNode* mergeKLists(vector<ListNode*>& lists);
void deleteLL(ListNode* start);

int main()
{
    vector<vector<int>> arrs = {{1,4,5}, {1,3,4}, {2,6}};
    vector<ListNode*> lists = {nullptr};
    /*for(int a = 0; a < arrs.size(); ++a)
    {
        lists.push_back(createLL(arrs[a]));
    }*/
    ListNode* sorted = mergeKLists(lists);

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

ListNode* mergeKLists(vector<ListNode*>& lists) 
{
    if(lists.empty()) return nullptr;
    
    ListNode* sortedStart = new ListNode(-1);
    
    priority_queue<ListNode*,vector<ListNode*>,CompareNode> nodes;
    for(vector<ListNode*>::iterator itr = lists.begin(); itr != lists.end(); ++itr)
    {
        if(*itr != nullptr) nodes.push(*itr);
    }

    ListNode* sortedCurr = sortedStart;
    while(!nodes.empty())
    {
        ListNode* node = nodes.top();
        nodes.pop();

        sortedCurr->next = node;
        if(node->next) nodes.push(node->next);
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