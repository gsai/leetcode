#include <algorithm>
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
		multimap<int, int> coords;
		for (auto building : buildings)
		{
			coords.insert(building[0], building[2]);
			coords.insert(-building[1], building[2]);
		}

		multiset<int> currs = { 0 };
		map<int, int> points;

		for (auto coord : coords)
		{
			if (coord.first > 0)
				currs.insert(coord.second);
			else
				currs.erase(coord.second);
			
			int h = *(currs.rbegin());
			pair<int, int> p(coord.first, h);
			points.insert(p);
		}
	}
};