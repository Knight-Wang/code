// poj3468.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

const int MAXN = 131073;
struct node
{
	ll sum, inc;
};

node data[2 * MAXN - 1];

int n, q;
char c;
ll x, y, z, tmp;
void init(int n_)
{
	n = 1;
	while (n < n_)
	{
		n <<= 1;
	}
	for (int i = 0; i < n; i++)
	{
		data[i].sum = data[i].inc = 0;
	}
}

void add(int a, int b, int k, int l, int r, ll num)
{
	if (b <= l || a >= r)
		return;
	if (l >= a && r <= b)
	{
		data[k].inc += num;
		return;
	}
	ll len = 0;
	if (a >= l && b <= r)
		len = b - a;
	else if (l >= a)
		len = b - l;
	else
		len = r - a;
	data[k].sum += num * len;
	add(a, b, 2 * k + 1, l, (l + r) / 2, num);
	add(a, b, 2 * k + 2, (l + r) / 2, r, num);
}

ll query(int a, int b, int k, int l, int r, ll num)
{
	data[k].inc += num;
	if (b <= l || a >= r)
	{
		return 0;
	}
	if (l >= a && r <= b)
	{
		return data[k].sum + (ll)(r - l) * data[k].inc;
	}
	if (data[k].inc)
	{
		data[k].sum += data[k].inc * (ll)(r - l);
	}
	ll tmp = data[k].inc;
	data[k].inc = 0;
	ll x = query(a, b, 2 * k + 1, l, (l + r) / 2, tmp);
	ll y = query(a, b, 2 * k + 2, (l + r) / 2, r, tmp);
	return x + y;
}

int main()
{
	//freopen("res.txt", "w", stdout);
	cin >> n >> q;
	int n_ = n;
	init(n);
	for (int i = 0; i < n_; i++)
	{
		scanf("%I64d", &tmp);
		getchar();
		add(i, i + 1, 0, 0, n, tmp);
	}
	for (int i = 0; i < q; i++)
	{
		scanf("%c", &c);
		if (c == 'C')
		{
			scanf("%I64d %I64d %I64d", &x, &y, &z);
			getchar();
			add(x - 1, y, 0, 0, n, z);
		}
		else
		{
			scanf("%I64d %I64d", &x, &y);
			getchar();
			ll res = query(x - 1, y, 0, 0, n, 0);
			printf("%I64d\n", res);
		}
	}
	//system("pause");
	return 0;
}