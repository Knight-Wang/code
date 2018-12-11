// 震惊！这道题的解法竟然是这样的.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

int f[10];

void init()
{
	f[0] = 1;
	for (int i = 1; i < 10; i++)
	{
		f[i] = f[i - 1] * i;
	}
}

int main()
{
	int n;
	init();
	while (cin >> n, n != -1)
	{
		bool flag = false;
		for (int i = 9; i >= 0; i--)
		{
			if (n >= f[i]) n -= f[i];
			if (n == 0)
			{
				flag = true;
				puts("YES");
				break;
			}
		}
		if (!flag) puts("NO");
	}
	//system("pause");
	return 0;
}

