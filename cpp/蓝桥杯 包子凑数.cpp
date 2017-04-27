// 蓝桥杯 包子凑数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 100005;

int a[105], ok[MAXN], n;

int gcd(int x, int y)
{
	return !y ? x : gcd(y, x % y);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int g = a[0];
	for (int i = 1; i < n; i++)
	{
		g = gcd(g, a[i]);
	}
	if (g != 1)
		puts("INF");
	else
	{
		ok[0] = true;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j + a[i] < MAXN; j++)
			{
				if (ok[j])
				{
					ok[j + a[i]] = true;
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < MAXN; i++)
		{
			if (!ok[i])
				cnt++;
		}
		printf("%d\n", cnt);
	}
	system("pause");
	return 0;
}

