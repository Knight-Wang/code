// hihocoder offer收割编程练习赛11（2）.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int t, n, m, s;
int V[1005], S[1005], dp[1005][(1 << 11) + 5];

int dfs(int now, int s)
{
	if (dp[now][s] != -1)
		return dp[now][s];
	if (now == n)
	{
		if (s == (1 << m) - 1)
			return 0;
		return -INF;
	}
	int x = dfs(now + 1, s ^ S[now]) + V[now];
	int y = dfs(now + 1, s);
	return dp[now][s] = max(x, y);
}

int main()
{
	cin >> t;
	while (t--)
	{
		memset(dp, -1, sizeof(dp));
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin >> V[i] >> s;
			int tmp = 0, total = 0;
			for (int j = 0; j < s; j++)
			{
				cin >> tmp;
				tmp--;
				total |= (1 << tmp);
			}
			S[i] = total;
		}
		cout << dfs(0, 0) << endl;
	}
	//system("pause");
	return 0;
}

