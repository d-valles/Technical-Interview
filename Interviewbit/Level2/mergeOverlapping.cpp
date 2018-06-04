/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compareIntervals(Interval a, Interval b) {
    return a.start < b.start;
}

vector<Interval> Solution::merge(vector<Interval> &A) {
    vector<Interval> ans;
    if (!A.size()) return ans;

    sort(A.begin(), A.end(), compareIntervals);
    ans.push_back(A[0]);

    for(int i = 1; i < A.size(); i++) {
        Interval last = A[i-1];
        Interval current = A[i];

        if (current.start > last.end) {
            ans.push_back(current);
        } else if (current.end > last.end && current.start >= last.start) {
            ans[i-1].end = current.end;
        }
    }

    return ans;
}