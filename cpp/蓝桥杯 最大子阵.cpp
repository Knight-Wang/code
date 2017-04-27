// 蓝桥杯 最大子阵.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3;
int n, m, a[505][505], dp[505];

int solve()
{
	int sum = 0, maxnn = -INF;
	for (int l = 0; l < m; l++)
	{
		sum += dp[l];
		if (sum > maxnn)
			maxnn = sum;
		if (sum < 0)
			sum = 0;
	}
	return maxnn;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	int maxn = -INF;
	for (int i = 0; i < n; i++)
	{
		memset(dp, 0, sizeof(dp));
		for (int j = i; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				dp[k] += a[j][k];
			}
			int s = solve();
			maxn = max(maxn, s);
		}
	}
	cout << maxn << endl;
	//system("pause");
	return 0;
}


