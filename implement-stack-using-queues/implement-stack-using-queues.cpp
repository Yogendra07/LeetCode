class MyStack 
{
public:
    /** Initialize your data structure here. */
    queue<int> q;
    MyStack() 
    {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) 
    {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() 
    {
        int n = q.size();
        int val = 0;
        n = n-1;
        while(n--)
        {
            val = q.front();
            q.pop();
            q.push(val);
        }
        
        val = q.front();
        q.pop();
        
        return val;
    }
    
    /** Get the top element. */
    int top() 
    {
        int n = q.size();
        int val = 0;
        
        while(n--)
        {
            val = q.front();
            q.pop();
            q.push(val);
        }
        
        return val;    
    }
    
    /** Returns whether the stack is empty. */
    bool empty() 
    {
        return q.size() == 0;    
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