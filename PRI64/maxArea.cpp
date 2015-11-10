#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
	int maxArea(vector<int> &height)
	{
		int lf = 0, rt = height.size() - 1;
		int area = 0;
		while (lf < rt)
		{
			int h = min(height[lf], height[rt]);
			area=max(area, (rt - lf)*h);

			while (height[lf] <= h && lf < rt) lf++;
			while (height[rt] <= h && lf < rt) rt--;
		}
		return area;
	}
};