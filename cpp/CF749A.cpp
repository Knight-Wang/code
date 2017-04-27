// CF749A.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;
int n;
int main()
{
	cin >> n;
	if (n & 1)
	{
		if (n == 3)
		{
			puts("1");
			puts("3");
			return 0;
		}
		else
		{
			printf("%d\n", (n - 3) / 2 + 1);
			printf("3 ");
			for (int i = 0; i < (n - 3) / 2; i++)
			{
				printf("2 ");
			}
			puts("");
		}
	}
	else
	{
		printf("%d\n", n / 2);
		for (int i = 0; i < n / 2; i++)
		{
			printf("2 ");
		}
		puts("");
	}
	return 0;
}

