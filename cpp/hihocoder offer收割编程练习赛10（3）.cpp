// hihocoder offer收割编程练习赛10（3）.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll INF = 0x3f3f3f3f3f3f3f3f;

int t, n, k, a[200005], num[200005];
map<int, int> mp;

bool check(ll val)
{
	for (int i = 0; i < n; i++)
	{
		num[i] = 0;
	}
	ll ans = 0, sum = 0;
	int start = 0;
	for (int i = 0; i < n; i++)
	{
		sum += num[a[i]];
		num[a[i]]++;
		while (sum > val && start <= i)
		{
			sum -= --num[a[start]];
			start++;
		}
		ans += i - start + 1;
	}
	return ans >= k;
}

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &n, &k);
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			if (mp.count(a[i]))
				a[i] = mp[a[i]];
			else
			{
				mp[a[i]] = cnt++;
				a[i] = cnt - 1;
			}
		}
		mp.clear();
		ll l = 0, r = (ll)n * (n - 1) / 2, res = INF;
		while (l <= r)
		{
			ll m = (l + r) >> 1;
			if (check(m))
			{
				res = m;
				r = m - 1;
			}
			else
			{
				l = m + 1;
			}
		}
		printf("%lld\n", res);
	}
	//system("pause");
	return 0;
}