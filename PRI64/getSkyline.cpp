#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <utility>

using namespace std;
class Solution
{
public:
	vector<pair<int, int> > getSkyline(vector<vector<int> > &buildings)
	{
		vector<pair<int, int> > points;
		for (auto building : buildings)
		{
			points.emplace_back(building[0], building[2]);
			points.emplace_back(building[1], -building[2]);
		}
		sort(points.begin(), points.end());

		set<int> heights;
		heights.insert(0);
		vector<pair<int, int> > results;
		for (auto point : points)
		{
			if (point.second > 0)
				heights.insert(point.second);
			else
				heights.erase(-point.second);

			int currHeight = *(heights.rbegin());
			results.emplace_back(point.first, currHeight);
		}
		vector<pair<int,int> >::iterator last=unique(results.begin(), results.end(), [](pair<int, int> lf, pair<int, int> rt){return lf.second == rt.second; });
		results.erase(last, results.end());
		return results;
	}
};

int main()
{
	vector<vector<int> > buildings_ = { { 2,9,10 }, { 3,7,15 }, { 5,12,12 }, { 15,20,10 }, { 19,24,8 } };
	Solution sln;
	vector<pair<int, int>> v = sln.getSkyline(buildings_);
	for (auto vi : v)
	{
		cout << vi.first << " " << vi.second << endl;
	}

	return 0;
}