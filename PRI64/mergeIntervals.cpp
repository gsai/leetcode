#include <algorithm>
#include <vector>
#include <iostream>
#include <set>

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
	vector<Interval> merge(vector<Interval>& intervals)
	{
		sort(intervals.begin(), intervals.end(), [](Interval lf, Interval rt){return lf.start < rt.start; });
		vector<Interval> results;
		if (intervals.empty())
			return results;
		int curStart = intervals.front().start;
		int curEnd = intervals.front().end;
		
		for (auto i : intervals)
		{
			if (i.start <= curEnd)
			{
				curEnd = max(i.end, curEnd);
			}
			else
			{
				Interval point(curStart, curEnd);
				results.push_back(point);
				curStart = i.start;
				curEnd = i.end;
			}
		}

		results.emplace_back(curStart, curEnd);
		return results;
	}
};

