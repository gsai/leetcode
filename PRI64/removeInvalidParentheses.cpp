#include <set>
#include <string>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<string> removeInvalidParentheses(string s)
	{
		set<string> visited;
		queue<string> q;
		vector<string> ans;

		visited.insert(s);
		q.push(s);
		bool founded = false;

		while (!q.empty())
		{
			string curr = q.front();
			q.pop();

			if (isValid(curr))
			{
				ans.push_back(curr);
				founded = true;
			}

			if (founded) continue;

			for (int i = 0; i < curr.size(); i++)
			{
				if (curr[i] != '(' && curr[i] != ')') continue;

				string subStr = curr.substr(0, i) + curr.substr(i + 1);
				if (visited.find(subStr) != visited.end())
				{
					visited.insert(subStr);
					q.push(subStr);
				}
			}
		}
		return ans;
	}
private:
	bool isValid(string s)
	{
		int count = 0;
		for (auto c : s)
		{
			if (c == '(') count++;
			else
			{
				if (c == ')' && count-- <= 0) return false;
			}
		}
		return count == 0;
	}
};