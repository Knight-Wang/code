// poj3040.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N, C;
struct node
{
	int d, c;
};
node a[25];

bool cmp(const node & a, const node & b)
{	
	return a.d > b.d;
}

int main()
{
	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &a[i].d, &a[i].c);
	}
	sort(a, a + N, cmp);
	int cnt = 0;
	int j = 0;
	for (; j < N; j++)
	{
		if (a[j].d < C)
			break;
	}
	for (int i = 0; i < j; i++)
	{
		cnt += (a[i].d / C) * a[i].c;
	}
	while (true)
	{
		int now = 0;
		for (int i = j; i < N; i++)
		{
			while (a[i].c && now + a[i].d <= C)
			{
				now += a[i].d;
				a[i].c--;
			}
		}
		for (int i = N - 1; i >= j; i--)
		{
			while (a[i].c && now < C)
			{
				now += a[i].d;
				a[i].c--;
			}
		}
		if (now < C)
			break;
		cnt++;
	}
	cout << cnt << endl;
	//system("pause");
	return 0;
}

