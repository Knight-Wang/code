// 月度开销.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;
int a[100005], n, m, sum = 0, maxn = 0;
int max(int a, int b)
{
	return a > b ? a : b;
}
bool check(int x)
{
	int cnt = 0, s = 0;
	for (int i = 0; i < n; i++)
	{
		if (cnt + a[i] <= x)
			cnt += a[i];
		else
		{
			cnt = a[i];
			s++;
		}
	}
	if (cnt <= x)
		return s + 1 <= m;
	return false;
}
int solve(int t, int x)
{
	int l = t, r = x, m, res;
	while (l <= r)
	{
		m = (l + r) >> 1;
		if (check(m))
		{
			res = m;
			r = m - 1;
		}
		else
		{
			l = m + 1;
		}
	}
	return res;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
		maxn = max(maxn, a[i]);
	}
	if (m == n)
	{
		cout << maxn << endl;
	}
	else
	{
		cout << solve(maxn, sum) << endl;
	}
	//system("pause");
	return 0;
}

