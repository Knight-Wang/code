// CF622C.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

int a[1000005];
int p[1000005];
int n, t, l, r, x;
void init()
{
	p[0] = -1;
	for (int i = 1; i < n; i++)
	{
		if (a[i] != a[i - 1])
			p[i] = i - 1;
		else
			p[i] = p[i - 1];
	}
}
int main()
{
	cin >> n >> t;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	init();
	while (t--)
	{
		scanf("%d %d %d", &l, &r, &x);
		l--;
		r--;
		if (a[r] != x)
		{
			printf("%d\n", r + 1);
		}
		else
		{
			if (p[r] != -1 && p[r] >= l)
			{
				printf("%d\n", p[r] + 1);
			}
			else
			{
				puts("-1");
			}
		}
	}
	//system("pause");
	return 0;
}

