/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
	vector<Interval> answer;
	
	int index = 0;

	while (index < intervals.size() && intervals[index].end < newInterval.start) {
		answer.push_back(intervals[index++]);
	}

	while (index < intervals.size() && intervals[index].start <= newInterval.end) {
		newInterval.start = min(newInterval.start, intervals[index].start);
		newInterval.end = max(newInterval.end, intervals[index].end);
		index++;
	}
	answer.push_back(newInterval);

	while (index < intervals.size() && intervals[index].start > newInterval.end) {
		answer.push_back(intervals[index++]);
	}

	return answer;
}


