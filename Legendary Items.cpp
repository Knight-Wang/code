// Legendary Items.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

int p, q, n;

double get_item(int i)
{
	int pi = i < 7 ? p / (1 << i) : 0;
	double tmp = 1;
	double E = 0;
	for (int j = 0; j <= 100; j++)
	{
		E += tmp * (j + 1) * pi * 0.01;
		if (pi == 100)
			return E;
		tmp *= 1 - pi * 0.01;
		pi += q;
		if (pi >= 100)
		{
			pi = 100;
		}
	}
	return E;
}

int main()
{
	double ans = 0;
	cin >> p >> q >> n;
	for (int i = 0; i < n; i++)
	{
		ans += get_item(i);
	}
	printf("%.2lf\n", ans);
	//system("pause");
	return 0;
}

