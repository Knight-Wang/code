// 拿糖果.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
bool is_prime[100005];
int dp[100005];
int max(int a, int b)
{
	return a > b ? a : b;
}
void init()
{
	for (int i = 0; i < 100005; i++)
	{
		is_prime[i] = true;
	}
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i < 100005; i++)
	{
		if (is_prime[i])
		{
			for (int j = 2 * i; j < 100005; j += i)
			{
				is_prime[j] = false;
			}
		}
	}
}
int dfs(int x)
{
	if (dp[x] != -1)
		return dp[x];
	if (x <= 3)
		return 0;
	if (x == 4)
		return 2;
	int res = 0;
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0 && is_prime[i])
		{
			res = max(res, dfs(x - 2 * i) + i);
		}
	}
	return dp[x] = res;
}
int main()
{
	cin >> n;
	init();
	memset(dp, -1, sizeof(dp));
	cout << dfs(n) << endl;
	system("pause");
	return 0;
}

