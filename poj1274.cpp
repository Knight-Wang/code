// poj1274.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 500;
vector<int> G[MAXN + 5];
int n, m, k;
bool used[MAXN + 5];
int match[MAXN + 5];

bool dfs(int v)
{
	used[v] = true;
	for (int i = 0; i < G[v].size(); i++)
	{
		int u = G[v][i];
		int w = match[u];
		if (w == -1 || !used[w] && dfs(w))
		{
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	return false;
}

int max_match()
{
	int res = 0;
	for (int i = 1; i <= n + m; i++)
	{
		if (match[i] == -1)
		{
			memset(used, 0, sizeof(used));
			if (dfs(i))
				res++;
		}
	}
	return res;
}

int main()
{
	while (cin >> n >> m)
	{
		for (int i = 1; i <= n + m; i++)
		{
			G[i].clear();
		}
		memset(match, -1, sizeof(match));
		for (int i = 1; i <= n; i++)
		{
			int tmp;
			scanf("%d", &k);
			while (k--)
			{
				scanf("%d", &tmp);
				G[i].push_back(tmp + n);
				G[tmp + n].push_back(i);
			}
		}
		cout << max_match() << endl;
	}
	//system("pause");
	return 0;
}

