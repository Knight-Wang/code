// poj3258.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int l, n, m;
const int INF = 0x3f3f3f3f;
int a[50005];
bool judge(int x)
{
	int cnt = 0;
	int front = 1, end = 0;
	while (front < n)
	{
		if (a[front] - a[end] < x)
		{
			cnt++;
		}
		else
		{
			end = front;
		}
		front++;
	}
	return cnt <= m;
}
int binary_search(int p)
{
	int l = 1, r = p, m, res = 1;
	while (l <= r)
	{
		m = (l + r) >> 1;
		if (judge(m))
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
	while (cin >> l >> n >> m)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		sort(a + 1, a + n + 1);
		a[n + 1] = l;
		n += 2;
		printf("%d\n", binary_search(l));
	}
	//system("pause");
	return 0;
}