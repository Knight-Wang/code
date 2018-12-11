// k好数.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
typedef long long ll;
using namespace std;
const int mod = 1e9 + 7;
ll n, k;
ll dp[105][105];
ll dfs(int cur, int last)
{
	if (dp[cur][last] != -1)
		return dp[cur][last];
	if (cur == n)
	{
		return dp[cur][last] = 1;
	}
	ll cnt = 0;
	for (int i = 0; i < k; i++)
	{
		if (i != last - 1 && i != last + 1)
		{
			cnt = (cnt + dfs(cur + 1, i)) % mod;
		}
	}
	return dp[cur][last] = cnt;
}
int main()
{
	cin >> k >> n;
	memset(dp, -1, sizeof(dp));
	ll ans = 0;
	for (int i = 1; i < k; i++)
	{
		ans = (ans + dfs(1, i)) % mod;
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}

