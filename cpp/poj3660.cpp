// poj3660.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m, a[105][105], x, y;
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			a[i][j] = INF;
		}
		a[i][i] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		a[x][y] = 1;
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
	set<int> s;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (a[i][j] == INF && a[j][i] == INF)
			{
				s.insert(i);
				s.insert(j);
			}
		}
	}
	cout << n - s.size() << endl;
	//system("pause");
	return 0;
}

