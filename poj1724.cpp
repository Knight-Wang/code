// poj1724.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
using namespace std;

const int MAXN = 100;
const int MAXK = 10000;
const int INF = 0x3f3f3f3f;

struct node
{
	int to, len, toll;
};
vector<node> G[MAXN + 5];
int k, n, m, s, t, l, T, minLen = INF;

struct co
{
	int now, cost;
};
bool vis[MAXN + 10];
int d[MAXN + 5][MAXK + 5];
int in[MAXN + 5][MAXK + 5];

/*
void dfs(int now, int rem, int len) //当前在now点，还剩rem元钱，走过长度为len
{
	if (now == n)
	{
		minLen = min(minLen, len);
		return;
	}
	for (int i = G[now].size() - 1; i >= 0; i--)
	{
		if (!vis[G[now][i].to] && rem >= G[now][i].toll)
		{
			if (d[G[now][i].to][rem - G[now][i].toll] <= len + G[now][i].len || len + G[now][i].len >= minLen)
				continue;
			d[G[now][i].to][rem - G[now][i].toll] = len + G[now][i].len;
			dfs(G[now][i].to, rem - G[now][i].toll, len + G[now][i].len);
			vis[G[now][i].to] = false;
		}
	}
}
*/


int spfa()
{
	queue<co> q;
	co start;
	start.now = 1;
	start.cost = 0;
	q.push(start);
	in[1][0] = true;
	priority_queue<int, vector<int>, greater<int> > pq;
	pq.push(INF);
	while (!q.empty())
	{
		co tmp = q.front();
		q.pop();
		int now = tmp.now;
		int cost = tmp.cost;
		if (now == n)
		{
			pq.push(d[n][cost]);
		}
		in[now][cost] = false;
		for (int i = 0; i < G[now].size(); i++)
		{
			if (cost + G[now][i].toll <= k && d[now][cost] + G[now][i].len < d[G[now][i].to][cost + G[now][i].toll])
			{
				d[G[now][i].to][cost + G[now][i].toll] = d[now][cost] + G[now][i].len;
				if (d[G[now][i].to][cost + G[now][i].toll] >= pq.top())
					continue;
				if (!in[G[now][i].to][cost + G[now][i].toll])
				{
					in[G[now][i].to][cost + G[now][i].toll] = true;
					co son;
					son.now = G[now][i].to;
					son.cost = cost + G[tmp.now][i].toll;
					q.push(son);
				}
			}
		}
	}
	int minL = INF;
	for (int i = 0; i <= k; i++)
	{
		minL = min(minL, d[n][i]);
	}
	return minL;
}

int main()
{
	cin >> k >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> s >> t >> l >> T;
		node tmp;
		tmp.to = t;
		tmp.len = l;
		tmp.toll = T;
		if (s != t)
			G[s].push_back(tmp);
	}
	memset(d, 0x3f, sizeof(d));
	for (int i = 0; i <= k; i++)
	{
		d[1][i] = 0;
	}
	vis[1] = true;
	int minLen = spfa();
	if (minLen >= INF)
		puts("-1");
	else
		cout << minLen << endl;
	//system("pause");
	return 0;
}

