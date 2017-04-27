// CF_round397_B.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

bool vis[26];
bool check(string s)
{
	memset(vis, 0, sizeof(vis));
	int l = s.length();
	for (int i = 0; i < l; i++)
	{
		if (vis[s[i] - 'a'])
			continue;
		bool ok = true;
		for (int j = 0; j < s[i] - 'a'; j++)
		{
			if (!vis[j])
			{
				ok = false;
				break;
			}
		}
		if (!ok)
		{
			return false;
		}
		else
		{
			vis[s[i] - 'a'] = true;
		}
	}
	return true;
}

int main()
{
	string s;
	cin >> s;
	if (check(s))
		puts("YES");
	else
		puts("NO");
	//system("pause");
	return 0;
}

