// 股票买卖.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 100005;
const int INF = 0x3f3f3f3f;
int dp[5], n, T, p[MAXN];

int solve()
{
	for (int i = 0; i < 4; i++)
	{
		dp[i] = -INF;
	}
	dp[4] = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		dp[0] = max(dp[4], max(dp[3] - p[i], max(dp[2], max(dp[0], dp[1] - p[i]))));
		dp[1] = max(dp[4] + p[i], max(dp[3], max(dp[1], dp[2] + p[i])));
		dp[2] = max(dp[4], max(dp[2], dp[3] - p[i]));
		dp[3] = max(dp[3], dp[4] + p[i]);
		dp[4] = dp[4];
	}
	return dp[0];
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &p[i]);
		}
		cout << solve() << endl;
	}
    //system("pause");
	return 0;
}

