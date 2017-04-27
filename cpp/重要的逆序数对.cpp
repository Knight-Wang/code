// 重要的逆序数对.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 200005;
int n, a[MAXN], tmp[MAXN];
long long cnt = 0;

void mergeSort(int * a, int left, int right, int * tmp)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	mergeSort(a, left, mid, tmp);
	mergeSort(a, mid + 1, right, tmp);
	int x = left;
	int y = mid + 1;
	int start = left;
	while (x <= mid && y <= right)
	{
		if (a[x] < a[y])
		{
			tmp[start++] = a[x++];
		}
		else
		{
			int pos = upper_bound(a + x, a + mid + 1, 2 * a[y]) - a;
			cnt += mid - pos + 1;
			tmp[start++] = a[y++];
		}
	}
	while(x <= mid)
	{
		tmp[start++] = a[x++];
	}
	while(y <= right)
	{
		tmp[start++] = a[y++];
	}
	for (int i = left; i <= right; i++)
	{
		a[i] = tmp[i];
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	mergeSort(a, 0, n - 1, tmp);
	cout << cnt << endl;
	//system("pause");
	return 0;
}

