class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> myStack;
    
    /** Reorder elements to Stack order. */
    void reorder() {
        for(int i = 0; i < myStack.size() - 1; i++) {
            myStack.push(myStack.front());
            myStack.pop();
        }
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        myStack.push(x);
        reorder();
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int p = myStack.front();
        myStack.pop();
        return p;
    }
    
    /** Get the top element. */
    int top() {
        return myStack.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return myStack.empty();
    }
};

// 1 2
// 2 1

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */