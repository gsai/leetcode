#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

struct Interval
{
	int start;
	int end;
	Interval() :start(0), end(0){}
	Interval(int s, int e) :start(s), end(e){}
};
class Solution
{
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
	{
		int idx = 0;
		int n = intervals.size();
		vector<Interval> ans;

		while (idx<n && intervals[idx].end<newInterval.start)
		{
			ans.push_back(intervals[idx]);
			idx++;
		}

		while (idx<n && intervals[idx].start<=newInterval.end)
		{
			newInterval.start = min(intervals[idx].start, newInterval.start);
			newInterval.end = max(intervals[idx].end, newInterval.end);
			idx++;
		}
		ans.push_back(newInterval);

		while (idx <n)
		{
			ans.push_back(intervals[idx]);
		}
		return ans;
	}
};

