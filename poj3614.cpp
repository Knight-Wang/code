// poj3614.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

struct cow
{
	int minn, maxn;
};

struct lotion
{
	int s, c;
};

cow a[2505];
lotion t[2505];
int C, L;

bool cmp(const cow & c1, const cow & c2)
{
	if (c1.minn != c2.minn)
	{
		return c1.minn < c2.minn;
	}
	return c1.maxn < c2.maxn;
}

bool cmp1(const lotion & l1, const lotion & l2)
{
	return l1.s < l2.s;
}

int main()
{
	cin >> C >> L;
	priority_queue<int, vector<int>, greater<int> > q;
	for (int i = 0; i < C; i++)
	{
		cin >> a[i].minn >> a[i].maxn;
	}
	for (int i = 0; i < L; i++)
	{
		cin >> t[i].s >> t[i].c;
	}
	sort(a, a + C, cmp);
	sort(t, t + L, cmp1);
	int cnt = 0, cur = 0;
	for (int i = 0; i < L; i++)
	{
		while (cur < C && a[cur].minn <= t[i].s)
		{
			q.push(a[cur].maxn);
			cur++;
		}
		while (!q.empty() && t[i].c > 0)
		{
			int tmp = q.top();
			q.pop();
			if (t[i].s <= tmp)
			{
				cnt++;
				t[i].c--;
			}
		}
	}
	cout << cnt << endl;
	//system("pause");
	return 0;
}

