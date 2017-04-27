// CF749D.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
vector<int> G[200005];
int n, a, b;
int maxn[200005];
int minn[200005];
int d[200005];
int max(int a, int b)
{
	return a > b ? a : b;
}
int min(int a, int b)
{
	return a < b ? a : b;
}
struct node
{
	int index;
	int maxn;
};
struct cmp
{
	bool operator ()(const node & a, const node & b)const
	{
		return a.maxn > b.maxn;
	}
};
int main()
{
	cin >> n;
	memset(minn, 0x3f, sizeof(minn));
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		G[a].push_back(b);
		maxn[a] = max(maxn[a], b);
		minn[a] = min(minn[a], b);
	}
	set<node, cmp> s;
	for (int i = 1; i <= n; i++)
	{
		if (G[i].size())
		{
			node tmp;
			tmp.index = i;
			tmp.maxn = maxn[i];
			s.insert(tmp);
		}
	}
	int T, x;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &x);
		for (int j = 0; j < x; j++)
		{
			scanf("%d", &d[j]);
			node t;
			t.index = d[j];
			t.maxn = maxn[d[j]];
			s.erase(t);
		}
		if (s.size() == 0)
		{
			puts("0 0");
		}
		else if (s.size() == 1)
		{
			printf("%d %d\n", s.begin()->index, minn[s.begin()->index]);
		}
		else
		{
			set<node, cmp>::iterator t = s.begin();
			node y;
			y.index = t->index;
			y.maxn = t->maxn;
			s.erase(s.begin());
			set<node, cmp>::iterator t2 = s.begin();
			vector<int>::iterator it = upper_bound(G[t->index].begin(), G[t->index].end(), t2->maxn);
			if (it != G[t->index].end())
			{
				printf("%d %d\n", y.index, *it);
			}
			else
			{
				puts("0 0");
			}
			s.insert(y);
		}
		for (int j = 0; j < x; j++)
		{
			node t;
			t.index = d[j];
			t.maxn = maxn[d[j]];
			if (G[t.index].size())
				s.insert(t);
		}
	}
	//system("pause");
	return 0;
}

