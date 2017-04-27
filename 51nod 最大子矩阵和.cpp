// 51nod 最大子矩阵和.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

int n, m, a[505][505], dp[505];
ll b[505];

ll solve(ll * c)
{
	ll sum = 0, maxnn = 0;
	for (int l = 0; l < m; l++)
	{
		sum += c[l];
		if (sum < 0)
			sum = 0;
		if (sum > maxnn)
			maxnn = sum;
	}
	return maxnn;
}

int main()
{
	cin >> m >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	ll maxn = 0;
	for (int i = 0; i < n; i++)
	{
		memset(b, 0, sizeof(b));
		for (int j = i; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				b[k] += a[j][k];
			}
			ll s = solve(b);
			maxn = max(maxn, s);
		}
	}
	cout << maxn << endl;
	//system("pause");
	return 0;
}
