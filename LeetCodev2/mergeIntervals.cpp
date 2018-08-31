/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool sortFunction (Interval i , Interval j) {
        return i.start < j.start;
    }
    
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> answer;
        
        if (!intervals.size() || intervals.size() == 1) return intervals;
            
        sort(intervals.begin(), intervals.end(), sortFunction);
        Interval lastI = intervals[0];
        
        for (int i = 1; i < intervals.size(); i++) {
            
            Interval current = intervals[i];
            
            if (lastI.end < current.start) {
                answer.push_back(lastI);
                lastI = current;
            } else {
                lastI.start = min(lastI.start, current.start);
                lastI.end = max(lastI.end, current.end);
            }
                
            if (intervals.size() - 1 == i) {
                answer.push_back(lastI);
            }
        }
        
        return answer;
    }
};