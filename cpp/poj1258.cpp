// poj1258.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstdio>
#define INF 0x3f3f3f3f
using namespace std;

int map[1005][1005];
int mincost[1005];
bool used[1005];
int n, cost = 0;
int main()
{
	while (cin >> n)
	{
		cost = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		for (int i = 0; i < n; i++)
		{
			used[i] = false;
			mincost[i] = INF;
		}
		mincost[0] = 0;
		while (true)
		{
			int v = -1;
			for (int i = 0; i < n; i++)
			{
				if (!used[i] && (v == -1 || mincost[i] < mincost[v]))
					v = i;
			}
			if (v == -1)
				break;
			used[v] = true;
			cost += mincost[v];
			for (int i = 0; i < n; i++)
			{
				mincost[i] = min(mincost[i], map[v][i]);
			}
		}
		cout << cost << endl;
	}
	//system("pause");
	return 0;
}

