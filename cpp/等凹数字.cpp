// 等凹数字.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

int num[20], buf[20], n, t;
int dp[20][20][10][2][2][2];
ll l, r;

int dfs(int now, int len, int last, bool up, bool down, bool isP, bool lz, bool flag)
{
	if (now == 0)
	{
		return up && down && isP;
	}
	if (!flag && dp[now][len][last][up][down][isP] != -1)
		return dp[now][len][last][up][down][isP];
	int res = 0;
	int u = flag ? num[now] : 9;
	for (int i = 0; i <= u; i++)
	{
		buf[now] = i;
		if (lz)
			res += dfs(now - 1, len - (i == 0), i, up, down, isP, i == 0, flag && i == u);
		else if (i == last)
		{
			if (isP && now <= len / 2)
				res += dfs(now - 1, len, i, up, down, i == buf[len + 1 - now], false, flag && i == u);
			else
				res += dfs(now - 1, len, i, up, down, isP, false, flag && i == u);
		}
		else if (i < last)
		{
			if (up)
				continue;
			if (isP && now <= len / 2)
				res += dfs(now - 1, len, i, false, true, i == buf[len + 1 - now], false, flag && i == u);
			else
				res += dfs(now - 1, len, i, false, true, isP, false, flag && i == u);
		}
		else
		{
			if (!down)
				continue;
			if (isP && now <= len / 2)
				res += dfs(now - 1, len, i, true, true, i == buf[len + 1 - now], false, flag && i == u);
			else
				res += dfs(now - 1, len, i, true, true, isP, false, flag && i == u);
		}
	}
	return flag ? res : dp[now][len][last][up][down][isP] = res;
}

int query(ll x)
{
	memset(dp, -1, sizeof(dp));
	n = 0;
	while (x)
	{
		num[++n] = x % 10;
		x /= 10;
	}
	return dfs(n, n, 0, false, false, true, true, true);
}

int main()
{
	cin >> t;
	while (t--)
	{
		scanf("%lld %lld", &l, &r);
		printf("%d\n", query(r) - query(l - 1));
	}
	//system("pause");
	return 0;
}
