// 球队”食物链“.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 20;

char a[N][N];
int n, s, t, ans[N + 5], mp[N][N];
int dp[(1 << N) + 5][N];
int path[(1 << N) + 5][N];
bool ok = false;

int dfs(int S, int now)
{
	if (dp[S][now] != -1)
		return dp[S][now];
	if (S == (1 << n) - 1)
	{
		if (mp[now][s])
		{
			t = now;
			return ok = 1;
		}
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (ok)
			continue;
		if (!(S & (1 << i)) && mp[now][i])
		{
			int res = dfs(S | (1 << i), i);
			path[S][now] = i;
			if (res)
				return dp[S][now] = 1;
		}
	}
	return dp[S][now] = (ok ? -1 : 0);
}

void getPath()
{
	int p = 1 << s;
	ans[0] = s;
	int i = 1;
	for (int j = 0; j < n; j++)
	{
		ans[i++] = s = path[p][s];
		p |= (1 << s);
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 'W')
				mp[i][j] = 1;
			else if (a[i][j] == 'L')
				mp[j][i] = 1;
		}
	}
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++)
	{
		s = i;
		dfs(1 << i, i);
		if (ok)
			break;
	}
	if (!ok)
	{
		cout << "No Solution" << endl;
	}
	else
	{
		getPath();
		for (int i = 0; i < n; i++)
		{
			cout << ans[i] + 1;
			if (i != n - 1)
				cout << " ";
		}
		puts("");
	}
	//system("pause");
	return 0;
}