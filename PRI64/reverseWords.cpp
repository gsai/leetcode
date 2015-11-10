#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

class Solution
{
public:
	
	void reverseWords(string &s)
	{
		stack<string> words;
		istringstream iss(s);
		string item;
	
		while (iss >> item)
		{
			words.push(item);
		}
		
		s.clear();
		while (!words.empty())
		{
			s += words.top();
			s += " ";
			words.pop();
		}
		s = s.substr(0, s.size() - 1);
	}
};
//һЩСʵ��
class Solution2
{
public:
	bool bothSpaces(char a, char b)
	{
		return a == ' '&&b == ' ';
	}
	void split(string s, stack<string> &words)
	{
		//�����⣬Ҫ�޸�
	//	unique(s.begin(), s.end(), &Solution2::bothSpaces);
		cout << "unique:" << s << endl;

		if (s == " ")
			return;
		stringstream ss(s);
		string item;
		while (getline(ss,item,' '))
		{
			words.push(item);
		}
	}

	void reverseWords(string &s)
	{
		stack<string> dicts;
		split(s, dicts);
		s.clear();

		while (!dicts.empty())
		{
			s += dicts.top();
			dicts.pop();
		}
	}
};

