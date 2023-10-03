
#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head);

int main()
{

    getchar();
    return 0;
}

Node* copyRandomList(Node* head) 
{
    unordered_map<Node*,Node*> nodeMap;

    //Creating nodes
    for(Node* curr = head; curr; curr = curr->next)
    {
        nodeMap[curr] = new Node(curr->val);
    }

    //Making connections
    for(Node* curr = head; curr; curr = curr->next)
    {
        if(curr->next)
            nodeMap[curr]->next = nodeMap[curr->next];
        if(curr->random)
            nodeMap[curr]->random = nodeMap[curr->random];
    }

    return nodeMap[head];
}

Node* copyRandomList2(Node* head) 
{
    /*
        We first append the copied nodes to the original nodes to keep track of which copied nodes represent which original nodes. For eg,
        original: 1 -> 2 -> 3 
        manipulated: 1 -> 1copy -> 2 -> 2copy -> 3 -> 3copy

        We can then make the connections in the copied list by iteration
    */


    //Creating nodes
    for(Node* curr = head; curr; curr = curr->next->next)
    {
        Node* temp = curr->next;
        curr->next = new Node(curr->val);
        curr->next->next = temp;
    }

    //Making the random connections
    Node* newHead = head->next;
    for(Node* curr = head; curr; curr = curr->next->next)
    {
        if(curr->random)
            curr->next->random = curr->random->next;
    }

    //Making the sequential connections and breaking connections between copied and original nodes
    Node* curr = head;
    while(curr)
    {
        Node* temp = curr->next->next;
        if(curr->next->next)
            curr->next->next = curr->next->next->next;
        
        curr->next = temp;
        curr = temp;
    }

    return newHead;
}