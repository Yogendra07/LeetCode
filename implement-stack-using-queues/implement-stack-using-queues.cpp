class MyStack {
public:
    /** Initialize your data structure here. */
    deque<int> q;
    MyStack() 
    {
            
    }
    
    /** Push element x onto stack. */
    void push(int x) 
    {
        q.push_back(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() 
    {
        int val = q.back();
        q.pop_back();
        return val;
    }
    
    /** Get the top element. */
    int top() 
    {
        return q.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() 
    {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */