#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<vector<string> > groupAnagrams(vector<string>& strs)
	{
		vector<vector<string> > result;
		if (strs.empty())
			return result;

		sort(strs.begin(), strs.end());

		map<string, vector<string>> sv;
		for (string s : strs)
		{
			string copy(s);
			sort(copy.begin(), copy.end());

			if (sv.find(copy) == sv.end())
			{
				vector<string> vstr;
				sv.insert(pair<string, vector<string> >(copy, vstr));
			}
			sv[copy].push_back(s);
		}

		for (auto vec : sv)
		{
			result.push_back(vec.second);
		}

		return result;
	}
};

