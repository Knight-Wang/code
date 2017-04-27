// 爬楼梯.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

const int mod = 10007;
int x[25];
int main()
{
	x[1] = 1; x[2] = 2; x[3] = 4;
	for (int i = 4; i <= 20; i++)
	{
		x[i] = x[i - 1] + x[i - 2] + x[i - 3];
	}
	int t, n, tmp;
	cin >> t;
	while (t--)
	{
		scanf("%d", &n);
		int res = 1;
		for (int i = 0; i < n - 1; i++)
		{
			scanf("%d", &tmp);
			res = res * x[tmp] % mod;
		}
		printf("%d\n", res);
	}
	//system("pause");
	return 0;
}

