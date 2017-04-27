// cz_vino和他的书架.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;
int t[105], w[105], n, s_t = 0, s_w = 0;
int dp[2][205][10005];
const int INF = 0x3f3f3f3f;
int min(int a, int b)
{
	return a < b ? a : b;
}

int solve()
{
	for (int j = 0; j <= s_t; j++)
	{
		for (int k = 0; k <= s_w; k++)
		{
			if (j >= k)
				dp[n & 1][j][k] = j;
			else
				dp[n & 1][j][k] = INF;
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = s_t; j >= 0; j--)
		{
			for (int k = s_w; k >= 0; k--)
			{
				dp[i & 1][j][k] = min(dp[(i + 1) & 1][j + t[i]][k], dp[(i + 1) & 1][j][k + w[i]]);
			}
		}
	}
	return dp[0][0][0];
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t[i] >> w[i];
		s_t += t[i];
		s_w += w[i];
	}
	cout << solve() << endl;
	//system("pause");
	return 0;
}

