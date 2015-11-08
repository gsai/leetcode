#include <cstdint>
#include <cmath>
using namespace std;

class Solution
{
public:
	uint32_t reverseBits(uint32_t n)
	{
		int ans = 0;
		for (int i = 0; i < 32; i++)
		{
			uint32_t mask = (1 << i);
			if (n & mask)
			{
				ans += static_cast<uint32_t>(pow(2, 31 - i));
			}
		}
		return ans;
	}
};