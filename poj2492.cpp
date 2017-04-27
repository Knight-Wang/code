// poj2492.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 2000;
vector<int> G[MAXN + 5];
int T, n, m, x, y, color[MAXN + 5];

bool dfs(int x, int c)
{
	color[x] = c;
	for (int i = 0; i < G[x].size(); i++)
	{
		int t = G[x][i];
		if (color[t] == c)
			return false;
		if (color[t] == 0 && !dfs(t, -c))
			return false;
	}
	return true;
}

int main()
{
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			G[i].clear();
		}
		memset(color, 0, sizeof(color));
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d", &x, &y);
			G[x].push_back(y);
			G[y].push_back(x);
		}
		bool flag = true;
		for (int i = 1; i <= n; i++)
		{
			if (!color[i])
			{
				if (!dfs(i, 1))
				{
					flag = false;
					break;
				}
			}
		}
		cout << "Scenario " << "#" << t << ":" << endl;
		if (!flag)
		{
			cout << "Suspicious bugs found!" << endl << endl;
 		}
		else
		{
			cout << "No suspicious bugs found!" << endl << endl;
		}
	}
	//system("pause");
	return 0;
}

