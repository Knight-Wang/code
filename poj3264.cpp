// poj3264.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 65536;
const int INF = 0x3f3f3f3f;

struct node
{
	int maxn, minn;
};

node data[2 * MAXN - 1];
int n, q, x, y, tmp;

void init(int n_)
{
	n = 1;
	while (n < n_)
	{
		n *= 2;
	}
	for (int i = 0; i < 2 * n - 1; i++)
	{
		data[i].maxn = -INF;
		data[i].minn = INF;
	}
}

void update(int k, int a)
{
	k += n - 1;
	data[k].minn = data[k].maxn = a;
	while (k)
	{
		k = (k - 1) / 2;
		data[k].minn = min(data[2 * k + 1].minn, data[2 * k + 2].minn);
		data[k].maxn = max(data[2 * k + 1].maxn, data[2 * k + 2].maxn);
	}
}

int query(int a, int b, int k, int l, int r, int type) 
{
	if (r <= a || l >= b)
	{
		if (type)
			return INF;
		else
			return -INF;
	}
	if (l >= a && r <= b)
	{
		if (type)
			return data[k].minn;
		else
			return data[k].maxn;
	}
	int x = query(a, b, 2 * k + 1, l, (l + r) / 2, type);
	int y = query(a, b, 2 * k + 2, (l + r) / 2, r, type);
	if (type)
		return min(x, y);
	return max(x, y);
}

int main()
{
	scanf("%d %d", &n, &q);
	int n_ = n;
	init(n);
	for (int i = 0; i < n_; i++)
	{
		scanf("%d", &tmp);
		update(i, tmp);
	}
	for (int i = 0; i < q; i++)
	{
		scanf("%d %d", &x, &y);
		int s = query(x - 1, y, 0, 0, n, 1);
		int t = query(x - 1, y, 0, 0, n, 0);
		printf("%d\n", t - s);
	}
	//system("pause");
	return 0;
}

