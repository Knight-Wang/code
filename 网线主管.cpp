// 网线主管.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;
float x;
int a[100005], n, k, maxn;
int max(int a, int b)
{
	return a > b ? a : b;
}
bool check(int x)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cnt += a[i] / x;
	}
	return cnt >= k;
}
int solve(int x)
{
	int l = 1, r = x, m, res = 0;
	while (l <= r)
	{
		m = (l + r) >> 1;
		if (check(m))
		{
			res = m;
			l = m + 1;
		}
		else
		{
			r = m - 1;
		}
	}
	return res;
}
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		scanf("%f", &x);
		a[i] = x * 100;
		maxn = max(maxn, a[i]);
	}
	int res = solve(maxn);
	if (res == 0)
	{
		puts("0.00");
	}
	else
	{
		printf("%.2lf\n", res / 100.0);
	}
	//system("pause");
	return 0;
}

