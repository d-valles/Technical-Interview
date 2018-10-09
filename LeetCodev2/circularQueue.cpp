class MyCircularQueue {
private:
    vector<int> V;
    int front = 0;
    int back = 0;

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k):V(k + 1) {
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) return false;
         V[front] = value;
        front = (front + 1) % V.size();
        return true;       
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) return false;
        back = (back + 1) % V.size();
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (!isEmpty()) {
            return V[back];
        }
        
        return -1;
    }
    
    /** Get the last item from the queue. */
    int Rear() {
       if (!isEmpty()) {
           int b = (front + V.size() - 1) % V.size(); 
           return V[b];
       }
        
        return -1;
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
       return front == back;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        int next = (front + 1) % V.size();
        return next == back;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */