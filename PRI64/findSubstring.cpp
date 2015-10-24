#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	string lengthOfLongestSubstring(string s)
	{
		int lastIndicates[256];
		for (int i = 0; i < 256; i++)
			lastIndicates[i] = -1;

		int len = 0;
		int start = 0;
		int curStart = 0;
		int curLen = 0;

		for (int i = 0; i < s.size(); i++)
		{
			char ch = s[i];
			if (lastIndicates[ch] < curStart)
			{
				curLen++;
				lastIndicates[ch] = i;
			}
			else
			{
				int lastIndex = lastIndicates[ch];
				curStart = lastIndex + 1;
				curLen = i - curStart + 1;
				lastIndicates[ch] = i;
			}

			if (curLen > len)
				len = curLen;
		}
		
		return s.substr(start, len);
	}
};

