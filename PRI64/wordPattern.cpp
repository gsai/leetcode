#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

class Solution
{
public:
	bool wordPattern(string pattern, string str)
	{
		vector<string> words;
		segment(str, words);

		if (pattern.size() != words.size())
			return false;

		int n = pattern.size();
		map<char, int> p2i;
		map<string, int> s2i;

		for (int i = 0; i < n; i++)
		{
			if (p2i[pattern[i]] != s2i[words[i]])
				return false;
			//��һ��Ҫע�⣬������i+1,i+2,.....�������ǿ��ܳ���0�ı��ʽ�������i,�Ǵ���ģ��ο� (abba : dog cat cat fish)
			p2i[pattern[i]] = s2i[words[i]] = i;
		}

		return true;
	}
	void segment(string s, vector<string> &dict)
	{
		istringstream iss(s);
		string item;
		while (iss>>item)
		{
			if (!item.empty())
				dict.push_back(item);
		}
	}
};

