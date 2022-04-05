class MinStack
{
public:
    stack <int> pushedElements, minElements;

    MinStack(){}
    
    void push(int val)
    {
        pushedElements.push(val);
        if (minElements.empty() or val <= minElements.top())
            minElements.push(val);
    }
    
    void pop()
    {
        int val = pushedElements.top();
        pushedElements.pop();
        if (minElements.top() == val)
            minElements.pop();
    }
    
    int top()
    {
        return pushedElements.top();
    }
    
    int getMin()
    {
        return minElements.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */