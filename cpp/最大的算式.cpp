// 最大的算式.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
typedef long long ll;
using namespace std;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll n, k, a[20];
ll max(ll a, ll b)
{
	return a > b ? a : b;
}
ll dfs(ll cur, ll num, ll last, ll n_mul)
{
	if (cur == n)
	{
		if (n_mul == k)
		{
			ll tmp = 0;
			for (int i = last + 1; i < n; i++)
			{
				tmp += a[i];
			}
			return tmp * num;
		}
		return -INF;
	}
	ll x1 = -INF;
	ll x2 = -INF;
	if (n_mul < k)
	{
		ll tmp = 0;
		for (int i = last + 1; i <= cur; i++)
			tmp += a[i];
		x1 = dfs(cur + 1, num * tmp, cur, n_mul + 1);
	}
	x2 = dfs(cur + 1, num, last, n_mul);
	return max(x1, x2);
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << dfs(0, 1, -1, 0) << endl;
	//system("pause");
	return 0;
}

