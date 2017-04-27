// Bribe the Prisoners.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXP = 10000, MAXQ = 100, INF= 0x3f3f3f3f;
int n, p, q, a[MAXP + 5], dp[MAXQ + 5][MAXQ + 5];

int solve()
{
	memset(dp, 0, sizeof(dp));
	a[0] = 0;
	a[q + 1] = p + 1;
	for (int j = 2; j <= q + 1; j++)
	{
		for (int i = 0; i <= q + 1 - j; i++)
		{
			dp[i][i + j] = INF;
			for (int k = i + 1; k < i + j; k++)
				dp[i][i + j] = min(dp[i][i + j], dp[i][k] + dp[k][i + j]);
			dp[i][i + j] += a[i + j] - a[i] - 2;
		}
	}
	return dp[0][q + 1];
}

int main()
{
	cin >> n;
	for (int t = 1; t <= n; t++)
	{
		cin >> p >> q;
		for (int i = 1; i <= q; i++)
		{
			scanf("%d", &a[i]);
		}
		cout << "Case #" << t << ": " << solve() << endl;
	}
	//system("pause");
	return 0;
}

