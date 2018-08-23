class Solution {
public:    
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return !(rec2[2] <= rec1[0] || rec1[2] <= rec2[0] || rec2[1] >= rec1[3] || rec1[1] >= rec2[3]);
    }
};

/*
Solution 2
class Solution {
public:    
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int left = max(rec1[0], rec2[0]);
        int right = min(rec1[2], rec2[2]);
        int top = min(rec1[3], rec2[3]);
        int bottom = max(rec1[1], rec2[1]);       
        return left < right && bottom < top ? true : false;
    }
};
*/