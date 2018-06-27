long long int getMaxChocolate(int A, priority_queue<int>& maxHeap) {
    long long int sumOfChocolates = 0;
    long long int mod = 1000000007;
    
    for (int i = 0; i < A; i++) {
        long long int bestPosibleBag = maxHeap.top();
        maxHeap.pop();
        
        long long int newBag = floor(bestPosibleBag / 2);
        maxHeap.push(newBag);
        
        sumOfChocolates += bestPosibleBag;
        sumOfChocolates %= mod;
    }
    return sumOfChocolates;
}

int Solution::nchoc(int A, vector<int> &B) {
    priority_queue<int> maxHeap;
    for (int i = 0; i < B.size(); i++) {
        maxHeap.push(B[i]);
    }
    return getMaxChocolate(A, maxHeap);
}