// poj3187.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, a[10], buf[10];

bool check()
{
	for (int i = 0; i < n; i++)
	{
		buf[i] = a[i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
			buf[j] += buf[j + 1];
	}
	return buf[0] == m;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		a[i - 1] = i;
	}
	do
	{
		if (check())
			break;
	} while (next_permutation(a, a + n));
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	puts("");
	//system("pause");
	return 0;
}

