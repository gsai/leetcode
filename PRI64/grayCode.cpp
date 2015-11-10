#include <vector>

using namespace std;
class Solution
{
public:
	vector<int> grayCode(int n)
	{
		vector<int> result(1, 0);
		for (int i = 0; i < n; i++)
		{
			int curCount = result.size();

			while (curCount)
			{
				curCount--;
				int id = result[curCount];
				id += (1 << i);
				result.push_back(id);
			}
		}

		return result;
	}
};