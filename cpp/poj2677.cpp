// poj2677.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 50, INF = 0x3f3f3f3f;
double dp[MAXN + 5][MAXN + 5], dis[MAXN + 5][MAXN + 5];
int n, x[MAXN + 5], y[MAXN + 5];

int square(int x)
{
	return x * x;
}

void init()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			dis[i][j] = sqrt(square(x[i] - x[j]) + square(y[i] - y[j]));
		}
	}
}

double solve()
{
	dp[1][2] = dis[1][2];
	for (int j = 3; j <= n; j++)
	{
		// i < j - 1
		for (int i = 1; i <= j - 2; i++)
		{
			dp[i][j] = dp[i][j - 1] + dis[j - 1][j];
		}
		// i == j - 1
		dp[j - 1][j] = INF;
		for (int k = 1; k <= j - 2; k++)
		{
			dp[j - 1][j] = min(dp[j - 1][j], dp[k][j - 1] + dis[k][j]);
		}
	}
	return dp[n][n] = dp[n - 1][n] + dis[n - 1][n];
}

int main()
{
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> x[i] >> y[i];
		}
		init();
		printf("%.2f\n", solve());
	}
	//system("pause");
	return 0;
}

