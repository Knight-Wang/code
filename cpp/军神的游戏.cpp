// 军神的游戏.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int dp[205][205];
bool dfs(int a, int b)
{
	if (dp[a][b] != -1)
		return dp[a][b];
	if (!a && !b)
		return dp[a][b] = false;
	if (a)
	{
		if (b)
		{
			if (!dfs(a - 1, b) || !dfs(a, b - 1) || !dfs(a - 1, b - 1))
			{
				return dp[a][b] = true;
			}
		}
		else
		{
			if (!dfs(a - 1, b))
				return dp[a][b] = true;
		}
	}
	else
	{
		if (b)
		{
			if (!dfs(a, b - 1))
			{
				return dp[a][b] = true;
			}
		}
	}
	return false;
}

int main()
{
	int t, x, y;
	memset(dp, -1, sizeof(dp));
	cin >> t;
	while (t--)
	{
		cin >> x >> y;
		if (x)
		{
			if (y)
			{
				if (!dfs(x - 1, y))
					cout << 1 << endl;
				else if (!dfs(x, y - 1))
					cout << 2 << endl;
				else if (!dfs(x - 1, y - 1))
					cout << 3 << endl;
				else
					cout << "KUSO GAME!" << endl;
			}
			else
			{
				if (!dfs(x - 1, y))
					cout << 1 << endl;
				else
					cout << "KUSO GAME!" << endl;
			}
		}
		else
		{
			if (y)
			{
				if (!dfs(x, y - 1))
					cout << 2 << endl;
				else
					cout << "KUSO GAME!" << endl;
			}
			else
			{
				cout << "KUSO GAME!" << endl;
			}
		}
	}
	//system("pause");
	return 0;
}

