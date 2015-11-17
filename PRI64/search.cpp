#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
	int search(vector<int> &nums, int target)
	{
		if (nums.empty()) return -1;

		int h = 0, t = nums.size() - 1;
		int mid;
		while (h < t)
		{
			mid = (h + t) / 2;
			if (nums[mid] > nums[t]) h = mid + 1;
			else  t = mid;
		}

		int rot = h;
		h = 0, t = nums.size() - 1;
		int realmid;
		while (h<=t)
		{
			mid = (h + t) / 2;
			realmid = (mid + rot) % nums.size();
			if (nums[realmid] == target) return realmid;
			if (nums[realmid] < target) h = mid + 1;
			else t = mid - 1;
		}

		return -1;
	}
};
