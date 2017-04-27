// six.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
const ll mod = 1000000007;

ll pow(ll a, ll b, ll mod)
{
	ll res = 1;
	while (b > 0)
	{
		if (b & 1)
			res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

ll n, t;
int main()
{
	cin >> n >> t;
	if (!n)
	{
		cout << "0" << endl;
	}
	else if (!t)
	{
		cout << n << endl;
	}
	else
	{
		n %= mod;
		ll res = n * (pow(2, t + 1, mod) - 1) % mod;
		cout << res << endl;
	}
	//system("pause");
	return 0;
}

