#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution
{
public:
	void split(const string s,char dilim,vector<string> &elems)
	{
		stringstream ss(s);
		string item;
		while (getline(ss, item, dilim))
		{
			elems.push_back(item);
		}
	}
	string simplifyPath(string path)
	{
		vector<string> tmps;
		deque<string> dicts;
		split(path, '/', tmps);
		for (auto i : tmps)
			cout << i << " ";
		cout << endl;
		
		for (auto i : tmps)
		{
			if (!i.empty())
			{
				if (i == ".." && !dicts.empty())
					dicts.pop_back();
				if (i != "." && i != "..")
					dicts.push_back(i);
			}
		}
		string dictory;
		while (!dicts.empty())
		{
			dictory += "/";
			dictory += dicts.front();
			dicts.pop_front();
		}
		
		if (dictory.empty())
			return "/";
		return dictory;
	}
};
