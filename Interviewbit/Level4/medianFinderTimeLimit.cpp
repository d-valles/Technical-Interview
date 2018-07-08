class MedianFinder {
public:
    /** initialize your data structure here. */
    multiset<double> balanceTree;
    int numberOfElements;
    
    MedianFinder() {
        balanceTree.clear();
        numberOfElements = 0;
    }
    
    void addNum(int num) {
        balanceTree.emplace(num);
        numberOfElements++;
    }
    
    double findMedian() {
        multiset<double>::iterator index1 = balanceTree.begin();
        multiset<double>::iterator index2 = balanceTree.begin();
        
        if (isOdd()) {
            advance(index1, getMedian());
            return *index1;
        } else {
            advance(index1, getMedian() - 1);
            advance(index2, getMedian());
            return (*index1 + *index2) / 2;
        }
        return NULL;
    }
    
    bool isOdd() {
        return numberOfElements % 2 != 0;
    }
    
    int getMedian() {
        return floor(numberOfElements / 2);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */