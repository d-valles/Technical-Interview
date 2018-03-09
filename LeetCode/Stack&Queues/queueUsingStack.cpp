class MyQueue {
public:
    stack<int> Queue;

    void reorder(int x) {
        stack<int> t;

        while(!Queue.empty()) {
            t.push(Queue.top());
            Queue.pop();
        }

        t.push(x);

        while(!t.empty()) {
            Queue.push(t.top());
            t.pop();
        }
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        (!Queue.empty()) ? reorder(x) : Queue.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int val = Queue.top();
        Queue.pop();
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        return Queue.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return Queue.empty();
    }
};