
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> StackNode;

class MinStack 
{
private:
    forward_list<StackNode> stack;

public:
    MinStack() 
    {

    }
    
    void push(int val) 
    {
        if(stack.empty())
        {
            stack.push_front(StackNode(val,val));
            return;
        }

        stack.push_front(StackNode(val, min(val, stack.front().second)));    
    }
    
    void pop() 
    {
        stack.pop_front();    
    }
    
    int top() 
    {
        return stack.front().first;    
    }
    
    int getMin() 
    {
        return stack.front().second;    
    }
};

int main()
{
    MinStack ms;
    ms.push(-2);
    ms.push(0);
    ms.push(-3);
    cout << ms.getMin() << '\n';
    ms.pop();
    cout << ms.top() << '\n';
    cout << ms.getMin() << '\n';

    getchar();
    return 0;
}