#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:

	bool wordBreak(string s, unordered_set<string> &wordDict)
	{
		if (s.empty() || wordDict.empty())
			return false;
		string::size_type length = s.size() + 1;
		vector<bool> estimate(length, false);
		estimate[0] = true;
		for (int i = 1; i < length; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (estimate[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end())
					estimate[i] = true;
			}
		}
		return estimate.back();
	}
};

