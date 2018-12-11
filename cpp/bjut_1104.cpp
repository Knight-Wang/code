// Cw的烦恼.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

ll pow(ll a, ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
			res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

ll p, k, vis[1000005];

int main()
{
	cin >> p >> k;
	ll ans;
	memset(vis, 0, sizeof(vis));
	ll cnt = 0;
	if (k == 0)
	{
		ans = pow(p, p - 1) % mod;
	}
	else if (k == 1)
		ans = pow(p, p) % mod;
	else
	{
		for (ll i = 1; i <= p - 1; i++)
		{
			if (!vis[i])
			{
				vis[i] = 1;
				ll x = k * i % p % mod;
				while (i != x)
				{
					vis[x] = 1;
					x = k * x % p % mod;
				}
				cnt++;
			}
		}
		ans = pow(p, cnt);
	}
	cout << ans << endl;
	system("pause");
	return 0;
}

