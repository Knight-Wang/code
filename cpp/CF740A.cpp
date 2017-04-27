// CF740A.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
ll min(ll a, ll b)
{
	return a < b ? a : b;
}
int main()
{
	ll n, a, b, c;
	cin >> n >> a >> b >> c;
	int t = (4 - n % 4) % 4;
	if (t == 0)
	{
		puts("0");
	}
	else if (t == 1)
	{
		ll x = min(min(a, b + c), 3 * c);
		printf("%d\n", x);
	}
	else if (t == 2)
	{
		ll x = min(min(2 * a, min(b, 2 * c)), 5 * b);
		printf("%d\n", x);
	}
	else
	{
		ll x = min(min(3 * a, a + b), c);
		printf("%d\n", x);
	}
	//system("pause");
	return 0;
}

