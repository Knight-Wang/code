// CF792C.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

string s;
int n, cnt = 0;
int dp[100005][2][3]; 
int path[100005][2][3];
int ans[100005];

int trans(int index)
{
	return s[index] - '0';
}

int dfs(int now, bool lz, int mod)
{
	if (dp[now][lz][mod] != -1)
		return dp[now][lz][mod];
	if (now == n)
	{
		if (lz && !mod)
			return 0;
		return -INF;
	}
	int x, y = -INF;
	x = dfs(now + 1, lz, mod);
	path[now][lz][mod] = 0;
	if (s[now] != '0' || (s[now] == '0' && lz))
	{
		y = dfs(now + 1, true, (mod + trans(now)) % 3) + 1;
		if (y > x)
		{
			path[now][lz][mod] = 1;
			return dp[now][lz][mod] = y;
		}
	}
	return dp[now][lz][mod] = x;
}


void get_path(int now, bool lz, int mod)
{
	if (now == n)
		return;
	if (path[now][lz][mod])
	{
		ans[cnt++] = now;
		get_path(now + 1, true, (mod + trans(now)) % 3);
	}
	else
	{
		get_path(now + 1, lz, mod);
	}
}


int main()
{
	cin >> s;
	n = s.length();
	memset(dp, -1, sizeof(dp));
	int tmp = dfs(0, false, 0);
	if (tmp <= 0)
	{
		if (s.find("0") != string::npos)
			puts("0");
		else
			puts("-1");
	}
	else
	{
		get_path(0, false, 0);
		for (int i = 0; i < cnt; i++)
		{
			putchar(s[ans[i]]);
		}
		puts("");
	}
	//system("pause");
	return 0;
}

