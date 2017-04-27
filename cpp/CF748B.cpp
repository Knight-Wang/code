// CF748B.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;

string s, t;

map<char, char> m;
bool isSwap[30];
bool check(char a, char b)
{
	return (!isSwap[a - 'a'] && !isSwap[b - 'a']) ||
		   (isSwap[a - 'a'] && isSwap[b - 'a'] && m[a] == b && m[b] == a);
}
int main()
{
	cin >> s >> t;
	int n = s.length();
	bool flag = true;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == t[i])
		{
			isSwap[s[i] - 'a'] = true;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (s[i] == t[i])
		{
			continue;
		}
		if (check(s[i], t[i]))
		{
			m.insert(pair<char, char>(s[i], t[i]));
			m.insert(pair<char, char>(t[i], s[i]));
			isSwap[s[i] - 'a'] = isSwap[t[i] - 'a'] = true;
		}
		else
		{
			flag = false;
			break;
		}
	}
	if (flag)
	{
		memset(isSwap, 0, sizeof(isSwap));
		map<char, char>::iterator it;
		cout << m.size() / 2 << endl;
		for (it = m.begin(); it != m.end(); it++)
		{
			if (!isSwap[it->first - 'a'])
			{
				cout << it->first << " " << it->second << endl;
				isSwap[it->first - 'a'] = isSwap[it->second - 'a'] = true;
			}
		}
	}
	else
	{
		cout << "-1" << endl;
	}
	//system("pause");
	return 0;
}

