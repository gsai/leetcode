#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
	vector< vector<string> > lists;
	void split(string s, unordered_set<string> &dict, vector<string> vec){
		if (s.length() == 0){
			if (vec.size() != 0){
				lists.push_back(vec);
			}
			return;
		}
		else
		{
			for (auto it = dict.begin(); it != dict.end(); it++){
				string subStr(s.substr(0, (*it).length()));
				if (subStr.compare((*it)) == 0){
					vec.push_back(subStr);
					split(s.substr(subStr.length(), s.length() - subStr.length()), dict, vec);
					vec.pop_back();
				}
			}
		}
	}
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		vector<string> vec;
		split(s, wordDict, vec);
		if (lists.size() != 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

