
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

ListNode* mergeKLists(vector<ListNode*>& lists);
ListNode* insertNode(ListNode* node, ListNode* newParent);

int main()
{
    vector<vector<int>> vals = {{1,4,5},{1,3,4},{2,6}};
    vector<ListNode*> lists;
    for(int i = 0; i < vals.size(); ++i)
    {
        lists.push_back(generateLL(vals[i]));
    }

    ListNode* mergedHead = mergeKLists({});
    while(mergedHead)
    {
        cout << mergedHead->val << '\n';
        mergedHead = mergedHead->next;
    }

    getchar();
    return 0;
}

ListNode* mergeKLists(vector<ListNode*>& lists) 
{
    map<int,ListNode*> listMap;
    ListNode* mergedHead = new ListNode(INT_MIN);
    listMap[INT_MIN] = mergedHead;

    ListNode* currNode;
    map<int,ListNode*>::iterator itr;
    for(int i = 0; i < lists.size(); ++i)
    {
        currNode = lists[i];
        while(currNode)
        {
            itr = listMap.lower_bound(currNode->val);
            if(itr == listMap.end() || itr->first != currNode->val)
                itr--;
            
            ListNode* nextNode = insertNode(currNode, itr->second);
            listMap[currNode->val] = currNode;
            currNode = nextNode;
        }
    }

    return mergedHead->next;
}

ListNode* insertNode(ListNode* node, ListNode* newParent)
{
    ListNode* nextNode = node->next;
    
    node->next = newParent->next;
    newParent->next = node;

    return nextNode;
}