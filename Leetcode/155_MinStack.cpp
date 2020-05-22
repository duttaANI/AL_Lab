class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stack1;
    stack<int> min_stack;
    
    void push(int x) {
        stack1.push(x);
        if(min_stack.empty() || x<=min_stack.top() ) min_stack.push(x);
    }
    
    void pop() {
        if( stack1.top() == min_stack.top() ) min_stack.pop();
        stack1.pop();
    }
    
    int top() {
        return stack1.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */