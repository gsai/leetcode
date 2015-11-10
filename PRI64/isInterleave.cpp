#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isInterleave(string s1, string s2, string s3)
	{
		if (s3.length() != (s1.length() + s2.length()))
			return false;
		
		vector<vector<bool> > tables;
		for (int i = 0; i < s1.length() + 1; i++)
		{
			for (int j = 0; j < s2.length() + 1; j++)
			{
				if (i == 0 && j == 0)
					tables[i][j] = true;
				else if (i == 0)
					tables[i][j] = tables[i][j - 1] && s2[j - 1] == s3[i + j - 1];
				else if (j == 0)
					tables[i][j] = tables[i - 1][j] && s1[i - 1] == s3[i + j - 1];
				else
					tables[i][j] = tables[i - 1][j] && s1[i - 1] == s3[i + j - 1] || tables[i][j - 1] && s2[j - 1] == s3[i + j - 1];
			}
		}
		return tables[s1.length()][s2.length()];
	}
};