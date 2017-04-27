// poj1065.cpp : 定义控制台应用程序的入口点。
// 

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <windows.h>
const int INF = 0x3f3f3f3f;
using namespace std;
struct node
{
	int x, y;
};
node a[5005];
int d[5005];
bool cmp(const node & a, const node & b)
{
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}
void work(int x, int end)
{
	int l = 1, r = end, m, res = INF;
	while (l <= r)
	{
		m = (l + r) >> 1;
		if (d[m] <= x)
		{
			r = m - 1;
		}
		else
		{
			res = m;
			l = m + 1;
		}
	}
	if (res != INF)
		d[res + 1] = x;
	else
		d[1] = x;
}
int main()
{
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int j = 0; j < n; j++)
			scanf("%d %d", &a[j].x, &a[j].y);
		sort(a, a + n, cmp);
		int ans = 1;
		d[1] = a[0].y;
		for (int i = 1; i < n; i++)
		{
			if (a[i].y < d[ans])
				d[++ans] = a[i].y;
			else
				work(a[i].y, ans-1);	
		}
		cout << ans << endl;	
	}
	system("pause");
	return 0;
}