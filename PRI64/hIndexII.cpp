#include <vector>

using namespace std;

class Solution
{
public:
	int hIndex(vector<int> &citations)
	{
		int left = 0, len = citations.size(), right = len - 1;
		int mid;

		while (left <= right)
		{
			mid = (left + right) / 2;
			if (citations[mid] == (len-mid)) return citations[mid];
			else if (citations[mid] > (len - mid)) right = mid - 1;
			else left = mid + 1;
		}
		return len - (right + 1);
	}
};