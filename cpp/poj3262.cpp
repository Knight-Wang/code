// poj3262.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct node
{
	int t, d;
};
int n;
node a[100005];
int sum[100005];

bool cmp(const node & a, const node & b)
{
	double x = a.d * 1.0 / a.t;
	double y = b.d * 1.0 / b.t;
	return x > y;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a[i].t, &a[i].d);
	}
	sort(a, a + n, cmp);
	sum[n - 1] = a[n - 1].d;
	for (int i = n - 2; i >= 0; i--)
	{
		sum[i] = sum[i + 1] + a[i].d;
	}
	long long total = 0;
	for (int i = 0; i < n - 1; i++)
	{
		total += sum[i + 1] * 2 * a[i].t;
	}
	cout << total << endl;
	//system("pause");
	return 0;
}

