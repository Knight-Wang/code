// 骑士游历.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

const ll mod = 1e9 + 7;

ll n, x, y;

mat mul(mat & a, mat & b)
{
	mat c(a.size(), vec(b[0].size()));
	for (int i = 0; i < a.size(); i++)
	{
		for (int k = 0; k < b.size(); k++)
		{
			for (int j = 0; j < b[0].size(); j++)
			{
				c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
			}
		}
	}
	return c;
}

mat pow(mat a, ll n)
{
	mat b(a.size(), vec(a.size()));
	for (int i = 0; i < a.size(); i++)
	{
		b[i][i] = 1;
	}
	while (n > 0)
	{
		if (n & 1)
			b = mul(b, a);
		a = mul(a, a);
		n >>= 1;
	}
	return b;
}

bool check(int x, int y)
{
	int m = x / 8, n = x % 8, p = y / 8, q = y % 8;
	if (abs(m - p) == 1 && abs(n - q) == 2)
		return true;
	if (abs(m - p) == 2 && abs(n - q) == 1)
		return true;
	return false;
}

void init(mat & x, mat & y, int p, int q)
{
	for (int i = 0; i < 64; i++)
	{
		for (int j = 0; j < 64; j++)
		{
			if (check(i, j))
				x[i][j] = x[j][i] = 1;
			else
				x[i][j] = x[j][i] = 0;
		}
	}
	for (int i = 0; i < 64; i++)
	{
		y[0][i] = 0;
	}
	y[0][p * 8 + q] = 1;
}

int main()
{
	cin >> n >> x >> y;
	x--, y--;
	mat a(64, vec(64));
	mat m(1, vec(64));
	init(a, m, x, y);
	a = pow(a, n);
	m = mul(m, a);
	ll cnt = 0;
	for (int i = 0; i < 64; i++)
	{
		cnt += m[0][i];
		cnt %= mod;
	}
	cout << cnt << endl;
	//system("pause");
	return 0;
}
