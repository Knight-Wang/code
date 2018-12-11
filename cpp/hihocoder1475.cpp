// hihocoder offer收割编程练习赛8（3）.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

const int mod = 1e9 + 7;
int a[100005], s[100005], dp[100005], n, total;
map<int, int> g;

int solve()
{
	total = dp[0] = 1;
	g[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (!g.count(s[i]))
			g[s[i]] = 0;
		dp[i] = ((total - g[s[i]]) % mod + mod) % mod;
		g[s[i]] = (g[s[i]] + dp[i]) % mod;
		total = (total + dp[i]) % mod;
	}
	return dp[n];
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
	}
	cout << solve() << endl;
	//system("pause");
	return 0;
}

