// poj2139.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int a[305][305], n, m, k;
const int INF = 0x3f3f3f3f;
int main()
{
	memset(a, 0x3f, sizeof(a));
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		vector<int> l;
		int tmp;
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			cin >> tmp;
			l.push_back(tmp);
		}
		for (int p = 0; p < k; p++)
		{
			for (int q = 0; q < k; q++)
			{
				a[l[p]][l[q]] = p == q ? 0 : 1;
			}
		}
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (a[i][k] + a[k][j] < a[i][j])
				{
					a[i][j] = a[i][k] + a[k][j];
				}
			}
		}
	}
	double __ = INF;
	for (int j = 1; j <= n; j++)
	{
		int sum = 0;
		for (int k = 1; k <= n; k++)
		{
			sum += a[j][k];
		}
		double ans = sum * 1.0 / (n - 1);
		__ = min(ans, __);
	}
	cout << (int)(__ * 100) << endl;
	//system("pause");
	return 0;
}

