// 小zyx快跑.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int a[21];
bool vis[1005];
struct node
{
	int data, depth;
	node(int a, int b)
	{
		data = a, depth = b;
	}
};
int main()
{
	int t, n, k;
	string s;
	cin >> t;
	while (t--)
	{
		memset(vis, 0, sizeof(vis));
		cin >> n >> k >> s;
		for (int i = 0; i < k; i++)
		{
			scanf("%d", &a[i]);
		}
		queue<node> q;
		q.push(node{0, 0});
		vis[0] = true;
	    int ans = -2;
		while (!q.empty() && ans == -2)
		{
			node tmp = q.front();
			q.pop();
			for (int j = 0; j < k; j++)
			{
				int nx = tmp.data + a[j];
				if (nx >= n)
				{
					ans = tmp.depth;
				}
				else if (s[nx - 1] == 'o' && !vis[nx])
				{
					vis[nx] = true;
					node son(nx, tmp.depth + 1);
					q.push(son);
				}
			}
		}
		printf("%d\n", ans + 1);
	}
	//system("pause");
	return 0;
}

