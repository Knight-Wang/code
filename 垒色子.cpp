// 垒色子.cpp : 定义控制台应用程序的入口点。
// 

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

const ll mod = 1e9 + 7;

mat mul(mat & A, mat & B)
{
	mat C(A.size(), vec(B[0].size()));
	for (int i = 0; i < A.size(); i++)
	{
		for (int k = 0; k < B.size(); k++)
		{
			for (int j = 0; j < B[0].size(); j++)
			{
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
			}
		}
	}
	return C;
}

mat pow(mat A, ll n)
{
	mat B(A.size(), vec(A[0].size()));
	for (int i = 0; i < A.size(); i++)
	{
		B[i][i] = 1;
	}
	while (n)
	{
		if (n & 1)
		{
			B = mul(B, A);
		}
		A = mul(A, A);
		n >>= 1;
	}
	return B;
}

ll pow_num(ll x, ll n)
{
	ll res = 1;
	while (n)
	{
		if (n & 1)
		{
			res = res * x % mod;
		}
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}

ll n, m, a, b;
int side[6] = {3, 4, 5, 0, 1, 2};
mat x(6, vec(6)), dp(1, vec(6));
void init()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			x[i][j] = 1;
		}
	}
	for (int i = 0; i < 6; i++)
	{
		dp[0][i] = 4;
	}
}
int main()
{
	cin >> n >> m;
	init();
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		x[a - 1][side[b - 1]] = (ll)0;
		x[b - 1][side[a - 1]] = (ll)0;
	}
	x = pow(x, n - 1);
	dp = mul(dp, x);
	ll res = 0;
	for (int i = 0; i < 6; i++)
		res = (res + dp[0][i]) % mod;
	ll t = pow_num(4, n - 1);
	res = res * t % mod;
	cout << res << endl;
	system("pause");
	return 0;
}
