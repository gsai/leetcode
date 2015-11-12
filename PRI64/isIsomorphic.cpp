#include <string>
#include <map>

using namespace std;

class Solution
{
public:
	bool isIsomorphic(string s, string t)
	{
		map<char, int> s2i;
		map<char, int> t2i;
		int n = s.size();
		
		for (int i = 0; i < n; i++)
		{
			if (s2i[s[i]] != t2i[t[i]])
				return false;
			
			s2i[s[i]] = t2i[t[i]] = i + 1;
		}

		return true;
	}
};

