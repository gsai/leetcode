
#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
	void getCharSet(string &s, unordered_set<char> &chSet)
	{
		for (char c : s)
		{
			chSet.insert(c);
		}
	}

	void getCharSet(unordered_set<string> &ss, unordered_set<char> &chSet)
	{
		for (auto s : ss)
		{
			for (char c : s)
			{
				chSet.insert(c);
			}
		}
	}

	bool judge(unordered_set<char> &min, unordered_set<char> &max)
	{
		for (auto ia : min)
		{
			if (max.find(ia) == max.end())
				return false;
		}
		return true;
	}

	vector<string> wordBreak(string s, unordered_set<string>& wordDict)
	{
		unordered_set<char> strSet;
		unordered_set<char> dictSet;
		getCharSet(s, strSet);
		getCharSet(wordDict, dictSet);
		if (judge(strSet, dictSet))
		{
			split(s, wordDict, "");
		}

		return lists;
	}

	void split(string s, unordered_set<string> &dict, string str)
	{
		if (s.length() == 0)
		{
			lists.push_back(str.substr(1));
		}
		else
		{
			for each (string var in dict)
			{
				if (var.compare(s.substr(0, var.length())) == 0)
				{
					string substr(s.substr(0, var.length()));
					string tmpstr = str + " " + substr;
					split(s.substr(var.length()), dict, tmpstr);
				}
			}
		}
	}

	vector<string> lists;
};

