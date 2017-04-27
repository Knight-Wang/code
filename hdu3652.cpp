// hdu3652.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int num[15], n;

int dp[15][13][10][2];
int dfs(int now, int mod, int last, bool ok, bool flag)
{
	if (now == 0)
	{
		return !mod && ok;
	}
	if (!flag && dp[now][mod][last][ok] != -1)
		return dp[now][mod][last][ok];
	int res = 0;
	int u = flag ? num[now] : 9;
	for (int i = 0; i <= u; i++)
	{
		bool tmp = false;
		if (last == 1 && i == 3)
			tmp = true;
		res += dfs(now - 1, (mod * 10 + i) % 13, i, ok || tmp, flag && i == u);
	}
	return flag ? res : dp[now][mod][last][ok] = res;
}

int solve(int n)
{
	int sum = 0;
	while (n)
	{
		num[++sum] = n % 10;
		n /= 10;
	}
	return dfs(sum, 0, 0, 0, true);
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		memset(dp, -1, sizeof(dp));
		printf("%d\n", solve(n));
	}
	//system("pause");
	return 0;
}

