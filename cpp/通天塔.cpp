// 通天塔.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct node
{
	int x, y, z;
	bool operator < (const node & other)
	{
		return x < other.x;
	}
};
node a[100];

int dp[100], n;
int main()
{
	while (cin >> n, n)
	{
		for (int i = 0; i < 3 * n; i += 3)
		{
			cin >> a[i].x >> a[i].y >> a[i].z;
			a[i + 1].x = a[i].x;
			a[i + 1].y = a[i].z;
			a[i + 1].z = a[i].y;
			a[i + 2].x = a[i].y;
			a[i + 2].y = a[i].z;
			a[i + 2].z = a[i].x;
			for (int j = 0; j < 3; j++)
			{
				if (a[i + j].x < a[i + j].y)
				{
					swap(a[i + j].x, a[i + j].y);
				}
			}
		}
		sort(a, a + 3 * n);
		int maxn = 0;
		for (int i = 0; i < 3 * n; i++)
		{
			int maxj = 0;
			for (int j = 0; j < i; j++)
			{
				if (a[j].x < a[i].x && a[j].y < a[i].y)
				{
					maxj = max(maxj, dp[j]);
				}
			}
			dp[i] = maxj + a[i].z;
			maxn = max(maxn, dp[i]);
		}
		cout << maxn << endl;
	}
	//system("pause");
	return 0;
}

