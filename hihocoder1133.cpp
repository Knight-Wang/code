// hihocoder1133.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1000000;
int a[MAXN + 5], n, k;

int partition(int * num, int l, int r)
{
	int i = l, j = r, m = (l + r) >> 1;
	int x = num[m];
	while (i != j)
	{
		while (j > m && num[j] >= x)
		{
			j--;
		}
		num[m] = num[j], m = j;
		while (i < m && num[i] <= x)
		{
			i++;
		}
		num[m] = num[i], m = i;
	}
	num[i] = x;
	return i;
}

int findK(int * num, int l, int r, int k)
{
	int pos = partition(num, l, r);
	if (pos == k)
	{
		return num[k];
	}
	if (pos > k)
	{
		return findK(num, l, pos - 1, k);
	}
	return findK(num, pos + 1, r, k);
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("%d\n", findK(a, 1, n, k));
	//system("pause");
	return 0;
}

