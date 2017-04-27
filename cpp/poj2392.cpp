// poj2392.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;

int K, dp[405][40005];
struct node
{
	int h, a, n;
};
node a[405];

bool cmp(const node & x, const node & y)
{
	return x.a < y.a;
}

int solve()
{
	for (int j = 0; j <= 40000; j++)
	{
		dp[K][j] = j;
	}
	for (int i = K - 1; i >= 0; i--)
	{
		for (int j = 0; j <= 40000; j++)
		{
			dp[i][j] = -INF;
			for (int t = 0; t <= a[i].n; t++)
			{
				if (j + t * a[i].h > a[i].a)
					break;
				dp[i][j] = max(dp[i][j], dp[i + 1][j + t * a[i].h]);
			}
		}
	}
	return dp[0][0];
}

int main()
{
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> a[i].h >> a[i].a >> a[i].n;
	}
	sort(a, a + K, cmp);
	cout << solve() << endl;
	//system("pause");
	return 0;
}