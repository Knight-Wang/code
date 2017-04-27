// poj2010.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

ll N, C, F, minL[100005], minR[100005];
struct node
{
	ll c, f;
};
node a[100005];

bool cmp(const node & a, const node & b)
{
	return a.c < b.c;
}

bool check(int i)
{
	return minL[i] + minR[i] + a[i].f <= F;
}

ll solve()
{
	ll s = 0;
	priority_queue<ll> q;
	for (int i = 0; i < C; i++)
	{
		if (i < N / 2)
		{
			q.push(a[i].f);
			s += a[i].f;
		}
		else
		{
			minL[i] = s;
			if (a[i].f <= q.top())
			{
				s -= q.top();
				q.pop();
				q.push(a[i].f);
				s += a[i].f;
			}
		}
	}
	s = 0;
	while (!q.empty())
	{
		q.pop();
	}
	for (int i = C - 1; i >= 0; i--)
	{
		if (i > C - 1 - N / 2)
		{
			q.push(a[i].f);
			s += a[i].f;
		}
		else
		{
			minR[i] = s;
			if (a[i].f <= q.top())
			{
				s -= q.top();
				q.pop();
				q.push(a[i].f);
				s += a[i].f;
			}
		}
	}
	for (int i = C - 1 - N / 2; i >= N / 2; i--)
	{
		if (check(i))
		{
			return a[i].c;
		}
	}
	return -1;
}

int main()
{
	while (cin >> N >> C >> F)
	{
		for (int i = 0; i < C; i++)
		{
			scanf("%I64d %I64d", &a[i].c, &a[i].f);
		}
		sort(a, a + C, cmp);
		cout << solve() << endl;
	}
	//system("pause");
	return 0;
}
