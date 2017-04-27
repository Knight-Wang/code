// ACSync的面试题.cpp : 定义控制台应用程序的入口点。
//

#pragma comment(linker,"/STACK:1024000000,1024000000")
//#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 1000005;
ll dp[MAXN + 5][2], sum[MAXN + 5];
int n, tmp, maxn;

ll dfs(int now, bool last)
{
	if (dp[now][last] != -1)
		return dp[now][last];
	if (now == maxn + 1)
	{
		return 0;
	}
	if (last)
	{
		return dp[now][last] = dfs(now + 1, 0);
	}
	else
	{
		return dp[now][last] = max(dfs(now + 1, 0), dfs(now + 1, 1) + sum[now] * now);
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		maxn = max(maxn, tmp);
		sum[tmp]++;
	}
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0) << endl;
	//system("pause");
	return 0;
}

