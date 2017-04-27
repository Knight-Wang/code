// poj1631.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <cstdio>
#include <iostream>
using namespace std;
int d[40010];
int fuck(int x, int right)
{
	int left = 0;
	int pos = -1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (d[middle] >= x)
		{
			pos = middle;
			right = middle - 1;
		}
		else
		{
			left = middle + 1;
		}
	}
	return pos;
}
int main()
{
	int t, n;
	int temp;
	cin >> t;
	while (t--)
	{
		cin >> n;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &temp);
			if (cnt == 0 || temp > d[cnt - 1])
			{
				d[cnt++] = temp;
			}
			else
			{
				int pos = fuck(temp, cnt - 1);
				d[pos] = temp;
			}
		}
		printf("%d\n", cnt);
	}
	//system("pause");
	return 0;
}