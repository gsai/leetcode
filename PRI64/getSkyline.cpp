#include <algorithm>
#include <functional>
#include <iterator>
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
		multimap<int, int> points;
		for (auto building : buildings)
		{
			points.emplace(building[0], building[2]);
			points.emplace(building[1], -building[2]);
		}

		multiset<int> heights = { 0 };
		map<int, int> coords;
		for (auto point : points)
		{
			if (point.second > 0)
				heights.insert(point.second);
			else
			{
				heights.erase(-point.second);
			}

			int currHeight = *(heights.rbegin());
			coords.insert(pair<int, int>(point.first, currHeight));
		}

		vector<pair<int, int> > result;
		function<bool(pair<int, int>, pair<int, int>)> opr = [](pair<int, int> lf, pair<int, int> rt){return lf.second == rt.second; };
		unique_copy(coords.begin(), coords.end(), back_insert_iterator<vector<pair<int, int> > >(result), opr);

		return result;
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