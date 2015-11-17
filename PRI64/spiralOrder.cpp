#include <vector>

using std::vector;

class Solution
{
public:
	vector<int> spiralOrder(vector<vector<int>> &matrix)
	{
		vector<int> ans;

		int rowBegin = 0;
		int rowEnd = matrix.size() - 1;
		int colBegin = 0;
		int colEnd = matrix[0].size() - 1;

		while (rowBegin <= rowEnd && colBegin <= colEnd)
		{
			for (int j = colBegin; j <= colEnd; j++)
				ans.push_back(matrix[rowBegin][j]);
			rowBegin++;

			for (int i = rowBegin; i <= rowEnd; i++)
				ans.push_back(matrix[i][colEnd]);
			colEnd--;

			if (rowBegin <= rowEnd)
			{
				for (int j = colEnd; j >= colBegin; j--)
					ans.push_back(matrix[rowEnd][j]);
			}
			rowEnd--;

			if (colBegin <= colEnd)
			{
				for (int i = rowEnd; i >= rowBegin; i--)
					ans.push_back(matrix[i][colBegin]);
			}
			colBegin++;
		}
		return ans;
	}
};