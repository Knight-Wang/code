// CF580B.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
struct node
{
	ll m, s;
};
node a[100005];
ll tmp[100005];
ll s[100005];
bool cmp(const node & a, const node & b)
{
	return a.m < b.m;
}
int main()
{
	ll n, d;
	cin >> n >> d;
	for (int i = 0; i < n; i++)
	{
		scanf("%lld %lld", &a[i].m, &a[i].s);
	}
	sort(a, a + n, cmp);
	for (int i = 0; i < n; i++)
	{
		tmp[i] = a[i].m;
	}
	s[0] = a[0].s;
	for (int i = 1; i < n; i++)
	{
		s[i] = s[i - 1] + a[i].s;
	}
	ll maxn = 0;
	for (int i = 0; i < n; i++)
	{
		int pos = lower_bound(tmp + i + 1, tmp + n, a[i].m + d) - tmp;
		maxn = max(maxn, s[pos - 1] - s[i] + a[i].s);
		//cout << pos << " " << maxn << endl;
	}
	cout << maxn << endl;
	//system("pause");
	return 0;
}

