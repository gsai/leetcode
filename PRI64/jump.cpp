#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
	//time limited
	int jump(vector<int> &nums)
	{
		int n = nums.size();
		int index;
		for (int i = n - 1; i > -1; i--)
		{
			if (i + nums[i] >= n - 1)
				index = i;
		}
		if (index == 0)
			return 1;
		vector<int> v(nums.begin(), nums.begin() + index+1);
		return 1+jump(v);
	}
	//someone tell me use BFS
	int jumpBFS(vector<int> &nums)
	{
		
	}
};

