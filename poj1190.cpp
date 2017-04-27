// poj1190.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cmath>
#define INF 0x3f3f3f3f
using namespace std;
int n, m;
int min_now = INF;
int minV[25];
int minA[25];

int cal2(int a)
{
	return a * a;
}

int cal3(int a)
{
	return a * a * a;
}

int maxV(int r, int h, int rem)
{
	int ans = 0;
	for (int i = 0; i < rem; i++)
	{
		ans += r * r * h;
		r--, h--;
	}
	return ans;
}

void dfs(int cur, int v, int r, int h, int s)
{
	if (s + minA[cur] >= min_now)  //最优性剪枝 
		return;
	if (r - 1 < m - cur || h - 1 < m - cur) //可行性剪枝1（之后无法安排）
		return;
	if (maxV(r - 1, h - 1, m - cur) < v) //可行性剪枝2（之前搭的太小）
		return;
	if (v < minV[cur]) //可行性剪枝3（之前搭得太大）
		return;
	if (cur == m)
	{
		if (v == 0)
		{
			if (s < min_now)
			{
				min_now = s;
			}
		}
		return;
	}
	for (int i = h - 1; i >= 1; i--) // 枚举高度
	{
		for (int j = r - 1; j >= 1; j--) // 枚举半径
		{
			dfs(cur + 1, v - j * j * i, j, i, s + 2 * j * i);
		}
	}
}

int main()
{
	cin >> n >> m;
	minV[0] = (1 + m) * m / 2;
	minV[0] = minV[0] * minV[0];
	minA[0] = m * (m + 1) * (2 * m + 1) / 3;
	for (int i = 1; i < m; i++)
	{
		minV[i] = minV[i - 1] - cal3(m - i + 1);
		minA[i] = minA[i - 1] - 2 * cal2(m - i + 1);
	}
	for (int i = sqrt(n) + 1; i >= m; i--)
	{
		for (int j = n / i / i; j >= m; j--)
		{
			dfs(1, n - i * i * j, i, j, i * i + 2 * i * j);
		}
	}
	if (min_now == INF)
		puts("0");
	else
		printf("%d\n", min_now);
	//system("pause");
	return 0;
}
