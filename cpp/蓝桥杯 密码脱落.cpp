// 密码脱落.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int dp[1005][1005];
int main()
{
	string s;
	cin >> s;
	int n = s.length();
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i + 2; j < n; j++)
		{
			if (s[i] == s[j])
			{
				dp[i][j] = dp[i + 1][j - 1];
			}
			else
			{
				dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
			}
		}
	}
	cout << dp[0][n - 1] << endl;
	system("pause");
	return 0;
}

