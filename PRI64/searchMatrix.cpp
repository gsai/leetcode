#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
	bool searchMatrix(vector<vector<int>> &matrix, int target)
	{
		int m = matrix.size();
		int n = matrix[0].size();
		int h = 0, t = m*n - 1;
		int mid, midVal;

		while (h < t)
		{
			mid = (h + t) / 2;
			midVal = matrix[mid / n][mid%n];
			if (midVal > target) t = mid - 1;
			else if (midVal < target) h = mid + 1;
			else return true;
		}
		return matrix[h / n][h%n] == target;
	}
};
