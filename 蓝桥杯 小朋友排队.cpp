// 蓝桥杯 小朋友排队.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

const int N = 100000;
const int H = 1000000;
int bit[H + 5], a[N + 5], cnt[N + 5];
ll u[N + 5];

void add(int i, int x)
{
	while (i <= H)
	{
		bit[i] += x;
		i += i & -i;
	}
}

int sum(int i)
{
	int s = 0;
	while (i)
	{
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

void init()
{
	for (int i = 1; i <= N; i++)
	{
		u[i] = u[i - 1] + (ll)i;
	}
}

int main()
{
	int n, tmp;
	init();
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		a[i]++;
		add(a[i], 1);
		cnt[i] = i + 1 - sum(a[i]);
	}
	memset(bit, 0, sizeof(bit));
	for (int i = n - 1; i >= 0; i--)
	{
		add(a[i], 1);
		cnt[i] += sum(a[i] - 1);
	}
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += u[cnt[i]];
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}

