// 滑动窗口.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, k, a[1000005], q[1000005];
void max_value()
{
	int front = 0, end = 0;
	for (int i = 0; i < n; i++)
	{
		while (a[q[end]] <= a[i] && end >= front)
		{
			end--;
		}
		q[++end] = i;
		while (q[front] < i - k + 1 && front < end)
		{
			front++;
		}
		if (i >= k - 1)
			printf("%d ", a[q[front]]);
	}
	puts("");
}
void min_value()
{
	int front = 0, end = 0;
	for (int i = 0; i < n; i++)
	{
		while (a[q[end]] >= a[i] && end >= front)
		{
			end--;
		}
		q[++end] = i;
		while (q[front] < i - k + 1 && front < end)
		{
			front++;
		}
		if (i >= k - 1)
			printf("%d ", a[q[front]]);
	}
	puts("");
}
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	min_value();
	memset(q, 0, sizeof(q));
	max_value();
	//system("pause");
	return 0;
}

