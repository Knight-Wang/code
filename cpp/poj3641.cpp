// poj3641.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

ll pow(ll a, ll x, ll mod)
{
	ll res = 1;
	while (x)
	{
		if (x & 1)
			res = res * a % mod;
		a = a * a % mod;
		x >>= 1;
	}
	return res;
}

bool is_prime(ll x)
{
	for (ll i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
			return false;
	}
	return x != 1;
}

int main()
{
	ll p, a;
	while (cin >> p >> a, p || a)
	{
		if (pow(a, p, p) == a && !is_prime(p))
			puts("yes");
		else
			puts("no");
	}
	//system("pause");
	return 0;
}

