// 宠物小精灵之收服.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N, M, K;
int a[105], b[105], dp[1005][505];

void solve()
{
	for (int i = K - 1; i >= 0; i--)
	{
		for (int j = N; j >= 0; j--)
		{
			for (int k = M; k >= 0; k--)
			{
				dp[j][k] = dp[j][k];
				if (j >= a[i] && k >= b[i])
				{
					dp[j][k] = max(dp[j][k], dp[j - a[i]][k - b[i]] + 1);
				}
			}
		}
	}
	int maxN = 0, costM = 0;
	for (int i = 0; i < M; i++)
	{
		if (dp[N][i] > maxN)
		{
			maxN = dp[N][i];
			costM = i;
		}
	}
	cout << maxN << " " << M - costM << endl;
}
int main()
{
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> a[i] >> b[i];
	}
	solve();
	//system("pause");
	return 0;
}

