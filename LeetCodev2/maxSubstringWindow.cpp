class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> Q;
        vector<int> answer;
        
        if (!nums.size()) return answer;
        
        for (int i = 0; i < nums.size(); i++) {    
            if (i >= k) {
                answer.push_back(nums[Q.front()]);    
            }  
            while(!Q.empty() && nums[Q.back()] <= nums[i]) {
                Q.pop_back();
            }
            
            while(!Q.empty() && Q.front() <= i - k) {
                Q.pop_front();
            }
            
            Q.push_back(i);    
        }

        answer.push_back(nums[Q.front()]);            
        return answer;
    }
};