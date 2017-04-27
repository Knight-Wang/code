// poj1862.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int a[105], n;

bool cmp(const int & a, const int & b)
{
	return a > b;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n, cmp);
	double res = a[0];
	for (int i = 0; i < n - 1; i++)
	{
		res = 2.0 * sqrt(res * a[i + 1]);
	}
	printf("%.3f\n", res);
	//system("pause");
	return 0;
}

