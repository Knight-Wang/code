// poj3190.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

typedef pair<int, int> P;
struct node
{
	int index, left, right;
};
node a[50005];
int cow[50005];
int n;
priority_queue<P, vector<P>, greater<P> > pq;

bool cmp(const node & a, const node & b)
{
	if (a.left != b.left)
	{
		return a.left < b.left;
	}
	return a.right < b.right;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		a[i].index = i;
		scanf("%d %d", &a[i].left, &a[i].right);
	}
	sort(a + 1, a + n + 1, cmp);
	int cnt = 0;
	pq.push(P(a[1].right, ++cnt));
	cow[a[1].index] = cnt;
	for (int i = 2; i <= n; i++)
	{
		if (a[i].left > pq.top().first)
		{
			P tmp = pq.top();
			pq.pop();
			cow[a[i].index] = tmp.second;
			P tmp2(a[i].right, tmp.second);
			pq.push(tmp2);
		}
		else
		{
			pq.push(P(a[i].right, ++cnt));
			cow[a[i].index] = cnt;
		}
	}
	cout << cnt << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << cow[i] << endl;
	}
	//system("pause");
	return 0;
}