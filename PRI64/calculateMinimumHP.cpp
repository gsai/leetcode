#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
	int calculateMinimumHP(vector<vector<int>> &dungeon)
	{
		int m = dungeon.size();
		int n = dungeon[0].size();

		vector<vector<int>> blood(m + 1, vector<int>(n + 1,INT_MAX));
		blood[m - 1][n] = 1;
		blood[m][n - 1] = 1;

		for (int i = m - 1; i >= 0; i--)
		{
			for (int j = n - 1; j >= 0; j--)
			{
				int need = min(blood[i + 1][j], blood[i][j + 1]) - dungeon[i][j];
				blood[i][j] = need <= 0 ? 1 : need;
			}
		}

		return blood[0][0];
	}
};