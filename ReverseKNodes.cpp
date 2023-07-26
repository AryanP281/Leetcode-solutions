
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
ListNode* reverseKGroup(ListNode* head, int k);
void deleteLL(ListNode* start);

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    ListNode* head = createLL(arr);
    head = reverseKGroup(head,4);

    deleteLL(head);
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

void deleteLL(ListNode* start)
{
    while(start)
    {
        ListNode* temp = start;
        start = start->next;
        delete temp;
    }
}

ListNode* reverseKGroup(ListNode* head, int k) 
{
    auto groupExists = [k](ListNode* start) -> bool
    {
        ListNode* node = start;
        int i = 1;
        for(; i < k && node; ++i)
        {
            node = node->next;
        }

        return (i==k && node);
    };
    
    ListNode* start = new ListNode(-1);
    start->next = head;

    ListNode* currStart = start;
    while(currStart)
    {
        if(!groupExists(currStart->next)) break;
        
        ListNode* currNode = currStart->next->next;
        ListNode* prevNode = currStart->next;
        int a = 1;
        for(; a < k; ++a)
        {
            prevNode->next = currNode->next;
            currNode->next = currStart->next;
            currStart->next = currNode;

            currNode = prevNode->next;
        }

        currStart = prevNode;
    }

    ListNode* temp = start;
    start = start->next;
    delete temp;

    return start;
}

/*ListNode* reverseKGroup(ListNode* head, int k) 
{
    ListNode* currStart = new ListNode(-1);
    currStart->next = head;

    deque<ListNode*> kNodes;
    ListNode* prevNode = currStart;
    while(prevNode)
    {
        ListNode* currNode = prevNode->next;
        int a = 0;
        for(; a < k && currNode; ++a)
        {
            kNodes.push_back(currNode);
            currNode = currNode->next;
        }
        if(a != k) break;

        currNode = prevNode;
        prevNode = kNodes.front();
        while(kNodes.size() > 1)
        {
            ListNode* front = kNodes.front();
            kNodes.pop_front();
            ListNode* back = kNodes.back();
            kNodes.pop_back();

            ListNode* temp = back->next;
            currNode->next = back;

            if(!kNodes.empty())
            {
                kNodes.back()->next = front;
                back->next = front->next;
            }
            else
                back->next = front;
            front->next = temp;

            currNode = currNode->next;
        }
        if(kNodes.size() == 1) kNodes.pop_back();   
    }

    ListNode* temp = currStart;
    currStart = currStart->next;
    delete temp;

    return currStart;
}
*/