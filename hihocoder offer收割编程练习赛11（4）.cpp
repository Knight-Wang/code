// hihocoder offer收割编程练习赛11（4）.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

const int N = 200000;

int t, n, m, L, R, a[N + 5], block;
ll tot = 0, ans[N + 5];
ll bit1[N + 5]; //统计个数
ll bit2[N + 5]; //统计和

struct query
{
	int l, r, id;
};
query Q[N + 5];

bool cmp(const query & x, const query & y)
{
	if (x.l / block != y.l / block)
		return x.l / block < y.l / block;
	return x.r < y.r;
}

void bit_add(ll * bit, int i, int x)
{
	if (i == 0)
		return;
	while (i <= N)
	{
		bit[i] += x;
		i += i & -i;
	}
}

ll bit_sum(ll * bit, int i)
{
	ll s = 0;
	while (i)
	{
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

ll bit_query(ll * bit, int l ,int r)
{
	return bit_sum(bit, r) - bit_sum(bit, l - 1);
}

void Add(int pos)
{
	tot += (ll)a[pos] * (bit_query(bit1, a[pos], N + 1) + 1);
	tot += bit_query(bit2, 1, a[pos] - 1);
	bit_add(bit1, a[pos], 1);
	bit_add(bit2, a[pos], a[pos]);
}

void Del(int pos)
{
	tot -= (ll)a[pos] * bit_query(bit1, a[pos], N + 1);
	tot -= bit_query(bit2, 1, a[pos] - 1);
	bit_add(bit1, a[pos], -1);
	bit_add(bit2, a[pos], -a[pos]);
}

void init()
{
	block = sqrt(n);
	L = R = 1;
	tot = a[1];
	memset(bit1, 0, sizeof(bit1));
	memset(bit2, 0, sizeof(bit2));
	bit_add(bit1, a[1], 1);
	bit_add(bit2, a[1], a[1]);
}

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		init();
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d", &Q[i].l, &Q[i].r);
			Q[i].id = i;
		}
		sort(Q, Q + m, cmp);
		for (int i = 0; i < m; i++)
		{
			while (L < Q[i].l)
				Del(L++);
			while (L > Q[i].l)
				Add(--L);
			while (R < Q[i].r)
				Add(++R);
			while (R > Q[i].r)
				Del(R--);
			ans[Q[i].id] = tot;
		}
		for (int i = 0; i < m; i++)
		{
			printf("%lld\n", ans[i]);
		}
	}
	//system("pause");
	return 0;
}

