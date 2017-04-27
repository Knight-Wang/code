// 百练 雷涛的小猫.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, h, p, tmp, maxH;
int a[2005][2005], dp[2005][2005];

void solve()
{
	for (int j = maxH; j >= 0; j--)
	{
		int tmp = 0;
		for (int k = 0; k < n; k++)
		{
			if (j + h <= maxH)
				tmp = max(tmp, dp[k][j + h]);
		}
		for (int i = 0; i < n; i++)
		{
			dp[i][j] = tmp;
			if (j + 1 <= maxH)
				dp[i][j] = max(dp[i][j], dp[i][j + 1]);
			dp[i][j] += a[i][j];
		}
	}
	int maxn = 0;
	for (int i = 0; i < n; i++)
	{
		maxn = max(maxn, dp[i][0]);
	}
	cout << maxn << endl;
}

int main()
{
	cin >> n >> m >> h;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &p);
		for (int j = 0; j < p; j++)
		{
			scanf("%d", &tmp);
			maxH = max(maxH, tmp);
			a[i][tmp]++;
		}
	}
	solve();
	//system("pause");
	return 0;
}