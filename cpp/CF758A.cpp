// CF758A.cpp : �������̨Ӧ�ó������ڵ㡣
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

int a[105], n;
int main()
{
	cin >> n;
	int maxn = -1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] > maxn)
			maxn = a[i];
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cnt += maxn - a[i];
	}
	cout << cnt << endl;
	return 0;
}

