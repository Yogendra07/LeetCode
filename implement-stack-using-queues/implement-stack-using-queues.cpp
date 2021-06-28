class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1;
    queue<int> q2;
    
    MyStack() 
    {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) 
    {
        q1.push(x);    
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() 
    {
        while(q1.size() != 1)
        {
            int val = q1.front();
            q1.pop();
            q2.push(val);
        }
        
        int ans = q1.front();
        q1.pop();
        
        while(!q2.empty())
        {
            int val1 = q2.front();
            q1.push(val1);
            q2.pop();
        }
        
        return ans;
    }
    
    /** Get the top element. */
    int top() 
    {
        return q1.back();    
    }
    
    /** Returns whether the stack is empty. */
    bool empty() 
    {
        return q1.size() == 0;    
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