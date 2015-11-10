#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
	vector<string> findRepeatedDnaSequence(string s)
	{
		vector<string> ans;
		if (s.length() <= 10)
			return ans;

		int n = s.length();
		map<string, int> tables;
		for (int i = 0; i < n - 9; i++)
		{
			tables[s.substr(i, 10)]++;
		}
		for (auto entry : tables)
		{
			if (entry.second>1)
				ans.push_back(entry.first);
		}
		return ans;
	}
};