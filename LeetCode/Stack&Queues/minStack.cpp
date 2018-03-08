class MinStack {
public:
    stack<int> position;
    stack<int> value; 
    
    void push(int x) {
        position.push(x);
        if (value.empty() || getMin() >= x) {
            value.push(x);
        }
    }
    
    void pop() {
        int x = position.top();
        position.pop();
        
        if (!value.empty() && x == value.top()){
            value.pop();
        }
    }
    
    int top() {
        return position.top();
    }
    
    int getMin() {
        return value.top();
    }
};
// 8 2 3
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */