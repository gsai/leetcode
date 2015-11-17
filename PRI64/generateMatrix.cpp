#include <vector>

using namespace std;

class Solution
{
public:
	vector<vector<int>> generateMatrix(int n)
	{
		vector<vector<int>> ans(n, vector<int>(n));
		int rowBegin = 0, rowEnd = n - 1;
		int colBegin = 0, colEnd = n - 1;
		int k = 1;

		while (rowBegin<=rowEnd && colBegin<=colEnd)
		{
			for (int j = colBegin; j <= colEnd; j++)
				ans[rowBegin][j] = k++;
			rowBegin++;

			for (int i = rowBegin; i <= rowEnd; i++)
				ans[i][colEnd] = k++;
			colEnd--;

			for (int j = colEnd; j >= colBegin; j--)
				ans[rowEnd][j] = k++;
			rowEnd--;

			for (int i = rowEnd; i >= rowBegin; i--)
				ans[i][colBegin] = k++;
			colBegin++;
		}

		return ans;
	}
};