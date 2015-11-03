#include <iostream>

using namespace std;

class Solution
{
public:
	int mySqrt(int x)
	{
		long long low = 0;
		long long high = x;

		while (low <high)
		{
			long long mid = (high - low) / 2 + low;
			if (mid*mid == x)
				return mid;
			else if (mid*mid < x)
				low = mid + 1;
			else
				high = mid - 1;
		}
		
		return low*low > x ? (low-1): low;
	}
};

int main()
{
	Solution sln;
	cout << sln.mySqrt(2147483647) << endl;

	return 0;
}