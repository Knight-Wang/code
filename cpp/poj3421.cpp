// poj3421.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

ll fac[21];
int x;

void init()
{
	fac[0] = 1;
	for (ll i = 1; i <= 20; i++)
		fac[i] = fac[i - 1] * i;
}

map<int, int> prime_factor(int n)
{
	map<int, int> res;
	for (int i = 2; i * i <= n; i++)
	{
		while (n % i == 0)
		{
			res[i]++;
			n /= i;
		}
	}
	if (n != 1)
		res[n] = 1;
	return res;
}

int main()
{
	init();
	while (scanf("%d", &x) != EOF)
	{
		map<int, int> f = prime_factor(x);
		map<int, int>::iterator it;
		ll res = 1;
		int cnt = 0;
		for (it = f.begin(); it != f.end(); it++)
		{
			res *= fac[it->second];
			cnt += it->second;
		}
		printf("%d %lld\n", cnt, fac[cnt] / res);
	}
	//system("pause");
	return 0;
}
