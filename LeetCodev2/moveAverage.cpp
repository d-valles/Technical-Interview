class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        actualSize = size;
    }
    
    double next(int val) {
        if (D.size() == actualSize) {
            int t = D.front();
            D.pop_front();
            actualSum -= t;
        }
        D.push_back(val);
        actualSum += val;
        return actualSum / D.size();
    }
    
private:
    double actualSum;
    int actualSize;
    deque<int> D;
};
