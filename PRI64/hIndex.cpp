#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int hIndex(vector<int> &citations)
	{
		if (citations.empty())
			return 0;
		vector<int>::size_type nums = citations.size();
		int h = 0;
		for (int i = 1; i < nums + 1; i++)
		{
			int count=count_if(citations.begin(), citations.end(), [i](int v){return v >= i; });
			h = (count >= i) ? i : h;
		}
		return h;
	}
};

