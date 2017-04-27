// two.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s;
int main()
{
	cin >> s;
	s += "WUB";
	int n = s.length();
	vector<int> v;
	for (int i = 0; i <= n - 3; i++)
	{
		if (s.substr(i, 3) == "WUB")
		{
			v.push_back(i);
			i += 2;
		}
	}

	string tmp = "";
	vector<string> res;
	for (int i = 0; i < n; i++)
	{
		if (binary_search(v.begin(), v.end(), i))
		{
			i += 2;
			if (tmp.size())
			{
				res.push_back(tmp);
				tmp = "";
			}
		}
		else
		{
			tmp += s[i];
		}
	}
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i];
		if (i != res.size() - 1)
		{
			cout << " ";
		}
	}
	//system("pause");
	return 0;
}

