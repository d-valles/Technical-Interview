class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue <int, vector<int>, greater<int> > right;
    priority_queue <int> left;
    double median = NULL;
    
    MedianFinder() {

    }
    
    void addNum(int num) {               
        left.push(num);
        
        right.push(left.top());
        left.pop();
        
        if (left.size() < right.size()) {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        return left.size() > right.size() ? left.top() : (left.top() + right.top()) * 0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */