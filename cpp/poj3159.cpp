// poj3159.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;

struct edge
{
	int to;
	int cost;
};
vector<edge> G[30005];
int d[30005];
typedef pair<int, int>P;

int Scan()
{
	int res = 0, ch, flag = 0;

	if ((ch = getchar()) == '-')             //判断正负  
		flag = 1;

	else if (ch >= '0' && ch <= '9')           //得到完整的数  
		res = ch - '0';
	while ((ch = getchar()) >= '0' && ch <= '9')
		res = res * 10 + ch - '0';

	return flag ? -res : res;
}

int main()
{
	int n, m, a, b, l;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		a = Scan();
		b = Scan();
		l = Scan();
		edge e;
		e.to = b;
		e.cost = l;
		G[a].push_back(e);
	}
	priority_queue<P, vector<P>, greater<P> >myQueue;
	myQueue.push(P(0, 1));
	for (int i = 1; i <= n; i++)
	{
		d[i] = INF;
	}
	d[1] = 0;
	while (!myQueue.empty())
	{
		P temp = myQueue.top();
		myQueue.pop();
		int v = temp.second;
		if (d[v] < temp.first)
			continue;
		for (int i = 0; i < G[v].size(); i++)
		{
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost)
			{
				d[e.to] = d[v] + e.cost;
				myQueue.push(P(d[e.to], e.to));
			}
		}
	}
	cout << d[n] << endl;
	//system("pause");
	return 0;
}