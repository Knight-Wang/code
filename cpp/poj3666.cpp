// poj3666.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int a[2005], b[2005], dp[2005][2005], n;

int solve()
{
	for (int i = n - 1; i >= 0; i--)
	{
		dp[i][n - 1] = min(INF, dp[i + 1][n - 1]) + abs(a[i] - b[n - 1]);
		for (int j = n - 2; j >= 0; j--)
		{
			dp[i][j] = min(INF, dp[i][j + 1] - abs(a[i] - b[j + 1]));
			dp[i][j] = min(dp[i][j], dp[i + 1][j]);
			dp[i][j] += abs(a[i] - b[j]);
		}
	}
	int minn = INF;
	for (int i = 0; i < n; i++)
	{
		minn = min(minn, dp[0][i]);
	}
	return minn;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	int minn = INF;
	sort(b, b + n);
	minn = solve();
	cout << minn << endl;
	//system("pause");
	return 0;
}
