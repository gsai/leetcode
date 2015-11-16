#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
	void bfs(vector<vector<char>> &grid, int x, int y)
	{
		queue<pair<int, int>> q;
		q.emplace(x, y);

		while (!q.empty())
		{
			int idx = q.front().first;
			int idy = q.front().second;
			grid[idx][idy] = '#';

			int width = grid.size();
			int height = grid[0].size();

			q.pop();
			for (int i = 0; i < 4; i++)
			{
				if (idx + dx[i]>0 && idx + dx[i]<width && idy + dy[i]>0 && idy + dy[i]<height && grid[idx + dx[i]][idy + dy[i]] == '1')
					q.emplace(idx + dx[i], idy + dy[i]);
			}
		}
	}
	int numIslands(vector<vector<char>> &grid)
	{
		int islands = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[i].size(); j++)
			{
				if (grid[i][j] == '1')
				{
					bfs(grid, i, j);
					islands++;
				}
			}
		}
		return islands;
	}
private:
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
};