#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
	bool isAnagram(string s, string t)
	{
		if (s.empty() || t.empty())
			return false;
		sort(s.begin(), s.end(), [](char a, char b){return a < b; });
		sort(t.begin(), t.end(), [](char a, char b){return a < b; });
		return s == t;
	}
};
