// 神奇算式.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int num1[10], num2[10];

bool check(int x, int y, int z)
{
	while (x)
	{
		num1[x % 10]++;
		x /= 10;
	}
	while (y)
	{
		num1[y % 10]++;
		y /= 10;
	}
	while (z)
	{
		num2[z % 10]++;
		z /= 10;
	}
	bool flag = true;
	for (int i = 0; i <= 9; i++)
	{
		if (num1[i] != num2[i] || num1[i] > 1)
		{
			flag = false;
			break;
		}
	}
	return flag;
}

int main()
{
	int cnt = 0;
	for (int i = 1; i <= 999; i++)
	{
		for (int j = i; j <= 999; j++)
		{
			memset(num1, 0, sizeof(num1));
			memset(num2, 0, sizeof(num2));
			int x = i * j;
			if (x >= 1000 && x <= 9999 && check(i, j, x))
			{
				cnt++;
				cout << i << " " << j << " " << x << endl;
			}
		}
	}
	cout << cnt << endl;
	system("pause");
	return 0;
}

