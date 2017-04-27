// 递推求值.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
const int mod = 99999999;
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
int main()
{
	mat F(7, vec(1));
	F[0][0] = 6;
	F[1][0] = 1;
	F[2][0] = 2;
	F[3][0] = 5;
	F[4][0] = 4;
	F[5][0] = 3;
	F[6][0] = 1;
	ll n;
	cin >> n;
	if (n <= 3)
	{
		printf("%d\n", F[3-n][0]);
		printf("%d\n", F[5-(n-1)][0]);
		//system("pause");
		return 0;
	}
	mat x(7, vec(7));
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			x[i][j] = 0;
		}
	}
	x[0][2] = 2;
	x[0][3] = 1;
	x[0][6] = 5;
	x[1][0] = 1;
	x[2][1] = 1;
	x[3][0] = 1;
	x[3][2] = 3;
	x[3][5] = 2;
	x[3][6] = 3;
	x[4][3] = 1;
	x[5][4] = 1;
	x[6][6] = 1;
	mat res(7, vec(7));
	res = pow(x, n - 3);
	mat fuck(7, vec(1));
	fuck = mul(res, F);
    printf("%d\n", fuck[0][0]);
	printf("%d\n", fuck[3][0]);
	//system("pause");
	return 0;
}

