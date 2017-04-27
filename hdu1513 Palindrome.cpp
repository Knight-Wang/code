// hdu1513 Palindrome.cpp : 定义控制台应用程序的入口点。
// n % m = n & (m - 1)只有m等于2的时候才成立

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
string str;
int dp[5005][3];

int solve()
{
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (str[i] == str[j])
			{
				dp[i & 1][j] = dp[(i + 1) & 1][j - 1];
			}
			else
			{
				dp[i & 1][j] = min(dp[i & 1][j - 1], dp[(i + 1) & 1][j]) + 1;
			}
		}
	}
	return dp[0][n - 1];
}

int solve2()
{
	for (int j = 2; j <= n; j++)
	{
		for (int i = 0; i <= n - j; i++)
		{
			if (str[i] == str[i + j - 1])
			{
				dp[i][j % 3] = dp[i + 1][(j - 2) % 3];
			}
			else
			{
				dp[i][j % 3] = min(dp[i][(j - 1) % 3], dp[i + 1][(j - 1) % 3]) + 1;
			}
		}
	}
	return dp[0][n % 3];
}
int main()
{
	while (cin >> n >> str)
	{
		memset(dp, 0, sizeof(dp));
		cout << solve2() << endl;
	}
	//system("pause");
	return 0;
}