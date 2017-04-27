// poj3624.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int w[3403];
int v[3403];
int n, m;
int dp[12885];

void solve()
{
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = m; j >= w[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}

	cout << dp[m] << endl;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &w[i], &v[i]);
	}
	solve();
	//system("pause");
	return 0;
}