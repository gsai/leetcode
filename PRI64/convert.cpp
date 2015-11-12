#include <numeric>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
	string convert(string s, int numRows)
	{
		vector<string> buffer(numRows);
		size_t len = s.size();
		int i = 0;
		int idx;
		while (i<len)
		{
			for (idx = 0; idx < numRows&&i < len; idx++)
				buffer[idx].push_back(s[i++]);

			for (idx = numRows - 2; idx >= 1&&i < len; idx--)
				buffer[idx].push_back(s[i++]);
		}
		return accumulate(buffer.begin(), buffer.end(),string(""));
	}
};

