#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	string simplifyPath(string path)
	{
		char ch = path.back();
		while (ch == '/')
		{
			path = path.substr(0, path.size() - 1);
			if (!path.empty())
				ch = path.back();
			else
				break;
		}

		if (path.empty())
			return "/";
		else
		{
			size_t locSuffix = path.rfind("/");
			string suffix = path.substr(locSuffix);
			if (suffix == "/.." || suffix == "/.")
				return "/";
			else
			{
				if (suffix.substr(0, 4) == "/...")
				{
					string tmp = path.substr(0, locSuffix);
					if (!tmp.empty())
					{
						size_t locTmp = tmp.rfind("/");
						string suffixTmp = tmp.substr(locTmp);
						if (!suffixTmp.empty())
							return suffixTmp + suffix;
					}
					return suffix;
				}
				else
				{
					return suffix;
				}
			}
		}
	}
};

