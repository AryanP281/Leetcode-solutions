/*
#include<iostream>
#include<deque>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void reorderList(ListNode* head)
{
    deque<ListNode*> nodes;

    ListNode* currentNode = head;
    while (currentNode)
    {
        nodes.push_back(currentNode);
        currentNode = currentNode->next;
    }

    ListNode* tail = nodes.front();
    nodes.pop_front();
    while (!nodes.empty())
    {
        tail->next = nodes.back();
        nodes.pop_back();
        tail = tail->next;
        if (!nodes.empty())
        {
            tail->next = nodes.front();
            nodes.pop_front();
            tail = tail->next;
            if (nodes.empty()) tail->next = nullptr;
        }
        else tail->next = nullptr;
    }
    

}

void main()
{
    ListNode* head = new ListNode(1);
    ListNode* currNode = head;
    for (int a = 2; a < 6; ++a, currNode = currNode->next)
    {
        currNode->next = new ListNode(a);
    }

    reorderList(head);
}
*/