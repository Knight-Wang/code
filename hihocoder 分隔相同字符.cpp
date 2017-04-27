// hihocoder 分隔相同字符.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string s;
int n, cnt[26];

bool check(int x)
{
	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] > x / 2 + (x & 1))
		{
			return false;
		}
	}
	return true;
}

int main()
{
	cin >> s;
	n = s.length();
	int m = n;
	for (int i = 0; i < n; i++)
	{
		cnt[s[i] - 'a']++;
	}
	if (!check(n))
	{
		puts("INVALID");
		return 0;
	}
	int last = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (cnt[j] && j != last)
			{
				cnt[j]--;
				if (check(m - 1))
				{
					putchar('a' + j);
					last = j;
					m--;
					break;
				}
				else
					cnt[j]++;
			}
		}
	}
	puts("");
	//system("pause");
	return 0;
}

